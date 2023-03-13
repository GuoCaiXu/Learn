# ifndef _BSP_WWDG_H
# define _BSP_WWDG_H

# include "stm32f10x.h"

/*���ڿ��Ź��ݼ���������ʼֵ����ΧΪ��0x40~0x7f��һ�����ó����0x7f*/
# define WWDG_CNT   0x7F

/*WWDG ���ú���*/
void IWDG_Config(uint8_t tr, uint8_t wr, uint32_t prv);
/*ι��*/
void WWDG_Feed(void);

# endif /*_BSP_WWDG_H*/
