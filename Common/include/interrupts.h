#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

/* TODO
IMPORTANTE! Las primeras 32 interrupciones están reservadas para excepciones,
por lo que las nuestras empiezan a partir de index = 32 (0-31 reservadas).

int 0x20 = timer tick
int 0x21 = teclado
etc.

if(int >= 32 && int <= 47) => IRQ hardware interrupt
*/

void _int20();
void _int21();
void _int80(uint64_t syscallID, int64_t p1, int64_t p2, int64_t p3);

#endif