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
uint32_t _int80(uint32_t syscallID, uint32_t p1, uint32_t p2, uint32_t p3);

#endif