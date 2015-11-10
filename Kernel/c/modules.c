#include <modules.h>
#include <lib.h>
#include <fileDescriptors.h>

typedef int32_t (*EntryPoint)();
static uint8_t running = 0;

int32_t runCodeModule() {
	if(running) {
		sys_write(STDERR, "Code module already running", 27);
		return -1;
	}
	running = 1;
	int32_t result;
	ncPrintHex(CODE_MODULE_ADDR);
	ncPrintChar('\n');
	ncPrintHex(*(uint64_t *)CODE_MODULE_ADDR);
	while(1);
	result = ((EntryPoint)CODE_MODULE_ADDR)();
	running = 0;
	return result;
}

char * readDataModule() {
	return (char*)DATA_MODULE_ADDR;
}