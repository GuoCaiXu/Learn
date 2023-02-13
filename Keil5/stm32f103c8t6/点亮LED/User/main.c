# include "stm32f10x.h"
# include "./led/bsp_led.h" 

//�����ʱ����
void delay(uint32_t count){

	while(count --);
}

int main(void){

	LED_GPIO_Config();
	
	while(1){

		//����һ��λ
		GPIO_SetBits(LED_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);
		//��λһ��λ
		GPIO_ResetBits(LED_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);

		//����һ��λ
		GPIO_SetBits(LED_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);
		//��λһ��λ
		GPIO_ResetBits(LED_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);

		//����һ��λ
		GPIO_SetBits(LED_GPIO_PORT, LED3_GPIO_PIN);
		delay(0xfffff);
		//��λһ��λ
		GPIO_ResetBits(LED_GPIO_PORT, LED3_GPIO_PIN);
		delay(0xfffff);
	}
}
