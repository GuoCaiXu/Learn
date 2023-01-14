# include "key.h"

uint8_t KeySta[4] = {1,1,1,1};
uint8_t KeyBac[4] = {1,1,1,1};

//判断按键是否按下
uint8_t key_Judgement(){
    uint8_t i = 0;
    uint8_t key = 0;

    for (i = 0; i < 4; i++){
        if (KeySta[i] != KeyBac[i]){
            if (KeyBac[i] != 0){
                key = i+1;
            }
            KeyBac[i] = KeySta[i];
        }
    }
    return key;
}

//中断函数
void key_pick() {
    uint8_t KeyBuf[4] = {1,1,1,1};
    uint8_t i = 0;
    
    KeyBuf[0] = KEY1;
    KeyBuf[1] = KEY2;
    KeyBuf[2] = KEY3;
    KeyBuf[3] = KEY4;

    for (i = 0; i < 4; i++){
        if (KeyBuf[i] == 0) KeySta[i] = 0;
        else if (KeyBuf[i] == 1) KeySta[i] = 1;
    }
}
