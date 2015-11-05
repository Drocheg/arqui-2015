#include <syscalls.h>
#include <commonDefs.h>

uint64_t sysCall(uint64_t id, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4) {	//TODO var args?
	uint64_t result = -1;
	
	result = _int80(id, p1, p2, p3, p4);

	//Implementar array de funciones
	/*switch(id) {
		case SYSWRITE:
			result = fwrite(p1, (char *)p2, p3);
		break;

		case SYSREAD:
			result = fread(p1, (char *)p2, p3);
		break;

		case SYSEXIT:

		break;

		case DO_AWESOME_SHIT:

		break;
	}*/
	return result;
}