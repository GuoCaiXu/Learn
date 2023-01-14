# ifndef _BSP_PWM_H
# define _BSP_PWM_H

# include "reg52.h"

# define u8 unsigned char
# define u16 unsigned int

//1ms 延迟函数
void delay_ms(u8 z);

//pwm 初始化
void pwm_init(u8 tim_h, u8 tim_l, u8 tim_scale, u8 duty);

//传入占空比
void pwm_set_duty_cycle(u8 duty);

# endif