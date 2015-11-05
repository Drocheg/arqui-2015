#include <syscalls.h>
#include <interrupts.h>

uint32_t read(uint8_t fd, char *buff, uint32_t maxBytes) {
	return _int80(1, (uint32_t)fd, (uint32_t)buff, maxBytes);
}

uint32_t write(uint8_t fd, char *buff, uint32_t maxBytes) {
	return _int80(2, (uint32_t)fd, (uint32_t)buff, maxBytes);
}