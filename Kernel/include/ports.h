#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>

uint64_t portRead(uint64_t portNumber);
void portWrite(uint64_t port, uint64_t data);

#endif