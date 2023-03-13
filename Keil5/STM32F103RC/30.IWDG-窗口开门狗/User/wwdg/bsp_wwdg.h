# ifndef _BSP_WWDG_H
# define _BSP_WWDG_H

# include "stm32f10x.h"

/*窗口看门狗递减计数器初始值，范围为：0x40~0x7f，一般设置成最大0x7f*/
# define WWDG_CNT   0x7F

/*WWDG 配置函数*/
void IWDG_Config(uint8_t tr, uint8_t wr, uint32_t prv);
/*喂狗*/
void WWDG_Feed(void);

# endif /*_BSP_WWDG_H*/
