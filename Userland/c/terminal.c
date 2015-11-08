#include <terminal.h>
#include <usrlib.h>
#include <stdlib.h>
#include <scanCodes.h>
#include <syscalls.h>
#include <interrupts.h>
#include <songplayer.h>

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
void runCommand(char *cmd);
void dumpDataModule();
void codeModule();

#include "../../Kernel/include/speaker.h"

static int done = 0;
static command commands[] = {
	{"beep", beep},
	{"clear", clearScreen},
	{"codemodule", codeModule},
	{"playsong", playSong},
	{"exit", exit},
	{"help", help},
	{"hello", sayHello},
	{"jalp", jalp},
	{"piano", piano},
	{"reboot", reboot},
	{"scroll", scroll}
};

void runTerminal() {
	clearScreen();
	char buffer[100];
	while(!done) {
		uint8_t index = 0;
		uint8_t c;
		printf(">_");
		while((c = getchar()) != '\n') {
			if(c != 0) {					//Recognized key, print it and save it
				if(c == '\b') {				//Entered backspace
					if(index > 0) {			//NOT at beginning of line, discard entered key
						index--;
					}
					else {
						putchar('_');		//Don't want to erase the >_ prompt, so counter the \b with another char
					}
				}
				else if(index < sizeof(buffer)-1) {	//Save key
					buffer[index++] = c;
				}
				putchar('\b');
				putchar(c);
				putchar('_');
			}
		}
		buffer[index] = 0;					//Entry finished, terminate with null
		printf("\n");
		runCommand(buffer);
		if(!streql(buffer, "clear")) {
			printf("\n");
		}
	}
	printf("\nBye-bye!");
}

void runCommand(char *cmd) {
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
		printf("No such command.");
	}
}

void codeModule() {
	clearScreen();
	_int80(RUNCODEMODULE, 0, 0, 0);
}

void exit() {
	done = 1;
}

void sayHello() {
	printf("\nHello!\n");
}

void jalp() {
	clearScreen();
	printf("Iu asked for jalp frend? Jier is sam jalp:\n");
	printf("Aveilabel comandz:\n\n");
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		printf("    ");
		printf(commands[i].name);
		printf(" (jau du iu pronaunz dat?)");
		printf("\n");
	}
}

void help() {
	clearScreen();
	printf("Available commands:\n\n");
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		printf("    ");
		printf(commands[i].name);
		printf("\n");
	}
}