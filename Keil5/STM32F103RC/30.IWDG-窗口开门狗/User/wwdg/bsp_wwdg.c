# include "./wwdg/bsp_wwdg.h"

/**
 *  @brief  WWDG 中断优先级初始化
 *  @param  无
 *  @retval 无
 */
static void WWDG_NVIC_Config(void){

    NVIC_InitTypeDef    NVIC_InitStructure;

    /*设置中断组为1*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    /*设置中断来源*/
    NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
    /*设置抢占优先级*/
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    /*设置子优先级*/
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    /*使能中断*/
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/** 
 *  @brief   WWDG 配置函数
 * @param   tr ：递减计时器的值， 取值范围为：0x7f~0x40
 * @param   wr ：窗口值，取值范围为：0x7f~0x40
 * @param   prv：预分频器值，取值可以是
 *      @arg WWDG_Prescaler_1: WWDG counter clock = (PCLK1(36MHZ)/4096)/1
 *      @arg WWDG_Prescaler_2: WWDG counter clock = (PCLK1(36mhz)/4096)/2
 *      @arg WWDG_Prescaler_4: WWDG counter clock = (PCLK1(36mhz)/4096)/4
 *      @arg WWDG_Prescaler_8: WWDG counter clock = (PCLK1(36mhz)/4096)/8
 * @retval 无
 */
void IWDG_Config(uint8_t tr, uint8_t wr, uint32_t prv){
   
   /*开启WWDG 时钟*/
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

   /*设置递减计数器的值*/
   WWDG_SetCounter(tr);

   /*设置预分频的值*/
   WWDG_SetPrescaler(prv);

   /*设置上窗口的值*/
   WWDG_SetWindowValue(wr);

   /*设置计数器的值，使能WWDG*/
   WWDG_Enable(WWDG_CNT);

   /*清除提前唤醒中断标志位*/
   WWDG_ClearFlag();

   /*配置WWDG 中断优先级*/
   WWDG_NVIC_Config();

   /*开启WWDG 中断*/
   WWDG_EnableIT();
}

/**
 *  @brief  喂狗
 *  @param  无
 *  @retval 无
 */
void WWDG_Feed(void){

    /*喂狗，刷新递减计数器的值，设置成最大WDG_CNT=0x7f*/
    WWDG_SetCounter(WWDG_CNT);
}
