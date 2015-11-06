#include <keyboard.h>
#include <libasm.h>

static uint8_t queue[KEYBOARD_BUFF_SIZE] = {0};
static int readIndex = -1, writeIndex = 0;

//TODO consider cases when one index is around the border from the other (i.e. 0 vs 255)
uint8_t bufferIsEmpty() {
	return readIndex == writeIndex-1;
}

uint8_t bufferIsFull() {
	return readIndex == writeIndex;
}

uint8_t pollKey() {
	if(bufferIsEmpty()) return 0;
	if(++readIndex >= KEYBOARD_BUFF_SIZE) {
		readIndex == 0;
	}
	return queue[readIndex];
}

uint8_t offerKey(uint8_t data) {
	if(bufferIsFull()) {
		ncPrint("Keyboard buffer full.");	//TODO delete
		return 0;
	}
	if(writeIndex == KEYBOARD_BUFF_SIZE) {
		writeIndex = 0;
	}
	queue[writeIndex++] = data;
	return 1;
}

//TODO see http://wiki.osdev.org/PS/2_Keyboard#Scan_Code_Sets.2C_Scan_Codes_and_Key_Codes SCAN CODE SET 1
char getCharFromScanCode(uint8_t scanCode) {
	return 0;
}