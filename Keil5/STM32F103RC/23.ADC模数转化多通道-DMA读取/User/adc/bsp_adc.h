# ifndef _BSP_ADC_H
# define _BSP_ADC_H

# include "stm32f10x.h"

/*ADC1 输入通道(引脚)配置*/
# define ADC_APBxClock_FUN          RCC_APB2PeriphClockCmd
# define ADC_CLK                    RCC_APB2Periph_ADC1

/*ADC GPIO宏定义*/
/*注意：用作ADC采集的IO必须没有复用，否则采集电压会有影响*/
# define ADC_GPIO_APBxClock_FUN     RCC_APB2PeriphClockCmd
# define ADC_GPIO_CLK               RCC_APB2Periph_GPIOC
# define ADC_PORT                   GPIOC

/*转化通道个数*/
# define NOFCHANEL                  6

# define ADC_PIN1                   GPIO_Pin_0
# define ADC_CHANNEL1               ADC_Channel_10

# define ADC_PIN2                   GPIO_Pin_1
# define ADC_CHANNEL2               ADC_Channel_11

# define ADC_PIN3                   GPIO_Pin_2
# define ADC_CHANNEL3               ADC_Channel_12

# define ADC_PIN4                   GPIO_Pin_3
# define ADC_CHANNEL4               ADC_Channel_13

# define ADC_PIN5                   GPIO_Pin_4
# define ADC_CHANNEL5               ADC_Channel_14

# define ADC_PIN6                   GPIO_Pin_5
# define ADC_CHANNEL6               ADC_Channel_15

/*ADC1 对应DMA1 通道1，ADC3对应DMA2 通道5，ADC2 没有DMA功能*/
# define DMA_APBxClock_FUN          RCC_AHBPeriphClockCmd
# define ADC_x                      ADC1
# define ADC_DMA_CHANNEL            DMA1_Channel1
# define ADC_DMA_CLK                RCC_AHBPeriph_DMA1

/******************函数声明******************/
/*ADC 初始化配置*/
void ADCx_Init(void);

# endif /*_BSP_ADC_H*/
