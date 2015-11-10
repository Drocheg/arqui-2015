#include <songplayer.h>
#include <usrlib.h>
#include <fileDescriptors.h>

#include <vargs.h>	//TODO delete

/*
FORMATO DE CANCIONES:

(32 bits) cantidad de notas = n
	n veces:
		(16 bits) frecuencia
		(8 bits) tiempo

ejemplo:     cant=2             |f1              |t1       |f2              |t2
00000000000000000000000000000010 0000000100000101 00001010 0000001000001011 00001010
*/


void playSong() {
	char *buff = (char *)0x500000;		//TODO tidy up
	int32_t n = (int32_t) *buff;
	
	//TODO delete
	vargs a = {1, (void *[1]) {buff+4}};
	printf2("Playing %ui notes:\n", &a);

	char *data = (char *)(buff+4);	//Skip bytes for n
	uint16_t freq;
	uint8_t time;
	while(n > 0) {
		freq = *((uint16_t *)data);
		data = data+2;
		time = *((uint8_t *)data);
		data = data+1;
		fwrite(SPEAKER,(char *)freq, time);
	  	//offerSound(freq, time);	TODO Use syscalls done? see previous line
	  	n--;
	}
}