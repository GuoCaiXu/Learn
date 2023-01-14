# include "public.h"
# include "lcd1602.h"

void main(){

    //lcd1602初始化
    lcd1602_init();

    //显示字符串
    lcd1602_show_string(0, 0,"It's not just you who are giving");

    while(1);
}