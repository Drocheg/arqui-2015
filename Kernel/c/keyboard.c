#include <keyboard.h>
#include <ports.h>



uint64_t isNewKeyPressed() {
	uint64_t static lastKey=0;
	if(!portRead(0x60)) return 0;//See http://stanislavs.org/helppc/8042.html (also what would I return if no key is pressed?!)
	uint64_t result = portRead(0x64);
	if(result==lastKey) return 0;
	lastKey=result;
	return result;
}

uint64_t getPressedKey() {
	if(!portRead(0x60)) return 0;	
	uint64_t result = portRead(0x60);
	return result;
}