#include <piano.h>
#include <stdlib.h>
#include <usrlib.h>
#include <scanCodes.h>

void piano() {
	clearScreen();
	printf("                                 PIANO v1.0\n\n");
	while(1){
		int number = getscancode();
		if(decodeScanCode(number) == '\e') {	//Escape
			break;
		}
		if(number>=16 && number<28){
			//TODO offer notes via syscalls
			//offerNote(number-16,4,2);
		}
		if(number>=30 && number<42){
			//offerNote(number-30,5,2);
		}
		if(number>=43 && number<55){
			//offerNote(number-43,6,2);
		}
		else
		{
 			//offerNote(7,4,2); breakCodes
		}
		// for(int i=0; i<1000000; i++);
	}
	printf("\n");
}