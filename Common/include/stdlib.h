#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>

uint32_t intToStr(uint64_t value, char * buffer);

uint32_t intToStrBase(uint64_t value, char * buffer, uint32_t base);

int32_t strcmp(const char *s1, const char *s2);

uint8_t streql(const char *s1, const char *s2);

uint32_t strlen(const char *s);

int32_t indexOf(const char *needle, const char *haystack);

char * toUpperStr(char *s);

char * toLowerStr(char *s);

char toUpperChar(char s);

char toLowerChar(char s);

#endif