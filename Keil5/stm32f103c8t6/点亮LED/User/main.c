# include "stm32f10x.h"
# include "./led/bsp_led.h" 

//软件延时函数
void delay(uint32_t count){

	while(count --);
}

int main(void){

	LED_GPIO_Config();
	
	while(1){

		//设置一个位
		GPIO_SetBits(LED_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);
		//复位一个位
		GPIO_ResetBits(LED_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);

		//设置一个位
		GPIO_SetBits(LED_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);
		//复位一个位
		GPIO_ResetBits(LED_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);

		//设置一个位
		GPIO_SetBits(LED_GPIO_PORT, LED3_GPIO_PIN);
		delay(0xfffff);
		//复位一个位
		GPIO_ResetBits(LED_GPIO_PORT, LED3_GPIO_PIN);
		delay(0xfffff);
	}
}
