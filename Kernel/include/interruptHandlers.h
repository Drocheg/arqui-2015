#ifndef INTERRUPTHANDLERS_H
#define INTERRUPTHANDLERS_H

#include <stdint.h>

void intHandler(uint8_t id);

void IRQ_handler(uint8_t irq);

#endif