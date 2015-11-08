#include <terminal.h>
#include <usrlib.h>
#include <stdlib.h>
#include <scanCodes.h>
#include <syscalls.h>
#include <interrupts.h>

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
	{"datamodule", dumpDataModule},
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

void dumpDataModule() {
	char buff[1000];	//TODO allow to read until end of file rather than fixed-size buffer
	fread(DATA_MODULE, buff, sizeof(buff));
	printf(buff);
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

/*
#include "../../Kernel/include/speaker.h"

void reproducirMusica(uint8_t index) {
	uint64_t puntero = getSong(index);
	uint16_t frecuencia;
	uint8_t tiempo;
	uint32_t cant = (uint32_t)*puntero;
	puntero+=32; //Me salteo la cantidad;
	uint32_t contador=0;
	do{
		frecuencia = (uint16_t)puntero[0];
		puntero += 16;
		tiempo = (uint8_t)puntero[0];
		puntero += 8;
		offerNote(frecuencia,4,tiempo);
		//fwrite(SPEAKER,frecuencia,tiempo);
		contador++;
	}while(tiempo!=0 && contador<cant); 


}

uint64_t getSong(uint8_t index){
	char song[] = {0, 0, 0, 1, 1, 5, 10, 2, 11, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//uint64_t puntero=0x4000000;
	uint64_t puntero=(uint64_t)song;

	uint64_t count = 1;
	while(count<index){
		puntero+=((uint32_t)*puntero)*24+32; //16 de la freq y 8 del tiempo. Dice la cantidad de notas. +32 de la cantidad.
		count++;
	}
	//TODO NOW
}
*/

/*
Formato:
(32 bits) cantidad de notas = n
	n veces:
		(16 bits) frecuencia
		(8 bits) tiempo

ejemplo:     cant               !f1              !t1       !f2              !t2     !
00000000000000000000000000000001 0000000100000101 00001010 0000001000001011 00001010 
*/