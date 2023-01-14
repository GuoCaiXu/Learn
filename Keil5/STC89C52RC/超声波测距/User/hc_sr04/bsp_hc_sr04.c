# include "./hc_sr04/bsp_hc_sr04.h"
# include <stdio.h>
# include "intrins.h"

int putchar(int c){

    while(!(SCON & 0x02));
    SCON &= ~0x02;
    SBUF = c;
    return (c);
}

void  trigger(void) 		         //启动模块
  {
    TRIG = 0;
    TRIG = 1;			                     //启动一次模块
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    _nop_(); 
    TRIG = 0;
  }

void calc(void){

    uint16_t duration, distance;
    duration = TH0 * 256 + TL0;
    duration *= 12/11.0592;

    distance = duration * 0.017;
	printf("距离: %d cm\n", distance);
    TH0 = 0;
    TL0 = 0;
}

void setup(void){

    TMOD = 0x21;
    SCON = 0x40;

    TH1 = 0xFD;
    TCON |= 0x40;
    SCON |= 0x02;

    TH0 = 0;
    TL0 = 0;
    ET0 = 1;
    EA = 1;
}

void loop(void){

    trigger();
    while(!ECHO);
    TR0 = 1;
    while(ECHO);
    TR0 = 0;
    calc();
    delay_1ms(10);
}