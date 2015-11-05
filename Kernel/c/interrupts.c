#include <interrupts.h>
#include <keyboard.h>
#include <ports.h>
#include <video.h>



extern char *keyboardBuffer;
extern int keyboardBufferIndex;
//Array de punteros a funcion

void IRQ_handler(int irq) {
	ncPrint("IRQ #");
	ncPrintDec(irq);


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
}

void keyboardInt() {
	
	if(bufferIsFull()) return;
	ncPrintln("Keyboard interrupt received.");
	keyboardBuffer[keyboardBufferIndex++] = portRead(0x60);
  	/*if(portRead(0x60)!='\n'){
		printScanCode(portRead(0x60)); //TODO getScanCode
	}*/
}

void sayHello() {
	ncPrintln("\nInterrupt received");
}

char getCharFromScanCode(uint8_t scanCode) {
	return -1;	//TODO
}