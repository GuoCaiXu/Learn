# ifndef _BSP_IWDG_H
# define _BSP_WIDG_H

# include "stm32f10x.h"

/*独立看门狗初始化*/
void IWDG_Config(uint8_t prv, uint16_t rlv);
/*喂狗*/
void IWDG_Feed(void);

# endif /*_BSP_WIDG_H*/
