# ifndef _BSP_LED_H
# define _BSP_LED_H

# include "stm32f10x.h"

# define LED1_GPIO_CLK  RCC_APB2Periph_GPIOC
# define LED1_GPIO_PORT GPIOC
# define LED1_GPIO_PIN  GPIO_Pin_2

# define LED2_GPIO_CLK  RCC_APB2Periph_GPIOC
# define LED2_GPIO_PORT GPIOC
# define LED2_GPIO_PIN  GPIO_Pin_3

# define digitalHi(p, i)    {p->BSRR = i;}
# define digitalLo(p, i)    {p->BRR = i;}
# define digitalTOGGLE(p, i)    {p->ODR ^= i;}

# define LED1_TOGGLE            digitalTOGGLE(LED1_GPIO_PORT, LED1_GPIO_PIN)
# define LED1_OFF               digitalHi(LED1_GPIO_PORT, LED1_GPIO_PIN)
# define LED1_ON                digitalLo(LED1_GPIO_PORT, LED1_GPIO_PIN)

# define LED2_TOGGLE            digitalTOGGLE(LED2_GPIO_PORT, LED2_GPIO_PIN)
# define LED2_OFF               digitalHi(LED2_GPIO_PORT, LED2_GPIO_PIN)
# define LED2_ON                digitalLo(LED2_GPIO_PORT, LED2_GPIO_PIN)

/*LEDС??GPIO??ʼ??*/
void LED_GPIO_Config(void);

# endif /*_BSP_LED_H*/
