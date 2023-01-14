# include <reg52.h>
# define uchar unsigned char
# define uint unsigned int

//????
sbit OUT1 =P1^0;
sbit OUT2 =P1^1;
sbit OUT3 =P1^2;
sbit OUT4 =P1^3;

//??
sbit KeyOut4 = P2^0;
sbit KeyOut3 = P2^1;
sbit KeyOut2 = P2^2;
sbit KeyOut1 = P2^3;
sbit KEY1 = P2^4;
sbit KEY2 = P2^5;
sbit KEY3 = P2^6;
sbit KEY4 = P2^7;

//???T0?????
void T0_init(){
	EA = 1; //???????
	TMOD = 0x01; //T0????1
	TH0 = 0xfc;
	TL0 = 0x66;
	ET0 = 1;
	TR0 = 1;
	KeyOut1 = 0;
}

//??????
uchar cnt = 0;

//????????
uchar KeySta[] = {1,1,1,1};

//??????
uchar dir = 0;

//??????
uchar Menu = 0;

//????????
void pickScanf();

//??????2
void MenuBJ();

//???
void main(){

	T0_init();

	while(1){
		if (Menu == 0){
		pickScanf();
		}
		else if (Menu == 1){
			MenuBJ();
		}
	}
}

//????
void tureBJ(signed m){
static signed char i = 0;

	if (m != -1){
		i = m;
	}

	switch(i){
		case 0: OUT1 = 1; OUT2 = 0; OUT3 = 0; OUT4 = 0; break;
		case 1: OUT1 = 1; OUT2 = 1; OUT3 = 0; OUT4 = 0; break;
		case 2: OUT1 = 0; OUT2 = 1; OUT3 = 0; OUT4 = 0; break;
		case 3: OUT1 = 0; OUT2 = 1; OUT3 = 1; OUT4 = 0; break;
		case 4: OUT1 = 0; OUT2 = 0; OUT3 = 1; OUT4 = 0; break;
		case 5: OUT1 = 0; OUT2 = 0; OUT3 = 1; OUT4 = 1; break;
		case 6: OUT1 = 0; OUT2 = 0; OUT3 = 0; OUT4 = 1; break;
		case 7: OUT1 = 1; OUT2 = 0; OUT3 = 0; OUT4 = 1; break;
		default: OUT1 = 0; OUT2 = 0; OUT3 = 0; OUT4 = 0; break;
   }
   if (dir == 0){
	i++;
	if (i >= 8){
		i = 0;
	}
   }
   else if (dir == 1){
	i--;
	if (i <= 0){
		i = 7;
	}
   }
}

//????
void ControlBJ(uchar num){

	//????
	if (num == 0){
		dir = !dir;
		if (dir == 0){
			tureBJ(0);
		}
		else{
			tureBJ(7);
		}
	}
	//??
	else if (num == 1){
		if (cnt <= 0){
			cnt = 1;
		}
		cnt--;
	}
	//??
	else if (num == 2){
		cnt++;
	}
	//????????
	else if (num == 3){
		Menu = 1;
		EA = 0;
		dir = -1;
	}
}

void delay(uchar z){
	while(z--);
}

//??????2
void MenuBJ(){
	static signed i = 0;
		if (KEY1 == 0){
			i = 0;
			while(1){
			tureBJ(i++);
			if (i >= 8){
				i = 0;
			}
			if (KEY1 == 1){
				break;
			}
			delay(200);
			}
        }
		else if (KEY2 == 0){
			i = 7;
			while(1){
			tureBJ(i--);
			if (i <= 0){
				i = 7;
			}
			if (KEY2 == 1){
				break;
			}
			delay(200);
			}
		}
		else if (KEY3 == 0){
			Menu = 0;
			EA = 1;
			dir = 0;
		}
}

//????????
void pickScanf(){
	static KeyBac[] = {1,1,1,1};
	uchar i;

	for (i = 0; i < 4; i++){
		if (KeyBac[i] != KeySta[i]){
			if (KeyBac[i] != 0){
				ControlBJ(i);
			}
			KeyBac[i] = KeySta[i];
		}
	}
	
}

//??????????
void KeyScanf(){
	uchar i;
	uchar KeyBuf[] = {1,1,1,1};

	KeyBuf[0] = KEY1;
	KeyBuf[1] = KEY2;
	KeyBuf[2] = KEY3;
	KeyBuf[3] = KEY4;

	for (i = 0; i < 4; i++){
		if (KeyBuf[i] == 0){
			KeySta[i] = 0;
		}
		else if (KeyBuf[i] == 1){
			KeySta[i] = 1;
		}
	}
}

void InterruptTime0() interrupt 1{
	static uchar i = 0;
	TH0 = 0xfc;
	TL0 = 0x66;

	i++;
	if(i >= cnt){
		i = 0;
		tureBJ(-1);
	}

	KeyScanf();
}