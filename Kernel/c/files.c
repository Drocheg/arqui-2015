#include <stdint.h>
#include "files.h"
#include <video.h>

uint64_t fwrite(uint64_t fd, char *buffer, uint64_t maxBytes) {
	int result = -1;
	if(fd < MIN_FD || fd > MAX_FD) return -1;

	switch(fd) {
		case STDOUT:
			result = 0;
			int i;
			for(i = 0; buffer[i] != 0 && i < bytes; i++) {
				ncPrintChar(buffer[i]);
				result++;
			}
			break;
		case STDERR:
			result = 0;
			int i;
			for(i = 0; buffer[i] != 0 && i < bytes; i++) {
				ncPrintColorChar(buffer[i], (char) 0x04);
				result++;
			}
			break;
		case KEYBOARD:
			ncPrint("Keyboard not implemented yet.");
			break;
		case SPEAKER:
			ncPrint("Speaker not implemented yet.");
			break;
	}
	return result;
}