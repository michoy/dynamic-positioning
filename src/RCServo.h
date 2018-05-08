#include <phidget22.h>

#ifndef DATAMETODER_RCSERVO_H
#define DATAMETODER_RCSERVO_H

/**
 * Creates, configures, and opens a VoltageInput channel.
 *
 * @param ph
 * @param motorSerialNumber
 * @param motorChannel
 * @return 0 if the program exits successfully, 1 if it exits with errors.
 */
int createRCServoConnection(PhidgetRCServoHandle *ph, const int *motorSerialNumber, const int *motorChannel);

/**
 * Disengages servo, closes the channel and releases the pointer
 *
 * @param ph The channel of the RCServo
 */
void closeRCServoConnection(PhidgetRCServoHandle *ph);

/**
 * Sets an initial thrust level for the motor and turns it on.
 *
 * @param ph
 * @param engagedStatus
 * @param initialSpeed
 * @return 0 if the program exits successfully, 1 if it exits with errors.
 */
int setEngaged(PhidgetRCServoHandle *ph, int engagedStatus, double initialSpeed);

#endif //DATAMETODER_RCSERVO_H
