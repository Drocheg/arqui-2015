#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

#define SYSREAD 1
#define SYSWRITE 2

uint32_t read(uint8_t fd, char *buff, uint32_t maxBytes);

uint32_t write(uint8_t fd, char *buff, uint32_t maxBytes);

#endif