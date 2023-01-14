# include "./uart/bsp_uart.h"
# include "./led/bsp_led.h"
# include <stdio.h>

int putchar(int c){

    while(!(SCON & 0x02));
    SCON &= ~0x02;
    SBUF = c;
    return (c);
}

void uart_Config(void){

    TMOD = 0x20;
    SCON = 0x50;

    TH1 = 0xFD;
    SCON |= 0x02;

    ES=1;		
		EA=1;		
		TR1=1;
    EA = 1;
}

void uart() interrupt 4 
{
	uint8_t dat;

	RI = 0;			
	dat = SBUF;

  if (dat == '1'){
    LED1 = 1;
    printf("LED1 Light\r\n");
  }
  else if (dat == '2'){
    LED2 = 1;
    printf("LED2 Light\r\n");
  }
  else if (dat == '3'){
    LED3 = 1;
    printf("LED3 Light\r\n");
  }
  else if (dat == '4'){
    LED4 = 1;
    printf("LED4 Light\r\n");
  }
  else if (dat == '5'){
    LED5 = 1;
    printf("LED5 Light\r\n");
  }
  else if (dat == '6'){
    LED6 = 1;
    printf("LED6 Light\r\n");
  }
  else if (dat == '7'){
    LED7 = 1;
    printf("LED7 Light\r\n");
  }
  else if (dat == '8'){
    LED8 = 1;
    printf("LED8 Light\r\n");
  }
  else if (dat == '9'){
    P0 = 0x00;
    printf("all LED close\r\n");
  }
}