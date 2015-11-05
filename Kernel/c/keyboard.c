#include <keyboard.h>
#include <libasm.h>

uint8_t keyboardBuffer[KEYBOARD_BUFF_SIZE] = {0};
int keyboardBufferIndex = -1;

uint8_t bufferIsEmpty() {
	return keyboardBufferIndex < 0;
}

uint8_t bufferIsFull() {
	return keyboardBufferIndex >= KEYBOARD_BUFF_SIZE-1;
}

int8_t pop() {
	if(bufferIsEmpty()) return -1;
	uint8_t result = keyboardBuffer[keyboardBufferIndex--];
	return result;
}

int8_t push(uint8_t data) {
	if(bufferIsFull()) return -1;
	keyboardBuffer[++keyboardBufferIndex] = data;
	return 1;
}

//TODO see http://wiki.osdev.org/PS/2_Keyboard#Scan_Code_Sets.2C_Scan_Codes_and_Key_Codes SCAN CODE SET 1
char getCharFromScanCode(uint8_t scanCode) {
	return 0;
}