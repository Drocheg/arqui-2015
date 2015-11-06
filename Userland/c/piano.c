#include <piano.h>
#include <stdlib.h>
#include <usrlib.h>

void piano() {
   	while(1){
	   printf("hola");
	   int number = getchar();
		printf("%d",number);
	   if(number>=16 && number<28){
		offerNote(16-number,4,2);
	   }
	   if(number>=30 && number<42){
		offerNote(30-number,5,2);
	   }
	   if(number>=43 && number<55){
		offerNote(43-number,6,2);
	   }
	 for(int i=0; i<1000000; i++);

	}
 }