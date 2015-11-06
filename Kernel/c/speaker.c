#include <speaker.h>
#include <libasm.h>

#include <video.h>

static uint32_t soundQueue[SOUND_BUFF_SIZE] = {0};
static uint32_t soundTimeQueue[SOUND_BUFF_SIZE] = {0};
static int soundRIndex = -1, soundWIndex = 0;
static int sonidos[][8] = {{16,33,65,131,262,523,1046,2093},{17,35,69,139,277,554,1109,2217},{18,37,73,147,294,587,1175,2349},{19,39,78,155,311,622,1244,2489},{21,41,82,165,330,659,1328,2637},{22,44,87,175,349,698,1397,2794},{23,46,92,185,370,740,1480,2960},{24,49,98,196,392,784,1568,3136},{26,52,04,208,415,831,1661,3322},{27,55,10,220,440,880,1760,3520},{29,58,16,233,466,932,1865,3729},{31,62,23,245,494,988,1975,3951}};

//TODO consider cases when one index is around the border from the other (i.e. 0 vs 255)
uint8_t noSound() {
  	/*
  	ncPrint(" Rindex: ");
  	ncPrintDec(soundRIndex);
  	ncPrint(" Windex: ");
  	ncPrintDec(soundWIndex);
	*/
	  return soundRIndex == soundWIndex-1 || (soundRIndex == 0 && soundWIndex == SOUND_BUFF_SIZE-1) || (soundWIndex == 0 && soundRIndex == SOUND_BUFF_SIZE-1);
}

uint8_t soundBufferIsFull() {
	return soundRIndex == soundWIndex;
}

uint8_t offerSound(uint32_t sound, uint32_t time) {
	if(soundBufferIsFull()) {
	  	ncPrint("sFull");
		return 0;
	}
	if(soundWIndex == SOUND_BUFF_SIZE) { //No sera maximo-1???
		soundWIndex = 0;
	}
	soundTimeQueue[soundWIndex] = time;
	soundQueue[soundWIndex++] = sound; //aumentar antes o despues?

	return 1;
}

void decreaseTimer(){
	if(soundRIndex==soundWIndex) ncPrint("No se deberia decreaseTimer si esta vacio el buffer");
	playSound(soundQueue[soundRIndex+1]);
  	soundTimeQueue[soundRIndex+1]--;
  	if(soundTimeQueue[soundRIndex+1]<=0){
	  	soundRIndex++;
		 if(soundRIndex == SOUND_BUFF_SIZE) {
			soundRIndex = 0;
		}
		/*
		if(!noSound()){
			playSound(soundQueue[soundRIndex]);
		}
		*/
	}

}

void offerNote(uint8_t note, uint8_t octave, uint32_t time){
  	ncPrintDec(note);
  	ncPrintDec(octave);
  	ncPrint(" : ");
	  uint32_t nFrequence = sonidos[note][octave];
	ncPrintDec(nFrequence);
  	ncPrint(" ");
  	offerSound(nFrequence,time);
}


void playSound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;

    //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8_t) (Div) );
 	outb(0x42, (uint8_t) (Div >> 8));

    //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }

//make it shutup
void soundOff() {
 	uint8_t tmp = inb(0x61) & 0xFC;
 	outb(0x61, tmp);
 }

//Make a beep
void beep() {
 	 playSound(1000);
 	// timer_wait(10);
	for(int i=0; i<10000000; i++);
	soundOff();
        //set_PIT_2(old_frequency);
 }