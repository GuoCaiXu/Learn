# ifndef _sg90_H
# define _sg90_H

# include "stc89cxx.h"

//PWM 引脚
sbit PWM1 = P2^1;
sbit PWM2 = P2^2;

//PWM 初始�?
void pwm_init(uint8_t tim_h, uint8_t tim_l, uint8_t tim_scale, signed char duty1, signed char duty2);

//更新占空�?
void pwm_set_duty(uint8_t duty1, uint8_t duty2);

# endif
