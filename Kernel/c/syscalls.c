#include <syscalls.h>
#include <stdint.h>
#include <files.h>
//array de funciones

uint64_t syscallHandler(uint64_t id, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4) {	//TODO var args?
	uint64_t result = -1;
	switch(id) {
		case WRITE:
			result = fwrite(p1, p2, p3);
		break;

		case READ:
			result = fread(p1, p2, p3);
		break;

		case EXIT:

		break;

		case DO_AWESOME_SHIT:

		break;
	}
	return result;
}


uint64_t writeHandler(uint64_t fd, char * buffer, uint64_t bytes) {
	


	int result = 0;
	//Cortar efficiente cosas

	switch(fd){
		case 1:
		int i;
		for (i = 0; buffer[i] != 0 && i<bytes; i++){
			ncPrintChar(buffer[i]);
			result++;
		}
		break;
		case 3:
		//Print Distinto. //Error?
		break;
		case 2:
		//Sonido
		break;
	}
	return result;
}

uint64_t readHandler(uint64_t fd, char * buffer, uint64_t bytes) {

	int result = 0;
	switch(fd){
		case 0:
		int i;
		for (i = 0; buffer[i] != 0 && i<bytes; i++){
			ncPrintChar(buffer[i]);
			result++;
		}
		break;
	}
	return result;
}


int isKeyPressed() {
	int result = portRead(0x64);
	return result;
}

int getPressedKey() {
	if(!isKeyPressed()) return -1;	//See http://stanislavs.org/helppc/8042.html (also what would I return if no key is pressed?!)
	int result = portRead(0x60);
	return result;
}