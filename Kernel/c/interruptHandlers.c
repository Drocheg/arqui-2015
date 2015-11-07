#include <interruptHandlers.h>
#include <video.h>
#include <libasm.h>
#include <syscalls.h>
#include <fileDescriptors.h>
#include <lib.h>

#include <keyboard.h>

void timerTick();

void checkSound();

void int80Handler(uint32_t syscallID, uint32_t p1, uint32_t p2, uint32_t p3) {
	/*ncPrint("\nINT 80: Syscall #");
	ncPrintDec(syscallID);*/

	switch(syscallID) {
		case 0:	//Exit
			break;
		case SYSREAD:
			sys_read((uint8_t)p1, (char *)p2, p3);
			break;
		case SYSWRITE:
			sys_write((uint8_t)p1, (char *)p2, p3);
			break;
		case SYSCLEAR:
			ncClear();
			break;
		case REBOOT:
			outb(0x64, 0xFE);		//http://wiki.osdev.org/%228042%22_PS/2_Controller#CPU_Reset
			break;
		default:
			sys_write(STDERR, " Invalid syscall ID requested ", 29);
			ncPrintDec(syscallID);	//TODO delete
			break;
	}
}

void IRQ_handler(uint8_t irq) {
	uint8_t key;	//for keyboard, can't declare in SWITCH for some reason
	switch(irq) {
		case 0:	//Timer tick
			timerTick();
			break;
		case 1:	//Keyboard
			//If we don't read from the keyboard buffer, it doesn't fire interrupts again!
			key = inb(0x60);
			offerKey(key);
			break;
		default:
			ncPrint("?");
			break;
	}
	outb(0x20, 0x20);	//EOI
}

void timerTick() {
  	checkSound();
}

void checkSound() {
	if(!noSound()) {
		decreaseTimer();
	}
	if(noSound()) {
		soundOff();
	}


}