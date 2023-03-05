# ifndef _BSP_ADVANCE_H
# define _BSP_ADVANCE_H

# include "stm32f10x.h"

/*********ͨ�ö�ʱ��TIM�������壬ֻ��TIM1��TIM8*********/
/*��ʹ�ò�ͬ��ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ����, ���Ҫע��*/
/*��������Ĭ��ʹ��TIM1*/


# define ADVANCE_TIM                    TIM3
# define ADVANCE_TIM_APBxClock_FUN      RCC_APB2PeriphClockCmd
# define ADVANCE_TIM_CLK                RCC_APB2Periph_TIM1
/*���PWMƵ��Ϊ 72M     (ARR+1)*(PSC+1)*/
# define ADVANCE_TIM_PERIOD             (1000-1)
# define ADVANCE_TIM_PSC                (72-1)

/*�ж���غ궨��*/
# define ADVANCE_TIM_IRQ                TIM1_CC_IRQn
# define ADVANCE_TIM_IRQHandler         TIM1_CC_IRQHandler

/*TIM1 ���벶��ͨ��1*/
# define ADVANCE_TIM_CH1_GPIO_CLK       RCC_APB2Periph_GPIOA
# define ADVANCE_TIM_CH1_PORT           GPIOA
# define ADVANCE_TIM_CH1_PIN            GPIO_Pin_8

# define ADVANCE_TIM_IC1PWM_CHANNEL     TIM_Channel_1
// # define ADVANCE_TIM_IC2PWM_CHANNEL     TIM_Channel_2

/***********��������***********/
void ADVANCE_TIM_Init(void);

# endif /*_BSP_ADVANCE_H*/
