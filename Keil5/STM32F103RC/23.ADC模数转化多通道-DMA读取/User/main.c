# include "stm32f10x.h"
# include "./uart/bsp_uart.h"
# include "./adc/bsp_adc.h"

extern uint16_t ADC_ConvertedValue[NOFCHANEL];
float ADC_ConvertedValueLocal[NOFCHANEL];

/**
 *  @brief  延时函数
 *  @param  nCount: 延时几个10us
 *  @retval 无
 */

void Delay(uint32_t nCount){
    for (; nCount > 0; nCount --);
}

int main(){

    DEBUG_UART_Config();

    ADCx_Init();

    printf("\r\nADC 数模转化-多通道DMA读取实验!\r\n");

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
