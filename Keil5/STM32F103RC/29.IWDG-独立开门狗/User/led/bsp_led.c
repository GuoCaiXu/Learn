# include "./led/bsp_led.h"

/**
 *  @brief  LEDС��GPIO��ʼ��
 *  @param  ��
 *  @retval ��
 */
void LED_GPIO_Config(void){

    GPIO_InitTypeDef    GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);

	/*����LED1*/
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);

	/*����LED2*/
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
}
