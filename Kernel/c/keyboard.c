#include <keyboard.h>
#include <libasm.h>
#include <stdlib.h>
#include <scanCodes.h>

static uint8_t queue[KEYBOARD_BUFF_SIZE] = {0};
static uint8_t readIndex = -1, writeIndex = 0;
static uint8_t caps = 0, ctrl = 0, alt = 0;

uint8_t processModifierKey(uint8_t scanCode);
char processScanCode(uint8_t scanCode);

uint8_t bufferIsEmpty() {
	return readIndex == writeIndex-1 || (readIndex == KEYBOARD_BUFF_SIZE-1 && writeIndex == 0);
}

uint8_t bufferIsFull() {
	return readIndex == writeIndex;
}

uint8_t pollRawKey() {
	if(bufferIsEmpty()) return 0;
	if(++readIndex >= KEYBOARD_BUFF_SIZE) {
		readIndex = 0;
	}
	return queue[readIndex];
}

uint8_t pollProcessedKey() {
	uint8_t raw = pollRawKey();
	if(raw == 0) return 0;
	return processScanCode(raw);
}

//TODO verificar que no se rompa en casos límite

uint8_t offerKey(uint8_t scanCode) {
	processModifierKey(scanCode);
	if(bufferIsFull()) {
		return 0;
	}
	queue[writeIndex++] = scanCode;
	if(writeIndex == KEYBOARD_BUFF_SIZE) {
		writeIndex = 0;
	}
	return 1;
}

//TODO sort number asciis better? Or just ignore them altogether
char processScanCode(uint8_t scanCode) {
	if(scanCode >= 256) {
		return 0;
	}
	char ascii = decodeScanCode(scanCode);
	if(isAlpha(ascii)) {
		return (caps ? toUpperChar(ascii) : ascii);
	}
	if(isNumber(ascii)) {
		if(!caps) return ascii;
		switch(ascii) {
			case '0':
				return ')';
				break;
			case '2':
				return '@';
				break;
			case '6':
				return '^';
				break;
			default:
				return ascii > '6' ? ascii-17 : ascii-16;
				break;

		}
	}
	return ascii;	//Unknown, probably 0
}

//Modifies appropriate flags. Returns 1 if provided scan code
//is a modifier key, or 0 otherwise.
uint8_t processModifierKey(uint8_t scanCode) {
	switch(scanCode) {
		case 0x2A:		//L shift (make)
		case 0x36:		//R shift
			caps = 1;
			break;

		case 0x3A:		//caps lock (ignore break code, toggle on make)
			caps = 1-caps;
			break;
		
		case 0xAA:		//break
		case 0xB6:
			caps = 0;
			break;
		
		case 0x38:
		//case 0xE038:
			alt = 1;
			break;
		
		case 0xB8:
		//case 0xE0B8:
			alt = 0;
			break;
		
		case 0x1D:
		//case 0xE01D:
			ctrl = 1;
			break;
		
		case 0x9D:
		//case 0xE09D:
			ctrl = 0;
			break;
		
		default:
			return 0;
			break;
	}
	return 1;
}