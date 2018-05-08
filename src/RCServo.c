#include <stdio.h>
#include <stdlib.h>

#include <phidget22.h>
#include "PhidgetHelperFunctions.h"


static void CCONV onAttachHandler(PhidgetHandle ph, void *ctx) {
	PhidgetReturnCode prc;
	int channel;
	int serialNumber;

	prc = Phidget_getDeviceSerialNumber(ph, &serialNumber);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to get device serial number\n");
        DisplayError(prc);
		return;
	}

	prc = Phidget_getChannel(ph, &channel);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to get channel number\n");
        DisplayError(prc);
		return;
	}

	printf("\n[Attach Event]:\n\t-> Serial Number: %d\n\t-> Channel %d\n\n", serialNumber, channel);
}

static void CCONV onDetachHandler(PhidgetHandle ph, void *ctx) {
	PhidgetReturnCode prc;
	int channel;
	int serialNumber;

	prc = Phidget_getDeviceSerialNumber(ph, &serialNumber);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to get device serialNumber number\n");
        DisplayError(prc);
		return;
	}

	prc = Phidget_getChannel(ph, &channel);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to get channel number\n");
        DisplayError(prc);
		return;
	}

	printf("\n[Detach Event]:\n\t-> Serial Number: %d\n\t-> Channel %d\n\n", serialNumber, channel);
}

static void CCONV errorHandler(PhidgetHandle phid, void *ctx, Phidget_ErrorEventCode errorCode,
							   const char *errorString) {
	fprintf(stderr, "[Phidget Error Event] -> %s (%d)\n", errorString, errorCode);
}

static void CCONV onPositionChangeHandler(PhidgetRCServoHandle ch, void *ctx, double position) {
    // empty because it fired events very often and filled the terminal
}

static void CCONV onVelocityChangeHandler(PhidgetRCServoHandle ch, void *ctx, double velocity) {
	printf("Velocity Changed: %.3g\n", velocity);
}

static void CCONV onTargetPositionReachedHandler(PhidgetRCServoHandle ch, void *ctx, double position) {
	printf("Target Position Reached: %.3g\n", position);
}


/**
 * Sets an initial thrust level for the motor and turns it on.
 * Continuous rotation RCServo motors wont start before they're set to engaged.
 */
int setEngaged(PhidgetRCServoHandle *ph, int engagedStatus, double initialSpeed) {
	PhidgetReturnCode prc;

	if (initialSpeed > 180 || initialSpeed < 0) {
		printf("RCServo -> illegal initial speed");
		return 1;
	}

	prc = PhidgetRCServo_setTargetPosition(*ph, initialSpeed);
	if (prc !=  EPHIDGET_OK) {
		printf("failed to set target position in setEngaged");
		return 1;
	}

	prc = PhidgetRCServo_setEngaged(*ph, engagedStatus);
	if (prc != EPHIDGET_OK) {
		printf("RCServo failed to set engaged\n");
		DisplayError(prc);
		return 1;
	}
	return 0;
}


int createRCServoConnection(PhidgetRCServoHandle *ph, const int *motorSerialNumber, const int *motorChannel) {
	PhidgetReturnCode prc;

    printf("Running createRCServoConnection..\n");

	// Allocate a new Phidget Channel object
	prc = PhidgetRCServo_create(ph);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to create rc servo channel\n");
		return 1;
	}


	// Set matching parameters to specify which channel to open
	if (SetSerialNumber((PhidgetHandle *)ph, motorSerialNumber))
		goto error;

	if(SetChannel((PhidgetHandle *)ph, motorChannel))
		goto error;


	// Add event handlers before calling open so that no events are missed
	if (SetAttachDetachError_Handlers((PhidgetHandle*)ph, onAttachHandler, onDetachHandler, errorHandler))
		goto error;

	prc = PhidgetRCServo_setOnPositionChangeHandler(*ph, onPositionChangeHandler, NULL);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to set position change handler: \n");
		DisplayError(prc);
		goto error;
	}

	prc = PhidgetRCServo_setOnVelocityChangeHandler(*ph, onVelocityChangeHandler, NULL);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to set velocity change handler: \n");
		DisplayError(prc);
		goto error;
	}

	prc = PhidgetRCServo_setOnTargetPositionReachedHandler(*ph, onTargetPositionReachedHandler, NULL);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "failed to set target position reached handler: \n");
		DisplayError(prc);
		goto error;
	}


	// Open the channel with a timeout
	if (OpenPhidgetChannel_waitForAttach((PhidgetHandle *)ph, 5000)) {
        fprintf(stderr, "failed to attach to RCServo channel\n");
        goto error;
    }


	// If no errors
    printf("RCServo connection at address %p established\n", ph);
	return 0;


error:
	Phidget_close((PhidgetHandle)*ph);
	PhidgetRCServo_delete(ph);
	return 1;
}

void closeRCServoConnection(PhidgetRCServoHandle *ph) {
	PhidgetRCServo_setEngaged(*ph, 0);
	Phidget_close((PhidgetHandle)*ph);
	PhidgetRCServo_delete(ph);
	Phidget_release((PhidgetHandle*) ph);
}