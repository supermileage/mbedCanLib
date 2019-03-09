#include "CanButton.h"

CanButton::CanButton(PinName pin, unsigned canID_) : CanItem(canID_), button(pin, PullDown), on(false) {}

void CanButton::poll() {
    bool readPin = button.read();
    if(!on && readPin) {
        debounceDelay();
        if(button.read()) { // Debounce
            toggleButton();
        }
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

// Mbed wait doesnt work while debugging
void CanButton::debounceDelay() {
    Timer timer;
    timer.start();
    while (timer.read_ms() < 100) { } // delays by 100ms
}

