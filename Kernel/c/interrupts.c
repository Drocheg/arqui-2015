#include <interrupts.h>
#include <keyboard.h>
#include <ports.h>

extern char *keyboardBuffer;
extern int keyboardBufferIndex;
//Array de punteros a funcion

void IRQ_handler(int irq) {
	switch(irq) {
		case 0:	//Timer tick
			break;
		case 1:	//Keyboard
			keyboardInt();
			break;
	}
	//EOI(); No need, already done in ASM
	return;
}

void keyboardInt() {
	if(bufferIsFull()) return;
	keyboardBuffer[keyboardBufferIndex++] = portRead(0x60);
}

void testInt0() {
	ncPrintln("\nINT 0 RECEIVED");
}