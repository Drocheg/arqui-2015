#include <idt.h>
#include <video.h>
#include <lib.h>

/*static INTERRUPT_DESCRIPTOR *IDT = 0;

void setInterrupt(uint8_t index, uint64_t offset) {
	if(index < 0 || index >= IDT_SIZE) return;
	IDT[index].offset_low = offset & 0xFFFF;
	IDT[index].offset_middle = offset & 0xFFFF0000;
	IDT[index].offset_high = offset >> 32;
	
	IDT[index].type = 0x0E;			//00001110
	IDT[index].selector = 0x08;		//00001000
	IDT[index].zero1 = 0;
	IDT[index].zero2 = 0;
	ncPrint("Interrupt ");
	ncPrintDec(index);
	ncPrint(" at 0x");
	ncPrintHex((uint64_t)(IDT+index));
	
	ncNewline();
	ncPrintBin(IDT[index].offset_low);
	//ncPrint("|");
	ncPrintBin(IDT[index].selector);
	//ncPrint("|");
	ncPrintBin(IDT[index].zero1);
	//ncPrint("|");
	ncPrintBin(IDT[index].type);
	//ncPrint("|");
	ncPrintBin(IDT[index].offset_middle);
	//ncPrint("|");
	
	//ncNewline();
	ncPrintBin(IDT[index].offset_high);
	//ncPrint("|");
	ncPrintBin(IDT[index].zero2);
	//ncPrint("|");
}*/

static uint8_t * const IDT_start = (uint8_t*)0;

void setInterrupt(uint8_t index, /*uint8_t selector,*/ uint64_t offset/*, uint8_t type*/) {
	if(index < 0 || index >= IDT_SIZE) return;
	uint8_t *p = (uint8_t *) (IDT_start+(sizeof(INTERRUPT_DESCRIPTOR)*index));

	INTERRUPT_DESCRIPTOR d;

	d.offset_low = offset & 0xFFFF;
	d.offset_middle = offset & 0xFFFF0000;
	d.offset_high = offset >> 32;
	
	d.type = (uint8_t)0xE;			//00001110
	d.selector = (uint16_t)0x8;		//00001000
	d.zero1 = 0;
	d.zero2 = 0;

	memcpy(p, &d, sizeof(INTERRUPT_DESCRIPTOR));

	/*ncPrint("Interrupt ");
	ncPrintDec(index);
	ncPrint(" at 0x");
	ncPrintHex((uint64_t)p);
	
	ncNewline();
	ncPrintBin(d.offset_low);
	//ncPrint("|");
	ncPrintBin(d.selector);
	//ncPrint("|");
	ncPrintBin(d.zero1);
	//ncPrint("|");
	ncPrintBin(d.type);
	//ncPrint("|");
	ncPrintBin(d.offset_middle);
	//ncPrint("|");
	
	//ncNewline();
	ncPrintBin(d.offset_high);
	//ncPrint("|");
	ncPrintBin(d.zero2);
	//ncPrint("|");*/
}