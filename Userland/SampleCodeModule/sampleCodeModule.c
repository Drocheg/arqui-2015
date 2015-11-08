#include <stdint.h>

extern char bss;
extern char endOfBinary;

static int bssCheck = 0;

void * memset(void * destiny, int32_t c, uint64_t length);

int32_t main() {
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);
	

	if(bssCheck != 0) {	//Improper BSS setup
		return -1;
	}
	char *video = (char *)0xB8000;
	for(int i = 1; i < (80*25*2)-1; i += 2) {
		video[i] = (char)i;
	}
	video = video + (80*2*12) + (30*2);
	char *message = "TASTE THE RAINBOWWWW";
	for(int i = 0; message[i] != 0; i++) {
		video[i] = message[i];
		video++;
	}

	return 0;
}

void * memset(void * dest, int32_t c, uint64_t length) {
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)dest;

	while(length--)
		dst[length] = chr;

	return dest;
}
