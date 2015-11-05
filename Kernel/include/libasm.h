#ifndef LIBASM_H
#define LIBASM_H

#include <stdint.h>

void _sidt(uint64_t *dest);

void _cli();

void _sti();

void _halt();

#endif