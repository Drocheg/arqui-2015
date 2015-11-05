#ifndef INTERRUPTHANDLERS_H
#define INTERRUPTHANDLERS_H

#include <stdint.h>

void IRQ_handler(uint8_t irq);

uint32_t int80Handler(uint32_t syscallID, uint32_t p1, uint32_t p2, uint32_t p3);

#endif