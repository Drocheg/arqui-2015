include Makefile.inc

SOURCES=$(wildcard c/*.c)
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS) codeModule dataModule

codeModule:
	cd CodeModule; make

dataModule:
	cd Songmaker; make
	#printf "This is sample data." >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -I../Common/include -c $< -o $@

clean:
	cd CodeModule; make clean
	rm -rf c/*.o *.o *.bin

.PHONY: all clean