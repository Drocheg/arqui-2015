#ifndef FILES_H
#define FILES_H

#include <stdint.h>
#include <commonDefs.h>

uint64_t fwrite(uint64_t fd, char *buffer, uint64_t maxBytes);

uint64_t fread(uint64_t fd, char *buffer, uint64_t maxBytes);

#endif