# include "stm32f10x.h"
# include "./uart/bsp_uart.h"
# include "./adc/bsp_adc.h"

extern uint16_t ADC_ConvertedValue;
/*全局变量，用于保存转化计算后的电压值*/
double ADC_ConvertedValueLocal;

/**
 *  @brief  软件延时
 *  @param  nCount: 延时几个10us
 *  @retval 无
 */
void Delay(uint32_t nCount){
    for (; nCount != 0; nCount --);
}

int main(void){

    DEBUG_UART_Config();
    ADCx_Init();

    printf("\r\nADC模数转换实验!\r\n");

    while(1){

        ADC_ConvertedValueLocal = (float)ADC_ConvertedValue/4096*3.3;

        printf("\r\nADC_ConvertedValue = %d\r\n", ADC_ConvertedValue);
        printf("\r\n测量的电压值：%f V\r\n", ADC_ConvertedValueLocal);
        Delay(0xffffee);
    }
}
