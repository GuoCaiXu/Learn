# include "public.h"
# include "lcd1602.h"

void main(){

    lcd1602_init();
    lcd1602_show_string(0, 0, "Hello World!");
    lcd1602_show_string(0, 1, "Hello C++");

    while(1);
}