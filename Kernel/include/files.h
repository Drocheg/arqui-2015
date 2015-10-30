#ifndef FILES_H
#define FILES_H

#include <stdint.h>

#define STDOUT 1
#define STDIN 2
#define STDERR 3
#define KEYBOARD 4
#define SPEAKER 5
#define MIN_FD 1
#define MAX_FD 5

uint64_t fwrite(uint64_t fd, char *buffer, uint64_t maxBytes);

uint64_t fread(uint64_t fd, char *buffer, uint64_t maxBytes);

#endif