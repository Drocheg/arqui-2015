#include <terminal.h>
#include <usrlib.h>
#include <stdlib.h>

#include <fileDescriptors.h>

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
	printf("\n$>");
	fwrite(STDERR, "Test error", 10);
	char buffer[100];
	int i;
	/*while(!done) {
		i = 0;
		char c;
		while(i < sizeof(buffer)-1 && (c = getchar()) != '\n') {
			buffer[i++] = c;
			putchar(c);
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