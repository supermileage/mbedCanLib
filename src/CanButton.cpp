#include "CanButton.h"

CanButton::CanButton(PinName pin, unsigned canID_) : CanItem(canID_), button(pin, PullDown), on(false) {}

void CanButton::poll() {
    bool readPin = button.read();
    if(!on && readPin) {
        toggleButton();
    } else if(on && !readPin) {
        toggleButton();
    }
}

void CanButton::toggleButton() {
    on = !on;
    if(on) {
        sendMessage("1");
    } else {
        sendMessage("0");
    }
}


