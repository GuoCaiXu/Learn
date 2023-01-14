# include "bsp_pwm.h"

void main(){

    u8 dir = 0;
    signed char duty = 0;

    pwm_init(0xff, 0xf6, 100, 0);

    while(1){
        if (dir == 0){
            duty ++;
            if (duty == 50) dir = 1;
        }
        else {
            duty --;
            if (duty == 0) dir = 0;
        }

        delay_ms(1);
        pwm_set_duty_cycle(duty);
    }
}