# include "stm32f10x.h"
# include "./oled/OLED.h"
# include "./exti/bsp_exit.h"

uint16_t ADValue;
float Voltage;

/**
 *  @brief  ��ʱ����
 *  @param  ��
 *  @retval ��
*/
void delay(uint32_t z){

	while(z --);
}

/**
 *  @brief  ������
 *  @param  ��
 *  @retval ��
 */
int main(void){

	OLED_Init();

	while(1){


	}
}
