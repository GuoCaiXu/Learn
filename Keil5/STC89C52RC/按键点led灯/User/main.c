#include "reg52.h"
# define uint unsigned int
# define uchar unsigned char
# define ulong unsigned long

sbit Key1 = P0^4;
sbit Key2 = P0^5;
sbit Key3 = P0^6;
sbit Key4 = P0^7;

//??
sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit LED4 = P0^3;

void main(){


    while(1){
        LED1 = ~Key1;
        LED2 = ~Key2;
        LED3 = ~Key3;
        LED4 = ~Key4;
    }
}