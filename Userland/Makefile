include Makefile.inc

SAMPLE_DATA=0001-sampleDataModule.bin
SOURCES=$(wildcard c/*.c)
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS) sampleCodeModule sampleDataModule

sampleCodeModule:
	cd SampleCodeModule; make

sampleDataModule:
	printf "This is sample data." >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -I../Common/include -c $< -o $@

clean:
	cd SampleCodeModule; make clean
	rm -rf c/*.o *.o *.bin

.PHONY: all clean