#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>
#define SYSWRITE 1
#define SYSREAD 2
#define SYSEXIT 3
#define DO_AWESOME_SHIT 42

uint64_t sysCall(uint64_t id, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4);

#endif