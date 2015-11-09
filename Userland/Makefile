include Makefile.inc

SOURCES=$(wildcard c/*.c)
OBJECTS=$(SOURCES:.c=.o) $(wildcard ../Common/c/*.o)

all: $(OBJECTS) codeModule dataModule

codeModule:
	cd CodeModule; make

dataModule:
	cd Songmaker; make

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -I../Common/include -c $< -o $@

clean:
	cd CodeModule; make clean
	rm -rf c/*.o *.o *.bin

.PHONY: all clean