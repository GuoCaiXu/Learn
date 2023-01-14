# include "stc89cxx.h"
# include "./led/bsp_led.h"
# include "./uart/bsp_uart.h"
# include <stdio.h>

void main(void){

	uart_Config();
	
	printf("Welcome to use\r\n");
	P0 = 0x00;
	while(1){
	}
}
