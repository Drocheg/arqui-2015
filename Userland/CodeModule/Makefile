include ../Makefile.inc

MODULE=codeModule.bin
SOURCES=$(wildcard *.c) $(wildcard ../c/*.c) $(wildcard ../../Common/c/*.c)

all: 
	$(GCC) $(GCCFLAGS) -T codeModule.ld $(SOURCES) $(OBECTS) -I../include -I../../Common/include -o $(MODULE)

clean:
	rm -rf *.o

.PHONY: all clean
