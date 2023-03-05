# include "stm32f10x.h"
# include "./generamtim/bsp_generamtim.h"
# include "./uart/bsp_uart.h"


int main(void){

	DEBUG_UART_Config();
	GENERAL_TIM_Init();

	printf("通用定时器-四路PWM输出实验!");
	
	while(1){
		
	}
}
