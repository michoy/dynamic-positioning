#include <stdio.h>

#include <phidget22.h>
#include "PhidgetHelperFunctions.h"


void DisplayError(PhidgetReturnCode returnCode) {
	PhidgetReturnCode prc;
	const char* error;

	prc = Phidget_getErrorDescription(returnCode, &error);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Getting ErrorDescription: \n\t");
		DisplayError(prc);
		return;
	}

	fprintf(stderr, "Desc: %s\n", error);
}

int SetSerialNumber(PhidgetHandle *ph, const int *deviceSerialNumber) {
	PhidgetReturnCode prc;

	prc = Phidget_setDeviceSerialNumber(*ph, *deviceSerialNumber);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Setting DeviceSerialNumber: \n\t");
		DisplayError(prc);
		return 1;
	}
	return 0;
}

int SetChannel(PhidgetHandle *ph, const int *channel) {
	PhidgetReturnCode prc;

	prc = Phidget_setChannel(*ph, *channel);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Setting Channel: \n\t");
		DisplayError(prc);
		return 1;
	}

	return 0;
}

int SetAttachDetachError_Handlers(
		PhidgetHandle *ph,
		Phidget_OnAttachCallback onAttachCallback,
		Phidget_OnDetachCallback onDetachCallback,
		Phidget_OnErrorCallback onErrorCallback) {
	PhidgetReturnCode prc;

	prc = Phidget_setOnAttachHandler(*ph, onAttachCallback, NULL);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Set Attach Handler: \n\t");
		DisplayError(prc);
		return 1;
	}

	prc = Phidget_setOnDetachHandler(*ph, onDetachCallback, NULL);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Set Detach Handler: \n\t");
		DisplayError(prc);
		return 1;
	}

	prc = Phidget_setOnErrorHandler(*ph, onErrorCallback, NULL);
	if (EPHIDGET_OK != prc) {
		fprintf(stderr, "Runtime Error -> Set Error Handler: \n\t");
		DisplayError(prc);
		return 1;
	}

	return 0;
}

int OpenPhidgetChannel_waitForAttach(PhidgetHandle *ph, uint32_t timeout_in_ms) {
	PhidgetReturnCode prc;
	const char *errs;

	printf("Opening Channel...\n");
	prc = Phidget_openWaitForAttachment(*ph, timeout_in_ms);
	if (prc != EPHIDGET_OK) {
		if (prc == EPHIDGET_TIMEOUT) {
			fprintf(stderr,
					"Channel did not attach after %d seconds: please check that the device is attached\n",
					timeout_in_ms);
			DisplayError(prc);
		} else {
			Phidget_getErrorDescription(prc, &errs);
			fprintf(stderr, "failed to open channel:%s\n", errs);
		}
		return 1;
	}

	return 0;
}

int ClosePhidgetChannel(PhidgetHandle *ph) {
	PhidgetReturnCode prc;

	printf("Closing Channel...\n");
	prc = Phidget_close(*ph);
	if (prc != EPHIDGET_OK) {
		fprintf(stderr, "Runtime Error -> Closing Phidget Channel: \n\t");
		DisplayError(prc);
		return 1;
	}
	return 0;
}
