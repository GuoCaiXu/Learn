# include <reg52.h>

void delay(unsigned int z){
	
	while(z --);
}

void main(void){
	
	unsigned char i;
	
	while(1){
		
		for (i = 0; i < 8; i ++){
			P0 = 0x01 << i;
			delay(20000);
		}
		
		if (i == 8){
			for (i = 0; i < 8; i ++){
			
			P0 = 0x80 >> i;
			delay(20000);
			}
		}
	}
}