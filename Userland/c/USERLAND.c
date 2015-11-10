#include <stdint.h>
#include <usrlib.h>
#include <stdlib.h>
#include <scanCodes.h>
#include <syscalls.h>
#include <interrupts.h>
#include <songplayer.h>

#include <piano.h>
#include <fileDescriptors.h>

extern char bss;
extern char endOfBinary;
static int bssCheck = 0;

typedef struct
{
	char *name; 
	void (*function)(void);
	char *help;
} command;

void exit();
void help();
void jalp();
void sayHello();
void runCommand(char *cmd);
void dumpDataModule();
void codeModule();
void * memset(void * destiny, int32_t c, uint64_t length);

static int done = 0;
static command commands[] = {
	//{"beep", beep, "Makes a beep using the PC speaker"}, TODO
	{"clear", clearScreen, "Clears the screen"},
	{"codemodule", codeModule, "Runs the loaded code module"},
	{"playsong", playSong, "Plays the song loaded as data module"},
	{"exit", exit, "Exits the kernel"},
	{"help", help, "Shows this help"},
	{"hello", sayHello, "Greets the user"},
	{"jalp", jalp, "Ai can't spik inglish"},
	{"piano", piano, "Turns your keyboard into a piano!"},
	{"reboot", reboot, "Reboots the system"},
	{"scroll", scroll, "Scrolls an extra line"}
};


int32_t userland_main(int argc, char *argv[]) {
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);
	
	if(bssCheck != 0) {	//Improper BSS setup
		return -1;
	}

	char *msg = "LALALAL";
	_int80(SYSWRITE, STDOUT, (int64_t)msg, 7);

	while(1);
	

	clearScreen();

	printf("\nHello from userland!\n");
	return 0;
	char buffer[100];
	int majorVer = 1, minorVer = 0;
	vargs la = {2, (void *[2]) {&majorVer, &minorVer}};
	printf2("Terminal v%i.%i\n", &la);
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

	/*
	//RAINBOWW
	char *video = (char *)0xB8000;
	for(int i = 1; i < (80*25*2)-1; i += 2) {
		video[i] = (char)i;
	}
	video = video + (80*2*12) + (30*2);
	char *message = "TASTE THE RAINBOWWWW";
	for(int i = 0; message[i] != 0; i++) {
		video[i] = message[i];
		video++;
	}
	*/
	return 0;
}

void * memset(void * dest, int32_t c, uint64_t length) {
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)dest;

	while(length--)
		dst[length] = chr;

	return dest;
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
	printf("Aveilabel comandz:\n");
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		printf("    ");
		printf(commands[i].name);
		printf(" (jau du iu pronaunz dat?)");
		printf("\n");
	}
}

void help() {
	clearScreen();
	printf("Available commands:\n");
	for(int i = 0; i < sizeof(commands)/sizeof(command); i++) {
		vargs a = {2, (void *[2]) {commands[i].name, commands[i].help}};
		printf2("    %s - %s\n", &a);

		/*printf("    ");
		printf(commands[i].name);
		printf(" - ");
		printf(commands[i].help);
		printf("\n");*/
	}
}