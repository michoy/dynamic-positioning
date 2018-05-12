#include <stdio.h>
#include <stdlib.h>
#include <phidget22.h>
#include <string.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <time.h>
#include <errno.h>
#endif

#include "VoltageInput.h"
#include "RCServo.h"
#include "PhidgetHelperFunctions.h"
#include "animate.h"


// Config variables
static double positionWanted = 40.0;    // between 0 and reachableLength (cm)
static double reachableLength = 67.0;   // length boat can move in basin (cm)
static double iterationTime = 0.05;     // in seconds
static double maxTime = 10.0;           // time until control loop exits
static double bias = 90;                // thrust level that keeps boat approximately stationary

static double Kp = 2.9;
static double Ki = 1.5;
static double Kd = 0.004;

const int motorSerialNumber = 42685;
const int motorChannel = 0;
const int voltageSerialNumber = 76241;
const int voltageChannel = 2;


static void sleep_ms(int milliseconds) {
#ifdef WIN32
    Sleep((DWORD) milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}


/**
 * Sets thrust of the boats propeller
 *
 * For Continuous Rotation Servos, position is used to set speed.
 * Position by default is between 0 and 180, but this particular motor enters full-throttle reverse below 66
 * and is unreliable above 160
 */
int setMotorThrust(PhidgetRCServoHandle *motorHandle, double thrust) {

    PhidgetReturnCode prc;

    if (thrust >= 160)      // highest possible thrust for motor
        thrust = 160;
    else if (thrust < 66)   // motor enters reverse below 66
        thrust = 66;


    prc = PhidgetRCServo_setTargetPosition(*motorHandle, thrust);
    if (prc != EPHIDGET_OK) {
        fprintf(stderr, "Failed setting motor speed\n");
        DisplayError(prc);
        return 1;
    } else
        return 0;

}


/**
 * Finds max and min voltage. This will be used to find the boats position.
 * The voltage is lower the further in front the boat is.
 */
void getVoltageInputInterval(PhidgetVoltageInputHandle *voltageHandle, PhidgetRCServoHandle *motorHandle,
                             double *minVoltage, double *maxVoltage) {

    // Measure voltage when boat is in the back of the basin
    PhidgetVoltageInput_getVoltage(*voltageHandle, maxVoltage);

    // Let boat drive to front of basin and measure voltage there
    setMotorThrust(motorHandle, 110);
    sleep_ms(5000);
    PhidgetVoltageInput_getVoltage(*voltageHandle, minVoltage);

    // Let boat calmly reset to its starting position
    setMotorThrust(motorHandle, 85);
    sleep_ms(5000);

    printf("maxVoltage -> %.4f\nminVoltage -> %.4f\n\n", *maxVoltage, *minVoltage);
}


/**
 * calculates boat position in basin from the potentiometers voltage.
 * The function depends on minVoltage, maxVoltage and reachableLength to produce correct output.
 */
double getPosition(PhidgetVoltageInputHandle *voltageHandle, const double *minVoltage, const double *maxVoltage,
                   double *voltage) {

    PhidgetVoltageInput_getVoltage(*voltageHandle, voltage);

    return reachableLength - (*voltage - *minVoltage) * reachableLength / (*maxVoltage - *minVoltage);
}


/**
 * Logging was put into it's own function because fprintf strangely did not work in the main loop
 */
static void addToLog(FILE *f, const double *totalTime, const double *currentPosition, const double *thrust) {
    fprintf(f, "%f %f %f\n", *totalTime, *currentPosition, *thrust);
}


int main (int argc, char **argv) {

    // Setup channel for position input
    PhidgetVoltageInputHandle voltageHandle;
    if (createVoltageInputConnection(&voltageHandle, &voltageSerialNumber, &voltageChannel)) {
        fprintf(stderr, "Couldn't establish connection to voltageInput, application terminating..");
        return 1;
    }


    // Setup RCServo channel and engage
    PhidgetRCServoHandle motorHandle;
    if (createRCServoConnection(&motorHandle, &motorSerialNumber, &motorChannel)) {
        fprintf(stderr, "Couldn't establish connection to RCServo, application terminating..");
        return 1;
    }
    setEngaged(&motorHandle, 1, 90);


    // Find voltageInput interval
    double maxVoltage,minVoltage;
    getVoltageInputInterval(&voltageHandle, &motorHandle, &minVoltage, &maxVoltage);


    // Setup for logging to files
    FILE *f;
    f = fopen("../logs/log.dat", "w");
    if (f == NULL)  fprintf(stderr, "can't open log.dat\n");


    // Setup for control loop
    double currentPosition = 0.0;
    double voltage;

    double error = 0.0;
    double errorPrior = 0.0;

    double integral = 0.0;
    double derivative = 0.0;

    double thrust = 0.0;
    double totalTime = 0.0;


    // Control loop
    printf("Control loop running.. \n");
    while (totalTime < maxTime) {

        // Update current position
        currentPosition = getPosition(&voltageHandle, &minVoltage, &maxVoltage, &voltage);

        // Calculate new values for thrust
        error = positionWanted - currentPosition;
        derivative = (error - errorPrior) / iterationTime;
        if (Kp*error + Kd*derivative < 40)   // measure against integral windup
            integral = integral + (error * iterationTime);

        // Set motor thrust and update variables
        thrust = bias + Kp * error + Ki * integral + Kd * derivative;
        setMotorThrust(&motorHandle, thrust);
        totalTime += iterationTime;

        // Log results
        printf("error: %f\n", error);
        if (f != NULL)
            addToLog(f, &totalTime, &currentPosition, &thrust);

        // Delay before next calculation
        sleep_ms((int)(iterationTime*1000));
    }

    // Close channels and fileIO
    printf("\nTime limit reached\n");
    printf("Closing channels and io\n");
    closeRCServoConnection(&motorHandle);
    closeVoltageInputConnection(&voltageHandle);
    fclose(f);

    // Start animation
    animate(argc, argv);
    return 0;
}