# ifndef _BSP_IWDG_H
# define _BSP_WIDG_H

# include "stm32f10x.h"

/*�������Ź���ʼ��*/
void IWDG_Config(uint8_t prv, uint16_t rlv);
/*ι��*/
void IWDG_Feed(void);

# endif /*_BSP_WIDG_H*/
