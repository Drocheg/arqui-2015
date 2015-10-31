#include <pic.h>
#include <ports.h>

void masterPICmask(uint8_t mask) {
	portWrite(0x21, (uint64_t)mask);
}

void slavePICmask(uint8_t mask) {
	portWrite(0xA1, (uint64_t)mask);
}