# include "stm32f10x.h"
# include "./uart/bsp_uart.h"
# include "./adc/bsp_adc.h"

extern uint32_t ADC_ConvertedValue[NOFCHANEL];
float ADC_ConvertedValueLocal[NOFCHANEL*2];

/**
 *  @brief  延时函数
 *  @param  nCount: 延时几个10us
 *  @retval 无
 */

void Delay(uint32_t nCount){
    for (; nCount > 0; nCount --);
}

int main(){

    uint16_t temp0 = 0, temp1 = 0;

    DEBUG_UART_Config();

    ADCx_Init();

    printf("\r\nADC规则同步采集实验!\r\n");

    while(1){

        temp0 = (ADC_ConvertedValue[0]&0xFFFF0000) >> 16;
        temp1 = (ADC_ConvertedValue[0]&0xFFFF);

        ADC_ConvertedValueLocal[1] = (float) temp0/4096*3.3;
        ADC_ConvertedValueLocal[0] = (float) temp1/4096*3.3;

        printf("\r\nADCx_1 value = %f V\r\n", ADC_ConvertedValueLocal[0]);
        printf("\r\nADCx_2 value = %f V\r\n", ADC_ConvertedValueLocal[1]);

        Delay(0xffffff);
    }
}
