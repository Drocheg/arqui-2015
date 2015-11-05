#include <interruptHandlers.h>
#include <video.h>
#include <libasm.h>

#include <keyboard.h>

void intHandler(uint8_t id) {
	if(id >= 32 && id <= 47) {	//IRQ hardware interrupt
		IRQ_handler(id-32);
	}
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
			push(key);
			if(key == 28) {
				while(!bufferIsEmpty()) {
					key = pop();
					ncPrintHex(key);
					ncPrintChar(' ');
				}
			}
			break;
		default:
			ncPrint("?");
			break;
	}
}