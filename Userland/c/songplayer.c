#include <songplayer.h>
#include <usrlib.h>
#include <fileDescriptors.h>

/*
FORMATO DE CANCIONES:

(32 bits) cantidad de notas = n
	n veces:
		(16 bits) frecuencia
		(8 bits) tiempo

ejemplo:     cant=2             |f1              |t1       |f2              |t2     
00000000000000000000000000000010 0000000100000101 00001010 0000001000001011 00001010
*/

#include "../../Kernel/include/speaker.h"	//TODO remove, use syscalls
#include "../../Kernel/include/video.h"	//TODO remove, fix freaking printf
void playSong() {
	char buff[1000];	//TODO allow to read until end of file rather than fixed-size buffer
	fread(DATA_MODULE, buff, sizeof(buff));
	int32_t n = (int32_t) *buff;

	printf("Playing ");
	ncPrintDec(n);		//TODO Printf escribe cualquier cosa, arreglar
	printf(" notes: ");

	char *data = (char *)(buff+4);	//Skip bytes for n
	uint16_t freq;
	uint8_t time;
	while(n >= 0) {
		freq = (uint16_t) *data;
		data = data+2;
		time = (uint8_t) *data;
		data = data+1;
		offerNote(freq, 4, time);
		n--;
	}
}