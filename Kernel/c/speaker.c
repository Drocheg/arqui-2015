#include <speaker.h>
#include <libasm.h>

#include <video.h>

static uint32_t soundQueue[SOUND_BUFF_SIZE] = {0};
static uint32_t soundTimeQueue[SOUND_BUFF_SIZE] = {0};
static int soundRIndex = 0, soundWIndex = 0;

uint8_t noSound() {

	return soundRIndex == soundWIndex ;
}

uint8_t soundBufferIsFull() {
	return soundRIndex == soundWIndex+1 || (soundRIndex == 0 && soundWIndex == SOUND_BUFF_SIZE-1);
}

uint8_t offerSound(uint32_t sound, uint32_t time) {
	if(soundBufferIsFull()) {
		ncPrint("sFull");
		return 0;
	}
	soundTimeQueue[soundWIndex] = time+1;
	soundQueue[soundWIndex++] = sound;
	if(soundWIndex == SOUND_BUFF_SIZE) {
		soundWIndex = 0;
	}
	return 1;
}

void decreaseTimer() {
	if(noSound()) return;
	playSound(soundQueue[soundRIndex]);
	soundTimeQueue[soundRIndex]--;
	if(soundTimeQueue[soundRIndex]<=0){
		soundRIndex++;
		if(soundRIndex == SOUND_BUFF_SIZE) {
			soundRIndex = 0;
		}
	}
}

void playSound(uint32_t nFrequence) { //http://wiki.osdev.org/PC_Speaker
	uint32_t Div;
	uint8_t tmp;
	if(nFrequence){

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
	}else{
		soundOff();
	}
}

//make it shutup
void soundOff() {
	uint8_t tmp = inb(0x61) & 0xFC;
	outb(0x61, tmp);
}

