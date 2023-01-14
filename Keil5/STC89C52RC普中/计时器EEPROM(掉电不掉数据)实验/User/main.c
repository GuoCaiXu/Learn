# include "at24c02.h"
# include "public.h"

void main(){
    ulong num = 0;
    uchar Key_temp = 0;

    T0_init();
    Num_init();

    while(1){
        num = ReturnNum();
        Key_temp = key_JudKey();

        if (Key_temp == 1){
                Key1();
        }
        else if (Key_temp == 2){
            Num_0();
        }
        else if (Key_temp == 3){
            Key3();
        }
        smg_CopLed(num);
        Key_temp = 0;
    }
}