#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#pragma pack(push)
#pragma pack (1) 		/* Alinear las siguiente estructuras a 1 byte */
typedef struct 
{
	uint16_t	offset_low;		// offset bits 0..15
	uint16_t	selector;		// a code segment selector in GDT or LDT
	uint8_t		zero1;			// unused, set to 0
	uint8_t		type;			// type and attributes, see below
	uint16_t	offset_middle;	// offset bits 16..31
	uint32_t	offset_high;	// offset bits 32..63
	uint32_t	zero2;			// unused, set to 0
} INTERRUPT_DESCRIPTOR;
#pragma pack(pop)

#define IDT_SIZE 256

void setInterrupt(uint8_t index, /*uint8_t selector,*/ uint64_t offset/*, uint8_t type*/);

#endif