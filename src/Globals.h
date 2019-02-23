#include "../../mbed.h"

#ifndef GLOBALS_H
#define GLOBALS_H

// extern CAN can(p30, p29); // Actual pins
extern CAN can(p9, p10); // Use for testing (current wiring)
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing