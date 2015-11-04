#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <video.h>
#include <files.h>
#include <keyboard.h>
#include <idt.h>
#include <interrupts.h>
#include <pic.h>
#include <libasm.h>
#include <intHandler.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};
	loadModules(&endOfKernelBinary, moduleAddresses);
	clearBSS(&bss, &endOfKernel - &bss);
	ncPrintln("Kernel binary initialized.");
	return getStackBase();
}

int main()
{	
	ncClear();
	ncPrintln("Welcome to the kernel!");
	
	_sti();
	masterPICmask((uint8_t)0);	//Habilitar todoooo
	setInterrupt(0, (uint64_t)&sayHello);
	_int0();
	while(1);

	/*for(int i = 0; i < IDT_SIZE; i++) {
		setInterrupt(i, (uint64_t)&_int0);
	}*/
	
	
	/*ncNewline();
	char copy[32];
	memcpy(copy, (char *)0, 32);
	ncPrint("\nIDT[0] = \n");
	int i;
	for(i = 0; i < sizeof(copy); i++) {
		ncPrintBin((uint8_t)copy[i]);
	}
	ncNewline();
	testInt0();*/

	/*uint8_t i;
	for(i = 0; i < IDT_SIZE; i++) {
		setInterrupt(i, (uint64_t)&testInt0);
	}*/
	/*while(1) {
		if(!bufferIsEmpty()) {
			ncPrintDec(getPressedKey());
		}
	}*/
	return 0;
}
