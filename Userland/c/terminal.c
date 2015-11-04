#include <terminal.h>
#include <stdlib.h>
#include "../../Kernel/include/syscalls.h"
#include "../../Kernel/include/files.h"

typedef struct
{
	char *name;
	void (*function)(void);
} command;

void exit();
void help();

static int done = 0;
static command commands[] = {
	{"exit", exit},
	{"jalp", help},
	{"help", help}
};

void runTerminal() {
	char buffer[100];
	while(!done) {
		sysCall(READ, KEYBOARD, (uint64_t)buffer, sizeof(buffer), 0);	//Bloqueante
		int i;
		for(i = 0; i < sizeof(commands)/sizeof(command); i++) {
			if(streql(toLowerStr(buffer), commands[i].name)) {
				commands[i].function();
			}
		}
	}
}

void exit() {
	done = 1;
}

void help() {
	char *msg = "Welcome to help!";
	sysCall(WRITE, STDOUT, (uint64_t)msg, sizeof(msg), 0);	//TODO change with printf
}