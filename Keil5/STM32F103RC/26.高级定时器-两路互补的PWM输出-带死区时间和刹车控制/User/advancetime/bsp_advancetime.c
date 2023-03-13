# include "./advancetime/bsp_advancetime.h"

/**
 *  @brief  高级定时器初始化
 *  @param  无
 *  @retval 无
 */
static void ADVANCE_TIM_GPIO_Config(void){

    GPIO_InitTypeDef  GPIO_InitStruceure;

    /*输出比较通道 GPIO 初始化*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_CH1_PIN;
    GPIO_InitStruceure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruceure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStruceure);

    /*输出比较通道互补通道 GPIO 初始化*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1N_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_CH1N_PIN;
    GPIO_Init(ADVANCE_TIM_CH1N_PORT, &GPIO_InitStruceure);

    /*输出比较通道刹车通道 GPIO 初始化*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1N_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_BKIN_PIN;
    GPIO_Init(ADVANCE_TIM_BKIN_PORT, &GPIO_InitStruceure);

    /*BKIN 引脚默认先输出低电平*/
    GPIO_ResetBits(ADVANCE_TIM_BKIN_PORT, ADVANCE_TIM_BKIN_PIN);
}

/*
typedef struct
{
  uint16_t TIM_Prescaler;           //预分频器                                    
  uint16_t TIM_CounterMode;         //计数模式
  uint16_t TIM_Period;              //定时器周期                        
  uint16_t TIM_ClockDivision;       //时钟分频
  uint8_t TIM_RepetitionCounter;    //重复计算器
} TIM_TimeBaseInitTypeDef;


typedef struct
{
  uint16_t TIM_OCMode;              //比较输出模式
  uint16_t TIM_OutputState;         //比较输出使能
  uint16_t TIM_OutputNState;        //比较互补输出使能
  uint16_t TIM_Pulse;               //脉冲宽度
  uint16_t TIM_OCPolarity;          //输出极性
  uint16_t TIM_OCNPolarity;         //互补输出极性
  uint16_t TIM_OCIdleState;         //空闲状态下比较输出状态
  uint16_t TIM_OCNIdleState;        //空闲状态下比较互补输出状态
} TIM_OCInitTypeDef;

输入捕获结构体

*/

/**
 *  @brief  高级定时器模式初始化
 *  @param  无
 *  @retval 无
 */

static void ADVANCE_TIM_Mode_Config(void){

    /*开启定时器时钟，即内部时钟CK_INT=72M*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);


    /*********时基结构体初始化*********/
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    /*自动重装载寄存器的值，累计TIM_Period+1 个频率后产生一个更新或者中断*/
    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_PERIOD;
    /*驱动CNT计数器的时钟 = Fck_int/(psc+1)     11*1/72*/
    TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_PSC;
    /*时钟分频因子，配置死区时间需要用到*/
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    /*计数器计数模式，设置为向上计数*/
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    /*重复计数器的值，没用到不管*/
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    /*初始化定时器*/
    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);


    /*********输出比较结构体初始化*********/
    TIM_OCInitTypeDef TiM_OCInitStructure;
    /*配置为PWM模式1*/
    TiM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    /*输出使能*/
    TiM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    /*设置占空比大小*/
    TiM_OCInitStructure.TIM_Pulse = ADVANCE_TIM_PULSE;
    /*互补输出使能*/
    TiM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    /*输出通道电平极性配置*/
    TiM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    /*互补输出通道电平极性配置*/
    TiM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    /*输出通道空闲电平极性配置*/
    TiM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    /*互补输出通道电平极性配置*/
    TiM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
    TIM_OC1Init(ADVANCE_TIM, &TiM_OCInitStructure);
    TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);

    
    /*********刹车和死区结构体初始化*********/
    /*有关刹车和死区结构体的成员具体可参考BDTR寄存器描述*/
    TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
    /*输出比较信号死区时间配置，具体如何计算可参考 BDTR:UTG[7:0]的描述*/
    /*这里配置的死去时间为152ns*/
    TIM_BDTRInitStructure.TIM_DeadTime = 11;
    TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
    /*当BKIN引脚检测到高电平的时候，输出比较信号被禁止，就好像是刹车一样*/
    TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    TIM_BDTRConfig(ADVANCE_TIM, &TIM_BDTRInitStructure);


    /*使能计数器*/
    TIM_Cmd(ADVANCE_TIM, ENABLE);
    /*主输出使能，当使用的是通用定时器时这句不需要*/
    TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
}

void ADVANCE_TIM_Init(void){
    
    ADVANCE_TIM_GPIO_Config();
    ADVANCE_TIM_Mode_Config();
}
