#include <terminal.h>
#include <usrlib.h>
#include <stdlib.h>

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
	printf("Welcome to the terminal!\n>");
	/*char buffer[100];
	int i = 0;
	while(!done) {
		i = 0;
		char c;
		while(i < sizeof(buffer)-1 && (c = getchar()) != '\n') {	//TODO use scanf here
			buffer[i++] = c;
		}
		buffer[i++] = 0;
		for(i = 0; i < sizeof(commands)/sizeof(command); i++) {
			if(streql(toLowerStr(buffer), commands[i].name)) {
				commands[i].function();
			}
		}
	}*/
}

void exit() {
	done = 1;
}

void help() {
	printf("Welcome to help!");
}