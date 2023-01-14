# include "at24c02.h"

void main(){

    uchar Key_temp = 0;
	//保存的值
    ulong save_value = 0;
    T0_init();
    while(1){
        Key_temp = 0;
        Key_temp = JudKey();
        //K1 保存， K2 读取， K3 显示数据加1， K4 显示数据清零
        if (Key_temp == 1){
            at24c02_write_one_byte(0,save_value);
        }
        else if (Key_temp == 2){
           save_value = at24c02_read_byte(0);
        }
        else if (Key_temp == 3){
           save_value++;
        }
        else if (Key_temp == 4){
            save_value = 0;
        }
        smg_Calculate(save_value);
    }
}