include Makefile.inc

KERNEL=kernel.bin
SOURCES=$(wildcard c/*.c)
SOURCES_ASM=$(wildcard asm/*.asm)
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)
OBJECTS_COMMON=$(wildcard ../Common/c/*.o)
OBJECTS_ASM_COMMON=$(wildcard ../Common/asm/*.o)
LOADERSRC=loader.asm

LOADEROBJECT=$(LOADERSRC:.asm=.o)
STATICLIBS=

USERLAND=$(wildcard ../Userland/c/*.o)
#TODO remove this ^ and include of Userland on line 24

all: $(KERNEL)

$(KERNEL): $(LOADEROBJECT) $(COMMON) $(OBJECTS) $(STATICLIBS) $(OBJECTS_ASM)
	$(LD) $(LDFLAGS) -T kernel.ld -o $(KERNEL) $(LOADEROBJECT) $(OBJECTS_COMMON) $(OBJECTS_ASM_COMMON) $(OBJECTS) $(OBJECTS_ASM) $(STATICLIBS) $(USERLAND)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -I../Common/include -I../Userland/include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

$(LOADEROBJECT):
	$(ASM) $(ASMFLAGS) $(LOADERSRC) -o $(LOADEROBJECT)

clean:
	rm -rf asm/*.o c/*.o *.o *.bin

.PHONY: all clean