#include <phidget22.h>

#ifndef PHIDGET_HELPER_FUNCTIONS_H
#define PHIDGET_HELPER_FUNCTIONS_H


/**
* Displays the error string associated to the PhidgetReturnCode from a phidget function call
*
* @param returnCode The PhidgetReturnCode to get the error string of
*/
void DisplayError(PhidgetReturnCode returnCode);


/**
* Sets the DeviceSerialNumber of the Phidget channel
*
* @param ph The Phidget channel to set
 * @param deviceSerialNumber Serial number of device being registered
* @return 0 if the operation succeeds, 1 if it fails
*/
int SetSerialNumber(PhidgetHandle *ph, const int *deviceSerialNumber);


/**
* Sets the Channel value of the Phidget channel
*
* @param ph The Phidget channel to set
 * @param channel Id for device being registered
* @return 0 if the operation succeeds, 1 if it fails
*/
int SetChannel(PhidgetHandle *ph, const int *channel);


/**
* Sets the event handlers for Phidget Attach, Phidget Detach, Phidget Error events
*
* @param ph The Phidget channel to add event handlers to
 * @param onAttachCallback Fired when a Phidget channel with onAttachHandler registered attaches
 * @param onDetachCallback Fired when a Phidget channel with onDetachHandler registered detaches
 * @param onErrorCallback Fired when a Phidget channel with onErrorHandler registered encounters an error
* @return 0 if the operation succeeds, 1 if it fails
*/
int SetAttachDetachError_Handlers(
        PhidgetHandle *ph,
        Phidget_OnAttachCallback onAttachCallback,
        Phidget_OnDetachCallback onDetachCallback,
        Phidget_OnErrorCallback onErrorCallback);


/**
* Opens the phidget channel synchronously. This function will block for a duration of timeout_in_ms.
*
* @param ph The Phidget channel to be opened
* @param timeout_in_ms The number of milliseconds to wait for attach.
* @return 0 if the operation succeeds, 1 if it fails or times out
*/
int OpenPhidgetChannel_waitForAttach(PhidgetHandle *ph, uint32_t timeout_in_ms);


/**
* Closes the phidget channel, releasing control of the object.
*
* @param ph The Phidget channel to be closed
* @return 0 if the operation succeeds, 1 if it fails
*/
int ClosePhidgetChannel(PhidgetHandle *ph);

#endif