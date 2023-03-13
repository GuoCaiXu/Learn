# include "stm32f10x.h"
# include "./oled/OLED.h"
# include "./exti/bsp_exit.h"

uint16_t ADValue;
float Voltage;

/**
 *  @brief  延时函数
 *  @param  无
 *  @retval 无
*/
void delay(uint32_t z){

	while(z --);
}

/**
 *  @brief  主函数
 *  @param  无
 *  @retval 无
 */
int main(void){

	OLED_Init();

	while(1){


	}
}
