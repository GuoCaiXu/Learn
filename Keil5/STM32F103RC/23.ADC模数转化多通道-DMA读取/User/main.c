# include "stm32f10x.h"
# include "./uart/bsp_uart.h"
# include "./adc/bsp_adc.h"

extern uint16_t ADC_ConvertedValue[NOFCHANEL];
float ADC_ConvertedValueLocal[NOFCHANEL];

/**
 *  @brief  ��ʱ����
 *  @param  nCount: ��ʱ����10us
 *  @retval ��
 */

void Delay(uint32_t nCount){
    for (; nCount > 0; nCount --);
}

int main(){

    DEBUG_UART_Config();

    ADCx_Init();

    printf("\r\nADC ��ģת��-��ͨ��DMA��ȡʵ��!\r\n");

    while(1){
        int i = 0;
        for (i = 0; i < NOFCHANEL; i ++){

            ADC_ConvertedValueLocal[i] = (float)ADC_ConvertedValue[i]/4096*3.3;
            printf("NOFCHANEL[%d] = %f\n", i, ADC_ConvertedValueLocal[i]);
        }
        printf("\r\n");
        Delay(0xffffff);
    }
}
