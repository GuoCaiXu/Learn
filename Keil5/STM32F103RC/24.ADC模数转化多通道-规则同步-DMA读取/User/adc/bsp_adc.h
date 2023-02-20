# ifndef _BSP_ADC_H
# define _BSP_ADC_H

# include "stm32f10x.h"

/*双模数时，ADC1 和 ADC2 转换的数据都存放 ADC1 的数据寄存器*/
/*ADC1 的在低16 位，ADC2 的在高16 位*/
/*双ADC模式的第一个ADC，必须是ADC1*/
# define ADCx_1                     ADC1
# define ADCx_1_APBxClock_FUN       RCC_APB2PeriphClockCmd
# define ADCx_1_CLK                 RCC_APB2Periph_ADC1

# define ADCx_1_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd
# define ADCx_1_GPIO_CLK            RCC_APB2Periph_GPIOC
# define ADCx_1_PORT                GPIOC
# define ADCx_1_PIN                 GPIO_Pin_1
# define ADCx_1_CHANNEL             ADC_Channel_11

/*双模式下第二个ADC，必须是ADC2*/
# define ADCx_2                     ADC2
# define ADCx_2_APBxClock_FUN       RCC_APB2PeriphClockCmd
# define ADCx_2_CLK                 RCC_APB2Periph_ADC2

# define ADCx_2_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd
# define ADCx_2_GPIO_CLK            RCC_APB2Periph_GPIOC
# define ADCx_2_PORT                GPIOC
# define ADCx_2_PIN                 GPIO_Pin_4
# define ADCx_2_CHANNEL             ADC_Channel_14

/*转化通道个数*/
# define NOFCHANEL                  1

/*ADC1 对应DMA1 通道1，ADC3对应DMA2 通道5，ADC2 没有DMA功能*/
# define ADC_DMA_CHANNEL            DMA1_Channel1

/******************函数声明******************/
/*ADC 初始化配置*/
void ADCx_Init(void);

# endif /*_BSP_ADC_H*/
