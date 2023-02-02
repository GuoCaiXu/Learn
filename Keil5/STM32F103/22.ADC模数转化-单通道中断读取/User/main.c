# include "stm32f10x.h"
# include "./uart/bsp_uart.h"
# include "./adc/bsp_adc.h"

extern uint16_t ADC_ConvertedValue;
/*ȫ�ֱ��������ڱ���ת�������ĵ�ѹֵ*/
double ADC_ConvertedValueLocal;

/**
 *  @brief  �����ʱ
 *  @param  nCount: ��ʱ����10us
 *  @retval ��
 */
void Delay(uint32_t nCount){
    for (; nCount != 0; nCount --);
}

int main(void){

    DEBUG_UART_Config();
    ADCx_Init();

    printf("\r\nADCģ��ת��ʵ��!\r\n");

    while(1){

        ADC_ConvertedValueLocal = (float)ADC_ConvertedValue/4096*3.3;

        printf("\r\nADC_ConvertedValue = %d\r\n", ADC_ConvertedValue);
        printf("\r\n�����ĵ�ѹֵ��%f V\r\n", ADC_ConvertedValueLocal);
        Delay(0xffffee);
    }
}
