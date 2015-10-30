#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

uint64_t bufferIsEmpty();

uint64_t bufferIsFull();

uint64_t getPressedKey();

#endif