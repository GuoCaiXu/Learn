# include "public.h"

void main(){

    T0_init();
    hs0038_ired_init();

    while(1){

        LedBuff[0] = LedChar[gired[2] % 16];
        LedBuff[1] = LedChar[gired[2] / 16];
    }
}