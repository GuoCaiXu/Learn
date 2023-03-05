# include "stm32f10x.h"
# include "./advance/bsp_advance.h"
# include "./uart/bsp_uart.h"


int main(void){

	DEBUG_UART_Config();
	ADVANCE_TIM_Init();

	printf("高级定时器-PWM输入捕获!\n");
	
	while(1){
		
	}
}
