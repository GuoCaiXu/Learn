# include "sg90.h"
# include "key.h"

//初始化中断时间，周期，占空比
uint8_t gtim_h = 0;
uint8_t gtim_l = 0;
uint8_t gtim_scale = 0;
signed char gduty1 = 0;
signed char gduty2 = 0;

//PWM 初始化
void pwm_init(uint8_t tim_h, uint8_t tim_l, uint8_t tim_scale, signed char duty1, signed char duty2){

    //初始化中断时间，周期，占空比
    gtim_h = tim_h;
    gtim_l = tim_l;
    gtim_scale = tim_scale;
    gduty1 = duty1;
    gduty2 = duty2;

    //定时器T0 工作模式M1
    TMOD = 0x01;

    //设置中断时间
    TH0 = gtim_h;
    TL0 = gtim_l;

    //中断定时器T0 开启
    ET0 = 1;

    //总中断开启
    EA = 1;

    //定时器T0 开启
    TR0 = 1;
}

//更新占空比
void pwm_set_duty(uint8_t duty1, uint8_t duty2){
    gduty1 = duty1;
    gduty2 = duty2;
}

//中断函数
void pwm() interrupt 1{

    static uint8_t time = 0;

    TH0 = gtim_h;
    TL0 = gtim_l;

    time++;

    if (time >= gtim_scale) time = 0;

    if (time <= gduty1) PWM1 = 1;
    else PWM1 = 0;

    if (time <= gduty2) PWM2 = 1;
    else PWM2 = 0;
}
