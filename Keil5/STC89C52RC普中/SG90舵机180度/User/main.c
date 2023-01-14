# include "public.h"
# include "key.h"
# include "sg90.h"

void main(){

    u8 key = 0;
    signed char duty = 0;
	
    //初始化定时器中断
    pwm_init(0xFE, 0x33, 40, duty);

    while(1){

        //判断按键是否按下
        key_pick();

        //获取哪个按键按下
        key = key_Judgement();
        if (key == 1){
            if (duty <= 3){
                duty ++;
                //更新占空比
                pwm_set_duty(duty);
            }
        }
        else if (key == 2){
            if (duty >= 1){
                duty --;
                //更新占空比
                pwm_set_duty(duty);
            }
        }
    }
}