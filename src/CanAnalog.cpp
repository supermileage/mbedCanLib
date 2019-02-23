#include "CanAnalog.h"

CanAnalog::CanAnalog(PinName pin, unsigned canID_) : CanItem(canID_), analog(pin) {}

void CanAnalog::poll() {
    float dataAsFloat = read(); // Between 0 and 1
    char data[12]; 
    sprintf(data, "%.3f", dataAsFloat);
    sendMessage(data);
}

float CanAnalog::read() {
    return analog.read(); // Between 0 and 1
}

