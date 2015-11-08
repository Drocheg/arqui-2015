/*
FORMATO DE CANCIONES:

(32 bits) cantidad de notas = n
	n veces:
		(16 bits) frecuencia
		(8 bits) tiempo

ejemplo:     cant=2             |f1              |t1       |f2              |t2     
00000000000000000000000000000010 0000000100000101 00001010 0000001000001011 00001010
*/

#include <stdint.h>
#include <stdio.h>

#pragma pack(push)
#pragma pack (1) 		/* Alinear a 1 byte */
typedef struct
{
	uint16_t freq;
	uint8_t duration;
} note;
#pragma pack(pop)

int main(int argc, char *argv[]) {
	FILE *f;
	char *fname = "song1.bin";
	f = fopen(fname,"wb");  //(w)rite (b)inary
	
	note notes[] = {
		{261, 20},
		{523, 20}
	};
	uint32_t n = sizeof(notes) / sizeof(note);

	printf("Writing %d notes:\n", n);
	int i;
	for(i = 0; i < n; i++) {
		printf("%x ", notes[i].freq);
		printf("%x\n", notes[i].duration);
	}

	//Write
	fwrite(&n, 4, 1, f);
	for(i = 0; i < n; i++) {
		fwrite(&(notes[i].freq), 2, 1, f);
		fwrite(&(notes[i].duration), 1, 1, f);
	}
	fclose(f);
	printf("Song write complete. File is %s", fname);

	printf("\n");
	return 0;
}