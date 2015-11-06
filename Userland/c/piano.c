#include <piano.h>
#include <stdlib.h>
#include <usrlib.h>
#include <scanCodes.h>

void piano() {
	clearScreen();
	while(1){
		int number = getchar();
		if(getCharFromScanCode(number) == '\e') {	//Escape
			break;
		}
		if(number>=16 && number<28){
			offerNote(number-16,4,2);
		}
		if(number>=30 && number<42){
			offerNote(number-30,5,2);
		}
		if(number>=43 && number<55){
			offerNote(number-43,6,2);
		}
		else
		{
 			//offerNote(7,4,2); breakCodes
		}
		// for(int i=0; i<1000000; i++);
	}
	printf("\n");
}