# ifndef _STC89CXX_H
# define _STC89CXX_H

# include "reg52.h"

# define uint8_t	unsigned char
# define uint16_t	unsigned int
# define uint32_t	unsigned long
	
/*10us 延时*/
void delay_10us(uint32_t z);

/*延时1ms*/
void delay_1ms(uint32_t z);

# endif
