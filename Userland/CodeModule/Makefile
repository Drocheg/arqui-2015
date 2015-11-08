include ../Makefile.inc

MODULE=codeModule.bin
SOURCES=$(wildcard *.c)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T codeModule.ld $(SOURCES) -I../include -I../../Common/include  -o $(MODULE)

clean:
	rm -rf *.o

.PHONY: all clean
