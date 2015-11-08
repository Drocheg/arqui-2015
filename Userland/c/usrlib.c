#include <usrlib.h>
#include <stdlib.h>
#include <interrupts.h>
#include <syscalls.h>
#include <fileDescriptors.h>
#include <scanCodes.h>

void fread(uint8_t fd, char *buff, uint64_t maxBytes) {
	_int80(SYSREAD, fd, (uint64_t)buff, maxBytes);
}

void fwrite(uint8_t fd, char *buff, uint64_t maxBytes) {
	_int80(SYSWRITE, fd, (uint64_t)buff, maxBytes);
}

void putchar(char c) {
	_int80(SYSWRITE, STDOUT, (uint64_t)&c, 1);
}

char getchar() {
	char result;
	_int80(SYSREAD, STDIN, (uint64_t)&result, 1);
	return result;
}

uint8_t getscancode() {
	char result;
	_int80(SYSREAD, STDIN_RAW, (uint64_t)&result, 1);
	return result;
}

uint32_t getCaretPosition() {
	uint32_t result;
	result = _int80(GETCARETPOS, 0, 0, 0);
	return result;
}

void clearScreen() {
	_int80(SYSCLEAR, 0, 0, 0);
}

void scroll() {
	_int80(SCROLL, 1, 0, 0);
}

void reboot() {
	_int80(REBOOT, 0, 0, 0);
}

void printf(const char *format, ...) {
	char **arg = (char **) &format;
	int c;
	char buf[20];

	arg++;
	while((c = *format++) != 0) {
		if (c != '%') {
			putchar(c);
		}
		else {
			char *p;
			c = *format++;
			switch (c) {
				case 'd':
				case 'x':
					intToStrBase(*((int *) arg++), buf, (c == 'd' ? 10 : 16));
					p = buf;
					goto STRING;
					break;

				case 'c':
					putchar(*arg++);
					break;

				case 's':
					p = *arg++;
					if (! p)
						p = "(null)";

					STRING:
					while (*p)
						putchar(*p++);
					break;

				default:
					putchar(*((int *) arg++));
					break;
			}
		}
	}
}

//Buff should be NULL TERMINATED
void scanf(char format, char *buff) {
	if(format != 's' /*&& format != 'd'*/) return;	//TODO support other formats
	
	int len = strlen(buff);
	fread(STDIN, buff, len);
	if(format == 'd') {
		//Magic?
	}
}