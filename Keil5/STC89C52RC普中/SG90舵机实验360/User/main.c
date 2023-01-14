# include "public.h"

void main(){

    u8 i = 0;

    T0_init();

    while(1){

        key_Judgement();

        for (i = 0; i < 3; i++){
            if (sta[i] != bac[i]){
                if (bac[i] != 0){
                    key_fun(i+1);
                }
            }
            bac[i] = sta[i];
        }
    }
}