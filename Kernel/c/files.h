#ifndef FILES_H
#define FILES_H

#define STDOUT 1
#define STDERR 2
#define KEYBOARD 3
#define MIN_FD STDOUT
#define MAX_FD KEYBOARD

uint64_t fwrite(uint64_t fd, char *buffer, uint64_t maxBytes);

#endif