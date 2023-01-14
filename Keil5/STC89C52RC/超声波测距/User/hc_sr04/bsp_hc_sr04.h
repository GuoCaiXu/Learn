# ifndef _BSP_HC_SR04_H
# define _BSP_HC_SR04_H

# include "stc89cxx.h"

sbit TRIG = P2^2;
sbit ECHO = P2^3;

void setup(void);
void loop(void);

# endif