#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <video.h>
#include <interrupts.h>
#include <idt.h>
#include <libasm.h>

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
	ncPrint("Kernel binary initialized.");
	return getStackBase();
}

int main()
{	
	ncClear();
	ncPrint("Welcome to the kernel!");
		
		setInterrupt(0x0, (uint64_t)&_int0);
		setInterrupt(0x1, (uint64_t)&_int1);
		setInterrupt(0x2, (uint64_t)&_int2);
		setInterrupt(0x3, (uint64_t)&_int3);
		setInterrupt(0x4, (uint64_t)&_int4);
		setInterrupt(0x5, (uint64_t)&_int5);
		setInterrupt(0x6, (uint64_t)&_int6);
		setInterrupt(0x7, (uint64_t)&_int7);
		setInterrupt(0x8, (uint64_t)&_int8);
		setInterrupt(0x9, (uint64_t)&_int9);
		setInterrupt(0xa, (uint64_t)&_inta);
		setInterrupt(0xb, (uint64_t)&_intb);
		setInterrupt(0xc, (uint64_t)&_intc);
		setInterrupt(0xd, (uint64_t)&_intd);
		setInterrupt(0xe, (uint64_t)&_inte);
		setInterrupt(0xf, (uint64_t)&_intf);
		setInterrupt(0x10, (uint64_t)&_int10);
		setInterrupt(0x11, (uint64_t)&_int11);
		setInterrupt(0x12, (uint64_t)&_int12);
		setInterrupt(0x13, (uint64_t)&_int13);
		setInterrupt(0x14, (uint64_t)&_int14);
		setInterrupt(0x15, (uint64_t)&_int15);
		setInterrupt(0x16, (uint64_t)&_int16);
		setInterrupt(0x17, (uint64_t)&_int17);
		setInterrupt(0x18, (uint64_t)&_int18);
		setInterrupt(0x19, (uint64_t)&_int19);
		setInterrupt(0x1a, (uint64_t)&_int1a);
		setInterrupt(0x1b, (uint64_t)&_int1b);
		setInterrupt(0x1c, (uint64_t)&_int1c);
		setInterrupt(0x1d, (uint64_t)&_int1d);
		setInterrupt(0x1e, (uint64_t)&_int1e);
		setInterrupt(0x1f, (uint64_t)&_int1f);
		setInterrupt(0x20, (uint64_t)&_int20);
		setInterrupt(0x21, (uint64_t)&_int21);
		setInterrupt(0x22, (uint64_t)&_int22);
		setInterrupt(0x23, (uint64_t)&_int23);
		setInterrupt(0x24, (uint64_t)&_int24);
		setInterrupt(0x25, (uint64_t)&_int25);
		setInterrupt(0x26, (uint64_t)&_int26);
		setInterrupt(0x27, (uint64_t)&_int27);
		setInterrupt(0x28, (uint64_t)&_int28);
		setInterrupt(0x29, (uint64_t)&_int29);
		setInterrupt(0x2a, (uint64_t)&_int2a);
		setInterrupt(0x2b, (uint64_t)&_int2b);
		setInterrupt(0x2c, (uint64_t)&_int2c);
		setInterrupt(0x2d, (uint64_t)&_int2d);
		setInterrupt(0x2e, (uint64_t)&_int2e);
		setInterrupt(0x2f, (uint64_t)&_int2f);
		setInterrupt(0x30, (uint64_t)&_int30);
		setInterrupt(0x31, (uint64_t)&_int31);
		setInterrupt(0x32, (uint64_t)&_int32);
		setInterrupt(0x33, (uint64_t)&_int33);
		setInterrupt(0x34, (uint64_t)&_int34);
		setInterrupt(0x35, (uint64_t)&_int35);
		setInterrupt(0x36, (uint64_t)&_int36);
		setInterrupt(0x37, (uint64_t)&_int37);
		setInterrupt(0x38, (uint64_t)&_int38);
		setInterrupt(0x39, (uint64_t)&_int39);
		setInterrupt(0x3a, (uint64_t)&_int3a);
		setInterrupt(0x3b, (uint64_t)&_int3b);
		setInterrupt(0x3c, (uint64_t)&_int3c);
		setInterrupt(0x3d, (uint64_t)&_int3d);
		setInterrupt(0x3e, (uint64_t)&_int3e);
		setInterrupt(0x3f, (uint64_t)&_int3f);
		setInterrupt(0x40, (uint64_t)&_int40);
		setInterrupt(0x41, (uint64_t)&_int41);
		setInterrupt(0x42, (uint64_t)&_int42);
		setInterrupt(0x43, (uint64_t)&_int43);
		setInterrupt(0x44, (uint64_t)&_int44);
		setInterrupt(0x45, (uint64_t)&_int45);
		setInterrupt(0x46, (uint64_t)&_int46);
		setInterrupt(0x47, (uint64_t)&_int47);
		setInterrupt(0x48, (uint64_t)&_int48);
		setInterrupt(0x49, (uint64_t)&_int49);
		setInterrupt(0x4a, (uint64_t)&_int4a);
		setInterrupt(0x4b, (uint64_t)&_int4b);
		setInterrupt(0x4c, (uint64_t)&_int4c);
		setInterrupt(0x4d, (uint64_t)&_int4d);
		setInterrupt(0x4e, (uint64_t)&_int4e);
		setInterrupt(0x4f, (uint64_t)&_int4f);
		setInterrupt(0x50, (uint64_t)&_int50);
		setInterrupt(0x51, (uint64_t)&_int51);
		setInterrupt(0x52, (uint64_t)&_int52);
		setInterrupt(0x53, (uint64_t)&_int53);
		setInterrupt(0x54, (uint64_t)&_int54);
		setInterrupt(0x55, (uint64_t)&_int55);
		setInterrupt(0x56, (uint64_t)&_int56);
		setInterrupt(0x57, (uint64_t)&_int57);
		setInterrupt(0x58, (uint64_t)&_int58);
		setInterrupt(0x59, (uint64_t)&_int59);
		setInterrupt(0x5a, (uint64_t)&_int5a);
		setInterrupt(0x5b, (uint64_t)&_int5b);
		setInterrupt(0x5c, (uint64_t)&_int5c);
		setInterrupt(0x5d, (uint64_t)&_int5d);
		setInterrupt(0x5e, (uint64_t)&_int5e);
		setInterrupt(0x5f, (uint64_t)&_int5f);
		setInterrupt(0x60, (uint64_t)&_int60);
		setInterrupt(0x61, (uint64_t)&_int61);
		setInterrupt(0x62, (uint64_t)&_int62);
		setInterrupt(0x63, (uint64_t)&_int63);
		setInterrupt(0x64, (uint64_t)&_int64);
		setInterrupt(0x65, (uint64_t)&_int65);
		setInterrupt(0x66, (uint64_t)&_int66);
		setInterrupt(0x67, (uint64_t)&_int67);
		setInterrupt(0x68, (uint64_t)&_int68);
		setInterrupt(0x69, (uint64_t)&_int69);
		setInterrupt(0x6a, (uint64_t)&_int6a);
		setInterrupt(0x6b, (uint64_t)&_int6b);
		setInterrupt(0x6c, (uint64_t)&_int6c);
		setInterrupt(0x6d, (uint64_t)&_int6d);
		setInterrupt(0x6e, (uint64_t)&_int6e);
		setInterrupt(0x6f, (uint64_t)&_int6f);
		setInterrupt(0x70, (uint64_t)&_int70);
		setInterrupt(0x71, (uint64_t)&_int71);
		setInterrupt(0x72, (uint64_t)&_int72);
		setInterrupt(0x73, (uint64_t)&_int73);
		setInterrupt(0x74, (uint64_t)&_int74);
		setInterrupt(0x75, (uint64_t)&_int75);
		setInterrupt(0x76, (uint64_t)&_int76);
		setInterrupt(0x77, (uint64_t)&_int77);
		setInterrupt(0x78, (uint64_t)&_int78);
		setInterrupt(0x79, (uint64_t)&_int79);
		setInterrupt(0x7a, (uint64_t)&_int7a);
		setInterrupt(0x7b, (uint64_t)&_int7b);
		setInterrupt(0x7c, (uint64_t)&_int7c);
		setInterrupt(0x7d, (uint64_t)&_int7d);
		setInterrupt(0x7e, (uint64_t)&_int7e);
		setInterrupt(0x7f, (uint64_t)&_int7f);
		setInterrupt(0x80, (uint64_t)&_int80);
		setInterrupt(0x81, (uint64_t)&_int81);
		setInterrupt(0x82, (uint64_t)&_int82);
		setInterrupt(0x83, (uint64_t)&_int83);
		setInterrupt(0x84, (uint64_t)&_int84);
		setInterrupt(0x85, (uint64_t)&_int85);
		setInterrupt(0x86, (uint64_t)&_int86);
		setInterrupt(0x87, (uint64_t)&_int87);
		setInterrupt(0x88, (uint64_t)&_int88);
		setInterrupt(0x89, (uint64_t)&_int89);
		setInterrupt(0x8a, (uint64_t)&_int8a);
		setInterrupt(0x8b, (uint64_t)&_int8b);
		setInterrupt(0x8c, (uint64_t)&_int8c);
		setInterrupt(0x8d, (uint64_t)&_int8d);
		setInterrupt(0x8e, (uint64_t)&_int8e);
		setInterrupt(0x8f, (uint64_t)&_int8f);
		setInterrupt(0x90, (uint64_t)&_int90);
		setInterrupt(0x91, (uint64_t)&_int91);
		setInterrupt(0x92, (uint64_t)&_int92);
		setInterrupt(0x93, (uint64_t)&_int93);
		setInterrupt(0x94, (uint64_t)&_int94);
		setInterrupt(0x95, (uint64_t)&_int95);
		setInterrupt(0x96, (uint64_t)&_int96);
		setInterrupt(0x97, (uint64_t)&_int97);
		setInterrupt(0x98, (uint64_t)&_int98);
		setInterrupt(0x99, (uint64_t)&_int99);
		setInterrupt(0x9a, (uint64_t)&_int9a);
		setInterrupt(0x9b, (uint64_t)&_int9b);
		setInterrupt(0x9c, (uint64_t)&_int9c);
		setInterrupt(0x9d, (uint64_t)&_int9d);
		setInterrupt(0x9e, (uint64_t)&_int9e);
		setInterrupt(0x9f, (uint64_t)&_int9f);
		setInterrupt(0xa0, (uint64_t)&_inta0);
		setInterrupt(0xa1, (uint64_t)&_inta1);
		setInterrupt(0xa2, (uint64_t)&_inta2);
		setInterrupt(0xa3, (uint64_t)&_inta3);
		setInterrupt(0xa4, (uint64_t)&_inta4);
		setInterrupt(0xa5, (uint64_t)&_inta5);
		setInterrupt(0xa6, (uint64_t)&_inta6);
		setInterrupt(0xa7, (uint64_t)&_inta7);
		setInterrupt(0xa8, (uint64_t)&_inta8);
		setInterrupt(0xa9, (uint64_t)&_inta9);
		setInterrupt(0xaa, (uint64_t)&_intaa);
		setInterrupt(0xab, (uint64_t)&_intab);
		setInterrupt(0xac, (uint64_t)&_intac);
		setInterrupt(0xad, (uint64_t)&_intad);
		setInterrupt(0xae, (uint64_t)&_intae);
		setInterrupt(0xaf, (uint64_t)&_intaf);
		setInterrupt(0xb0, (uint64_t)&_intb0);
		setInterrupt(0xb1, (uint64_t)&_intb1);
		setInterrupt(0xb2, (uint64_t)&_intb2);
		setInterrupt(0xb3, (uint64_t)&_intb3);
		setInterrupt(0xb4, (uint64_t)&_intb4);
		setInterrupt(0xb5, (uint64_t)&_intb5);
		setInterrupt(0xb6, (uint64_t)&_intb6);
		setInterrupt(0xb7, (uint64_t)&_intb7);
		setInterrupt(0xb8, (uint64_t)&_intb8);
		setInterrupt(0xb9, (uint64_t)&_intb9);
		setInterrupt(0xba, (uint64_t)&_intba);
		setInterrupt(0xbb, (uint64_t)&_intbb);
		setInterrupt(0xbc, (uint64_t)&_intbc);
		setInterrupt(0xbd, (uint64_t)&_intbd);
		setInterrupt(0xbe, (uint64_t)&_intbe);
		setInterrupt(0xbf, (uint64_t)&_intbf);
		setInterrupt(0xc0, (uint64_t)&_intc0);
		setInterrupt(0xc1, (uint64_t)&_intc1);
		setInterrupt(0xc2, (uint64_t)&_intc2);
		setInterrupt(0xc3, (uint64_t)&_intc3);
		setInterrupt(0xc4, (uint64_t)&_intc4);
		setInterrupt(0xc5, (uint64_t)&_intc5);
		setInterrupt(0xc6, (uint64_t)&_intc6);
		setInterrupt(0xc7, (uint64_t)&_intc7);
		setInterrupt(0xc8, (uint64_t)&_intc8);
		setInterrupt(0xc9, (uint64_t)&_intc9);
		setInterrupt(0xca, (uint64_t)&_intca);
		setInterrupt(0xcb, (uint64_t)&_intcb);
		setInterrupt(0xcc, (uint64_t)&_intcc);
		setInterrupt(0xcd, (uint64_t)&_intcd);
		setInterrupt(0xce, (uint64_t)&_intce);
		setInterrupt(0xcf, (uint64_t)&_intcf);
		setInterrupt(0xd0, (uint64_t)&_intd0);
		setInterrupt(0xd1, (uint64_t)&_intd1);
		setInterrupt(0xd2, (uint64_t)&_intd2);
		setInterrupt(0xd3, (uint64_t)&_intd3);
		setInterrupt(0xd4, (uint64_t)&_intd4);
		setInterrupt(0xd5, (uint64_t)&_intd5);
		setInterrupt(0xd6, (uint64_t)&_intd6);
		setInterrupt(0xd7, (uint64_t)&_intd7);
		setInterrupt(0xd8, (uint64_t)&_intd8);
		setInterrupt(0xd9, (uint64_t)&_intd9);
		setInterrupt(0xda, (uint64_t)&_intda);
		setInterrupt(0xdb, (uint64_t)&_intdb);
		setInterrupt(0xdc, (uint64_t)&_intdc);
		setInterrupt(0xdd, (uint64_t)&_intdd);
		setInterrupt(0xde, (uint64_t)&_intde);
		setInterrupt(0xdf, (uint64_t)&_intdf);
		setInterrupt(0xe0, (uint64_t)&_inte0);
		setInterrupt(0xe1, (uint64_t)&_inte1);
		setInterrupt(0xe2, (uint64_t)&_inte2);
		setInterrupt(0xe3, (uint64_t)&_inte3);
		setInterrupt(0xe4, (uint64_t)&_inte4);
		setInterrupt(0xe5, (uint64_t)&_inte5);
		setInterrupt(0xe6, (uint64_t)&_inte6);
		setInterrupt(0xe7, (uint64_t)&_inte7);
		setInterrupt(0xe8, (uint64_t)&_inte8);
		setInterrupt(0xe9, (uint64_t)&_inte9);
		setInterrupt(0xea, (uint64_t)&_intea);
		setInterrupt(0xeb, (uint64_t)&_inteb);
		setInterrupt(0xec, (uint64_t)&_intec);
		setInterrupt(0xed, (uint64_t)&_inted);
		setInterrupt(0xee, (uint64_t)&_intee);
		setInterrupt(0xef, (uint64_t)&_intef);
		setInterrupt(0xf0, (uint64_t)&_intf0);
		setInterrupt(0xf1, (uint64_t)&_intf1);
		setInterrupt(0xf2, (uint64_t)&_intf2);
		setInterrupt(0xf3, (uint64_t)&_intf3);
		setInterrupt(0xf4, (uint64_t)&_intf4);
		setInterrupt(0xf5, (uint64_t)&_intf5);
		setInterrupt(0xf6, (uint64_t)&_intf6);
		setInterrupt(0xf7, (uint64_t)&_intf7);
		setInterrupt(0xf8, (uint64_t)&_intf8);
		setInterrupt(0xf9, (uint64_t)&_intf9);
		setInterrupt(0xfa, (uint64_t)&_intfa);
		setInterrupt(0xfb, (uint64_t)&_intfb);
		setInterrupt(0xfc, (uint64_t)&_intfc);
		setInterrupt(0xfd, (uint64_t)&_intfd);
		setInterrupt(0xfe, (uint64_t)&_intfe);
		setInterrupt(0xff, (uint64_t)&_intff);


	//masterPICmask(0x0);	//All interrupts
	masterPICmask(0xFC);	//Keyboard and timer tick
	//masterPICmask(0xFD);	//Keyboard only
	_sti();
	return 0;
}
