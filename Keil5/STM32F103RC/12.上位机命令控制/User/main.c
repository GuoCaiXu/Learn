# include "stm32f10x.h"
# include "./led/bsp_led.h"
# include "./uart/bsp_uart.h"
# include "stdio.h"

int main(void){

		uint8_t temp;

    LED_GPIO_Config();
    DEBUG_UART_Config();
		
		printf("开灯小程序!\r\n");
		printf("发送1 开LED1， 发送2 开LED2\n");
	
		//printf->fputc->USART_SendData->   
		LED1_OFF;
		LED2_OFF;
    while(1){
      temp = getchar();
      if (temp == '1'){
				printf("接收到的命令为：%c, 开启LED1 小灯!\n", temp);
			}
			else if (temp == '2'){
			
				printf("接收到的命令为：%c, 开启LED2 小灯!\n", temp);
			}
			else {
				printf("接收到的命令为：%c, 关闭小灯!\n", temp);
			}
			
			switch(temp){
				case '1' : 
        LED1_ON; 
        LED2_OFF; 
        break;
				
        case '2' : 
        LED2_ON; 
        LED1_OFF; 
        break;
				
        default: 
				LED2_OFF; 
        LED1_OFF;
        break;
			}
    }
}
