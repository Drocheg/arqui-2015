#include <scanCodes.h>

static int initialized = 0;
static char keys[256] = {0};

void loadKeys();

//http://wiki.osdev.org/PS/2_Keyboard#Scan_Code_Sets.2C_Scan_Codes_and_Key_Codes SCAN CODE SET 1
uint8_t getCharFromScanCode(uint8_t scanCode) {
	if(!initialized) {
		loadKeys();
	}
	if(scanCode >= sizeof(keys)) return 0;
	return keys[scanCode];
}

//Loads make codes only
//TODO consider modifier keys?
void loadKeys() {
	keys[0x1E] = 'a';
	keys[0x30] = 'b';
	keys[0x2E] = 'c';
	keys[0x20] = 'd';
	keys[0x12] = 'e';
	keys[0x21] = 'f';
	keys[0x22] = 'g';
	keys[0x23] = 'h';
	keys[0x17] = 'i';
	keys[0x24] = 'j';
	keys[0x25] = 'k';
	keys[0x26] = 'l';
	keys[0x32] = 'm';
	keys[0x31] = 'n';
	keys[0x18] = 'o';
	keys[0x19] = 'p';
	keys[0x10] = 'q';
	keys[0x13] = 'r';
	keys[0x1F] = 's';
	keys[0x14] = 't';
	keys[0x16] = 'u';
	keys[0x2F] = 'v';
	keys[0x11] = 'w';
	keys[0x2D] = 'x';
	keys[0x15] = 'y';
	keys[0x2C] = 'z';
	keys[0x39] = ' ';
	keys[0x02] = '1';
	keys[0x03] = '2';
	keys[0x04] = '3';
	keys[0x05] = '4';
	keys[0x06] = '5';
	keys[0x07] = '6';
	keys[0x08] = '7';
	keys[0x09] = '8';
	keys[0x0A] = '9';
	keys[0x0B] = '0';
	keys[0x0C] = '-';
	keys[0x0D] = '=';
	keys[0x1A] = '[';
	keys[0x1B] = ']';
	keys[0x2B] = '\\';
	keys[0x27] = ';';
	keys[0x28] = '\'';
	keys[0x29] = '`';
	keys[0x33] = ',';
	keys[0x34] = '.';
	keys[0x35] = '/';
	keys[0x37] = '*';
	keys[0x4A] = '-';
	keys[0x4E] = '+';
	keys[0x4F] = '1';
	keys[0x50] = '2';
	keys[0x51] = '3';
	keys[0x4B] = '4';
	keys[0x4C] = '5';
	keys[0x4D] = '6';
	keys[0x47] = '7';
	keys[0x48] = '8';
	keys[0x49] = '9';
	keys[0x52] = '0';
	keys[0x53] = '.';
	keys[0x0E] = '\b';		//backspace
	keys[0x1C] = '\n';		//enter
	keys[0xE0] = '\n';		//keypad enter
	initialized = 1;
}