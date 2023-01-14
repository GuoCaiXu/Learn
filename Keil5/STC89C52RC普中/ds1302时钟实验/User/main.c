# include "public.h"
# include "ds1302.h"
# include "smg.h"

void main(){

    ds1302_init();
    T0_init();

    while(1){
        ds1302_read_time();
        smg_ShowNum();
    }
}