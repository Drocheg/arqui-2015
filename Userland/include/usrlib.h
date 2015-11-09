#ifndef USRLIB_H
#define USRLIB_H

#include <stdint.h>
#include <vargs.h>

void fread(uint8_t fd, char *buff, uint64_t maxBytes);

void fwrite(uint8_t fd, char *buff, uint64_t maxBytes);

void putchar(char c);

char getchar();

uint8_t getscancode();

void printf(const char *format, ...);

void scroll();

void clearScreen();

void reboot();

//void scanf(char format, char *buff); Incomplete

void printf2(const char *format, vargs *args);

#endif