# include "stc89cxx.h"

/*10us 延时*/
void delay_10us(uint32_t z){

	while(z --);
}

/*延时1ms*/
void delay_1ms(uint32_t z){

	uint8_t i = 0;
	while(z --){
		for (i = 0; i <= 120; i ++);
	}
}
