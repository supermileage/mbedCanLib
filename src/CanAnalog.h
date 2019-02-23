#include "../../mbed.h"
#include "CanItem.h"

#ifndef CANANALOG_H
#define CANANALOG_H 

class CanAnalog : private CanItem {
    public:
        CanAnalog(PinName pin, unsigned canID_);
        void poll();
        float read();
    private:
        AnalogIn analog;
};

#endif 