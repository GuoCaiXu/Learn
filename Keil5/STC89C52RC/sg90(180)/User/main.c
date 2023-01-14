# include "stc89cxx.h"
# include "key.h"
# include "sg90.h"

void main(){

    uint8_t key = 0;
    signed char duty1 = 0;
    signed char duty2 = 0;
	
    //��ʼ����ʱ���ж�
    pwm_init(0xFE, 0x33, 40, duty1, duty2);

    while(1){

        //�жϰ����Ƿ���
        key_pick();

        //��ȡ�ĸ���������
        key = key_Judgement();
        if (key == 1){
            if (duty1 <= 3){
                duty1 += 2;
                //����ռ�ձ�
                pwm_set_duty(duty1, duty2);
            }
        }
        else if (key == 2){
            if (duty1 >= 2){
                duty1 -= 2;
                //����ռ�ձ�
                pwm_set_duty(duty1, duty2);
            }
        }
        else if (key == 3){
            if (duty2 <= 3){
                duty2 += 2;
                //����ռ�ձ�
                pwm_set_duty(duty1, duty2);
            }
        }
        else if (key == 4){
            if (duty2 >= 2){
                duty2 -= 2;
                //����ռ�ձ�
                pwm_set_duty(duty1, duty2);
            }
        }
    }
}