# include "stm32f10x.h"
# include "./generamtim/bsp_generamtim.h"
# include "./uart/bsp_uart.h"


int main(void){

	DEBUG_UART_Config();
	GENERAL_TIM_Init();

	printf("ͨ�ö�ʱ��-��·PWM���ʵ��!");
	
	while(1){
		
	}
}
