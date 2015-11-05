#include <keyboard.h>
#include <ports.h>

char keyboardBuffer[256] = {0};
int keyboardBufferIndex = 0;

uint64_t bufferIsEmpty() {
	return keyboardBufferIndex <= 0;
}

uint64_t bufferIsFull() {
	return keyboardBufferIndex >= 256;
}

//TODO change types, they are only 8 bits long
uint64_t getPressedKey() {
	if(bufferIsEmpty()) return 0;
	uint64_t result = keyboardBuffer[keyboardBufferIndex--];
	return result;
}