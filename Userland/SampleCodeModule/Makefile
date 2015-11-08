include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard *.c)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld $(SOURCES) -I../include -I../../Common/include  -o ../$(MODULE)

clean:
	rm -rf *.o

.PHONY: all clean
