# include "public.h"
# include "ds18b20.h"
# include "smg.h"

void main(){
    int temp_value = 0;
    uchar temp_pick = 1;
    uchar i = 0;
    uint num = 0;

    //初始化
    ds18b20_init();

    //定时器T0 中断初始化
    public_T0_init();

    while(1){
        i++;

        if (i == 50){
            i = 0;
        temp_value = ds18b20_read_temperture() * 10;
        }

        if (temp_value < 0){
            temp_value = -temp_value;
            temp_pick = 0;
            num = temp_value;
        }
        else {
            temp_pick = 1;
            num = temp_value;
        }
        smg_ShowNumber(num, temp_pick);
    }
}