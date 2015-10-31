#ifndef PIC_H
#define PIC_H

#include <stdint.h>

void masterPICmask(uint8_t mask);

void slavePICmask(uint8_t mask);

#endif