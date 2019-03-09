#include "CanItem.h"

#include <iostream> // TODO: remove

extern CAN can;

CanItem::CanItem(unsigned canID_) : canID(canID_){}

void CanItem::sendMessage(const char* data) {
    cout << "SendingID: " << canID << endl;
    can.write(CANMessage(canID,data,8));
}
