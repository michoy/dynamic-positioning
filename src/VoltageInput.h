#include <phidget22.h>

#ifndef DATAMETODER_VOLTAGEINPUT_H
#define DATAMETODER_VOLTAGEINPUT_H

/**
 * Creates, configures, and opens a VoltageInput channel.
 *
 * @param ph The channel the voltageInput will be attached to
 * @param deviceSerialNumber Serial number of voltageInput device
 * @param channel Channel of voltageInput device
 * @return 0 if the program exits successfully, 1 if it exits with errors.
 */
int createVoltageInputConnection(PhidgetVoltageInputHandle *ph, const int *deviceSerialNumber, const int *channel);

/**
 * Closes the VoltageInput channel and releases the pointer
 *
 * @param ph The channel of the voltageInput
 */
void closeVoltageInputConnection(PhidgetVoltageInputHandle* ph);

#endif //DATAMETODER_VOLTAGEINPUT_H
