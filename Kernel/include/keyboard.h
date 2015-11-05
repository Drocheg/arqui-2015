#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

#define KEYBOARD_BUFF_SIZE 256

uint8_t bufferIsEmpty();

uint8_t bufferIsFull();

int8_t pop();

int8_t push(uint8_t data);

char getCharFromScanCode(uint8_t scanCode);

#endif