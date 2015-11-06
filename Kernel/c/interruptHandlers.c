#include <interruptHandlers.h>
#include <video.h>
#include <libasm.h>
#include <syscalls.h>
#include <fileDescriptors.h>
#include <lib.h>

#include <keyboard.h>

void int80Handler(uint32_t syscallID, uint32_t p1, uint32_t p2, uint32_t p3) {
	ncPrint("\nINT 80: Syscall #");
	ncPrintDec(syscallID);

	//TODO NOW make this work properly. Also take a look at interrupts.asm -- no interrupt is ever actually called

	/*
	TODO call appropriate system function from here. I.E:
	0) EXIT
	1) READ
	2) WRITE
	
	switch(syscallID) {
		case 0:	//Exit

			break;
		case SYSREAD:
			return sys_read((uint8_t)p1, (char *)p2, p3);
			break;
		case SYSWRITE:
			return sys_write((uint8_t)p1, (char *)p2, p3);
			break;
		default:
			sys_write(STDERR, "Invalid syscall ID requested", 28);
			return -1;
			break;
	}
	*/
}

void IRQ_handler(uint8_t irq) {
	uint8_t key;	//for keyboard, can't declare in SWITCH for some reason
	switch(irq) {
		case 0:	//Timer tick
			//ncPrint("t");
			break;
		case 1:	//Keyboard
			//If we don't read from the keyboard buffer, it doesn't fire interrupts again!
			key = inb(0x60);
			/*ncPrintHex(key);
			ncPrintChar(' ');*/
			offerKey(key);
			if(key == 28) {
				while(!bufferIsEmpty()) {
					key = pollKey();
					ncPrintHex(key);
					ncPrintChar(' ');
				}
			}
			break;
		default:
			ncPrint("?");
			break;
	}
	outb(0x20, 0x20);	//EOI
}