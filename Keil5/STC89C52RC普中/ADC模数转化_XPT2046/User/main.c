# include "public.h"

void main(){

    u16 adc_value = 0;
    float adc_vol = 0;

    T0_init();

    while(1){
        adc_value = xpt2046_read_adc_value(0x94);

        adc_vol = 5.0 * adc_value / 4096;
        adc_value = adc_vol * 10;
        smg_ShowNum(adc_value);
    }
}