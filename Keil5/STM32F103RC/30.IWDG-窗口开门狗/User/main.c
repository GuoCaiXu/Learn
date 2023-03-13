# include "stm32f10x.h"
# include "./key/bsp_exti_key.h"
# include "./led/bsp_led.h"
# include "./wwdg/bsp_wwdg.h"

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

	uint8_t wwdg_tr, wwdg_wr;

	/*����LED GPIO�����ر�LED*/
	LED_GPIO_Config();

	LED1_ON;
	delay(0x8fffff);

	/*��ʼ��WWDG�����ü�������ʼֵ�������ϴ���ֵ��ʹ����ǰ�����ж�*/
	IWDG_Config(0x7f, 0x5f, WWDG_Prescaler_8);

	/*����ֵ�����ڳ�ʼ����ʱ�����ó�0x5f*/
	wwdg_wr = WWDG->CFR & 0x7f;

	while(1){

		LED1_OFF;
		//-----------------------------------------------------
		// �ⲿ��Ӧ��д��Ҫ��WWDG��صĳ�����γ������е�ʱ��
		// �����˴���ֵӦ�����óɶ��
		//-----------------------------------------------------
		
		// ��ʱ��ֵ����ʼ�������0X7F��������WWDGʱ�����ֵ�᲻�ϼ�С
		// ����������ֵ���ڴ���ֵʱι���Ļ����Ḵλ�������������ٵ�0X40
		// ��û��ι���Ļ��ͷǳ��ǳ�Σ���ˣ��������ټ�һ�ε���0X3Fʱ�͸�λ
		// ����Ҫ����������ֵ�ڴ���ֵ��0X40֮���ʱ��ι��������0X40�ǹ̶��ġ�
		wwdg_tr = WWDG->CR & 0x7f;

		if (wwdg_tr < wwdg_wr){
			/*ι�����������ü�������ֵ���0x7f		��ι���ͻ�һֱ��λ*/
			WWDG_Feed();
		}
	}
}
