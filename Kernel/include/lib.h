#ifndef LIB_H
#define LIB_H

#include <stdint.h>

void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);
char *cpuVendor(char *result);

int64_t sys_read(uint8_t fd, char *buff, uint32_t maxBytes);
int64_t sys_write(uint8_t fd, char *buff, uint32_t maxBytes);

#endif