# include "stm32f10x.h"
# include "./basetime/bsp_basetime.h"
# include "./led/bsp_led.h"

volatile uint32_t time = 0;		//ms 计时变量

int main(void){

	BASIC_TIM_Init();
	LED_GPIO_Config();
	
	LED1_TOGGLE;
	while(1){

		if (time == 500){
			time = 0;
			/*LED1 反转*/
			LED1_TOGGLE;
			LED2_TOGGLE
		}
	}
}
