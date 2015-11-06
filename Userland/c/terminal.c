#include <terminal.h>
#include <usrlib.h>
#include <stdlib.h>
#include <scanCodes.h>

#include <piano.h>
#include <fileDescriptors.h>

typedef struct
{
	char *name; 
	void (*function)(void);
} command;

void exit();
void help();
void jalp();
void sayHello();
void runCommand(char *cmd, ...);

#include "../../Kernel/include/speaker.h"

static int done = 0;
static command commands[] = {
	{"beep", beep},
	{"clear", clearScreen},
	{"exit", exit},
	{"help", help},
	{"hello", sayHello},
	{"jalp", jalp},
	{"piano", piano},
	{"reboot", reboot}
};

void runTerminal() {
	clearScreen();
	char buffer[100];
	while(!done) {
		uint8_t index = 0;
		uint8_t c;
		printf(">_");
		while((c = getCharFromScanCode(getchar())) != '\n') {
			//Move cursor if valid key
			if(c != 0) {
				putchar('\b');
				putchar(c);
				putchar('_');
			}
			//Store in buffer if necessary and possible
			if(c == '\b' && index > 0) {
				index--;
			}
			else if(index < sizeof(buffer)-1 && c != 0) {
				buffer[index++] = c;
			}
		}
		//Entry finished, terminate with null
		buffer[index] = 0;
		printf("\n");
		//Extract command from entry (up to space)
		runCommand(buffer);
		/*int spaceIndex = indexOf(buffer, " ");
		if(spaceIndex == -1) {	//No spaces
			
		}*/
		printf("\n");
	}
	printf("\nBye-bye!");
}

void runCommand(char *cmd, ...) {
	toLowerStr(cmd);
	int found = 0;
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		if(streql(cmd, commands[i].name)) {
			commands[i].function();
			found = 1;
			break;
		}
	}
	if(!found) {
		fwrite(STDOUT, "No such command.", 16);
		//printf("No such command.");
	}
}

void exit() {
	done = 1;
}

void sayHello() {
	printf("\nHello!\n");
}

void jalp() {
	clearScreen();
	printf("You wanted jalp? Here's your jalp:\n");
	printf("Available commands:\n\n");
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		printf("    ");
		printf(commands[i].name);
		printf("\n");
	}
}

void help() {
	printf("No, no, no ingrish. Trai \"jalp\"");
}