#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

void IRQ_handler(int irq);

void keyboardInt();

void sayHello();

#endif