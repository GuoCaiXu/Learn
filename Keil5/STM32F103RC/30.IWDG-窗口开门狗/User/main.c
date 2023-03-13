# include "stm32f10x.h"
# include "./key/bsp_exti_key.h"
# include "./led/bsp_led.h"
# include "./wwdg/bsp_wwdg.h"

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

	uint8_t wwdg_tr, wwdg_wr;

	/*配置LED GPIO，并关闭LED*/
	LED_GPIO_Config();

	LED1_ON;
	delay(0x8fffff);

	/*初始化WWDG：配置计数器初始值，配置上窗口值，使能提前唤醒中断*/
	IWDG_Config(0x7f, 0x5f, WWDG_Prescaler_8);

	/*窗口值我们在初始化的时候设置成0x5f*/
	wwdg_wr = WWDG->CFR & 0x7f;

	while(1){

		LED1_OFF;
		//-----------------------------------------------------
		// 这部分应该写需要被WWDG监控的程序，这段程序运行的时间
		// 决定了窗口值应该设置成多大。
		//-----------------------------------------------------
		
		// 计时器值，初始化成最大0X7F，当开启WWDG时候，这个值会不断减小
		// 当计数器的值大于窗口值时喂狗的话，会复位，当计数器减少到0X40
		// 还没有喂狗的话就非常非常危险了，计数器再减一次到了0X3F时就复位
		// 所以要当计数器的值在窗口值和0X40之间的时候喂狗，其中0X40是固定的。
		wwdg_tr = WWDG->CR & 0x7f;

		if (wwdg_tr < wwdg_wr){
			/*喂狗，重新设置计数器的值最大0x7f		不喂狗就会一直复位*/
			WWDG_Feed();
		}
	}
}
