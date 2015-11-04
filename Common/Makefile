include Makefile.inc

SAMPLE_DATA=0001-sampleDataModule.bin
SOURCES=$(wildcard c/*.c)
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

clean:
	cd SampleCodeModule; make clean
	rm -rf c/*.o


.PHONY: sampleCodeModule all clean
