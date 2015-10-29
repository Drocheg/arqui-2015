#include <syscalls.h>
#include <stdint.h>
#include <files.h>

uint64_t syscallHandler(uint64_t id, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4) {	//TODO var args?
	uint64_t result = -1;
	//Implementar array de funciones
	switch(id) {
		case WRITE:
			result = fwrite(p1, (char *)p2, p3);
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