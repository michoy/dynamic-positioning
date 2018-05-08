#include <stdio.h>
#include <stdlib.h>

#include <phidget22.h>
#include "PhidgetHelperFunctions.h"


/**
* Configures the device's DataInterval and ChangeTrigger.
* Datainterval is set to 50 ms.
* Displays info about the attached phidget channel.
* Fired when a Phidget channel with onAttachHandler registered attaches
*
* @param ph The Phidget channel that fired the attach event
* @param *ctx Context pointer
*/
static void CCONV onAttachHandler(PhidgetHandle ph, void *ctx) {
	PhidgetReturnCode prc;
	int32_t serialNumber;
	int32_t channel;

	/*
	*	Set the DataInterval inside of the attach handler to initialize the device with this value.
	*	DataInterval defines the minimum time between VoltageChange events.
	*	DataInterval can be set to any value from MinDataInterval to MaxDataInterval.
	*/
	prc = PhidgetVoltageInput_setDataInterval((PhidgetVoltageInputHandle)ph, 50);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Set DataInterval: \n\t");
		DisplayError(prc);
		return;
	}

	/*
	*	Set the VoltageChangeTrigger inside of the attach handler to initialize the device with this value.
	*	VoltageChangeTrigger will affect the frequency of VoltageChange events, by limiting them to only occur when
	*	the voltage changes by at least the value set.
	*/
	prc = PhidgetVoltageInput_setVoltageChangeTrigger((PhidgetVoltageInputHandle)ph, 0.0);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Set VoltageChangeTrigger: \n\t");
		DisplayError(prc);
		return;
	}

	prc = Phidget_getDeviceSerialNumber(ph, &serialNumber);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Get DeviceSerialNumber: \n\t");
		DisplayError(prc);
		return;
	}

	prc = Phidget_getChannel(ph, &channel);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Get Channel: \n\t");
		DisplayError(prc);
		return;
	}

	printf("\n[Attach Event]:\n\t-> Serial Number: %d\n\t-> Channel %d\n\n", serialNumber, channel);
}

static void CCONV onDetachHandler(PhidgetHandle ph, void *ctx) {
	PhidgetReturnCode prc;
	int serialNumber;
	int channel;

	prc = Phidget_getDeviceSerialNumber(ph, &serialNumber);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Get DeviceSerialNumber: \n\t");
		DisplayError(prc);
		return;
	}

	prc = Phidget_getChannel(ph, &channel);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Get Channel: \n\t");
		DisplayError(prc);
		return;
	}

	printf("\n[Detach Event]:\n\t-> Serial Number: %d\n\t-> Channel %d\n\n", serialNumber, channel);
}

static void CCONV onErrorHandler(PhidgetHandle phid, void *ctx, Phidget_ErrorEventCode errorCode,
                                 const char *errorString) {
	fprintf(stderr, "[Phidget Error Event] -> %s (%d)\n", errorString, errorCode);
}

static void CCONV onVoltageChangeHandler(PhidgetVoltageInputHandle ph, void *ctx, double voltage) {
    // empty because it fired events very often and filled the terminal
}

static int CreateVoltageInput(PhidgetVoltageInputHandle *ph) {
	PhidgetReturnCode prc;

	prc = PhidgetVoltageInput_create(ph);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Creating VoltageInput: \n\t");
		DisplayError(prc);
		return 1;
	}
	return 0;
}

static int SetVoltageHandler(PhidgetVoltageInputHandle ph, PhidgetVoltageInput_OnVoltageChangeCallback fptr) {
	PhidgetReturnCode prc;

	prc = PhidgetVoltageInput_setOnVoltageChangeHandler(ph, fptr, NULL);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Setting VoltageChangeHandler: \n\t");
		DisplayError(prc);
		return 1;
	}
	return 0;
}


int createVoltageInputConnection(PhidgetVoltageInputHandle *ph, const int *deviceSerialNumber, const int *channel) {

	// Allocate a new Phidget Channel object
	if (CreateVoltageInput(ph))
		goto error;


	// Set matching parameters to specify which channel to open
	if (SetSerialNumber((PhidgetHandle*)ph, deviceSerialNumber))
		goto error;

	if (SetChannel((PhidgetHandle*)ph, channel))
		goto error;


	// Add event handlers before calling open so that no events are missed.
	if (SetAttachDetachError_Handlers((PhidgetHandle*)ph, onAttachHandler, onDetachHandler, onErrorHandler))
		goto error;

	if (SetVoltageHandler(*ph, onVoltageChangeHandler))
		goto error;


	// Open the channel with a timeout
	if (OpenPhidgetChannel_waitForAttach((PhidgetHandle *)ph, 5000))
		goto error;


	printf("VoltageInput connection at address %p established\n", ph);
	return 0;


error:
	Phidget_close((PhidgetHandle)*ph);
	PhidgetVoltageInput_delete(ph);
	return 1;
}

void closeVoltageInputConnection(PhidgetVoltageInputHandle *ph) {
    ClosePhidgetChannel((PhidgetHandle *)ph);
	PhidgetVoltageInput_delete(ph);
	Phidget_release((PhidgetHandle *) ph);
}
