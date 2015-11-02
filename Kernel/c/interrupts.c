#include <interrupts.h>
#include <keyboard.h>
#include <ports.h>
#include <video.h>

extern char *keyboardBuffer;
extern int keyboardBufferIndex;
//Array de punteros a funcion

void EOI();	//File-specific functions
void sayHello();

void IRQ_handler(int irq) {
	switch(irq) {
		case 0:	//Timer tick
			sayHello();
			break;
		case 1:	//Keyboard
			keyboardInt();
			break;
	}
	EOI();
	return;
}

void EOI() {
 	portWrite(0x20, 0x20);
}

void keyboardInt() {
	if(bufferIsFull()) return;
	keyboardBuffer[keyboardBufferIndex++] = portRead(0x60);
}

void sayHello() {
	ncPrintln("\nINT 0 RECEIVED");
}