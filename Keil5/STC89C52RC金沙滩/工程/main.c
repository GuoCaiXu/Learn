#include <reg52.h>

unsigned char a[] = {0xC0,0xF9,0xA4,0xB0,
										0x99,0x92,0x82,0xF8,
										0x80,0x90,0x88,0x83,
										0xC6,0xA1,0x86,0x8E};

void show(unsigned int num);
										
void main(void)
{
	unsigned int cnt = 0,num;
	
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	
	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0x3C;
			TL0 = 0xAF;
			
			cnt ++;
			if(cnt >= 20)
			{
				cnt = 0;
				num ++;
			}
		}
		show(num);
	}
}

void show(unsigned int num)
{
	unsigned char i,time;
	for(i = 0;i < 8;i ++)
	{
		P0 = 0xFF;
		P1 = 0xE8 + i;
		P0 = a[num % 10];
		num /= 10;
		for(time = 0;time < 200;time ++);
	}
}