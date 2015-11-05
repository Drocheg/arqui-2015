#include <interruptHandlers.h>
#include <video.h>
#include <libasm.h>

void intHandler(uint8_t id) {
	ncPrint(" Interrupt #");
	ncPrintDec(id);
	if(id >= 32 && id <= 47) {	//IRQ hardware interrupt
		IRQ_handler(id-32);
		masterPICmask(0xFD);
	}
}

void IRQ_handler(uint8_t irq) {
	ncPrint(" IRQ #");
	ncPrintDec(irq);
	outb(0x20, 0x20);	//EOI
	/*
	switch(irq) {
		case 0:	//Timer tick
			sayHello();
			break;
		case 1:	//Keyboard
			keyboardInt();
			break;
		default:
			ncPrint("IRQ #");
			ncPrintDec(irq);
			ncPrintln(" received");
			break;
	}
	return;
	*/
}