# ifndef _key_H
# define _key_H

# include "stc89cxx.h"

sbit KEY1 = P3^2;
sbit KEY2 = P3^3;
sbit KEY3 = P3^4;
sbit KEY4 = P3^5;

//判断按键是否按下
uint8_t key_Judgement();

void key_pick();

# endif
