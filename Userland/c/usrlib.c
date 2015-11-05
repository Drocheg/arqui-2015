#include <usrlib.h>
#include <commonDefs.h>
#include <syscalls.h>

char getChar() {
	char c;
	syscall(SYSREAD, STDIN, &c, 1, 0);
	return c;
}