# include "./adc/bsp_adc.h"

uint16_t ADC_ConvertedValue;

/**
 *  @brief  ADC 初始化函数
 *  @param  无
 *  @retval 无
 */
static void ADCx_GPIO_Config(void){
    GPIO_InitTypeDef    GPIO_InitStructure;

    /*打开ADC IO 端时钟*/
    ADC_GPIO_APBxClock_FUN( ADC_GPIO_CLK, ENABLE );

    /*配置ADC IO 引脚模式*/
    /*必须为模拟输入*/
    GPIO_InitStructure.GPIO_Pin = ADC_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

    /*初始化 ADC IO*/
    GPIO_Init(ADC_PORT, &GPIO_InitStructure);
}

/**
 *  @brief  ADC 模式初始化
 *  @param  无
 *  @retval 无
 */
static void ADCx_Mode_Config(void){

    ADC_InitTypeDef ADC_InitStructre;

    /*打开ADC 时钟*/
    ADC_APBxClock_FUN( ADC_CLK, ENABLE );

    /*ADC 模式配置*/
    /*只使用一个ADC，属于独立模式*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_Independent;

    /*禁止扫描模式，多通道才要，单通道不需要*/
    ADC_InitStructre.ADC_ContinuousConvMode = DISABLE;

    /*连续转化模式*/
    ADC_InitStructre.ADC_ContinuousConvMode = ENABLE;

    /*不用外部触发转化，软件开启即可*/
    ADC_InitStructre.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

    /*转化结果右对齐*/
    ADC_InitStructre.ADC_DataAlign = ADC_DataAlign_Right;

    /*转化通道1个*/
    ADC_InitStructre.ADC_NbrOfChannel = 1;

    /*初始化ADC*/
    ADC_Init( ADCx, &ADC_InitStructre );

    /*配置ADC 时钟为CLK2的8分频，即9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*配置 ADC 通道转化顺序和采样时间*/
    ADC_RegularChannelConfig(ADCx, ADC_CHANNEL, 1,
                            ADC_SampleTime_55Cycles5);

    /*ADC 转化结束产生中断，在中断函数服务程序中读取转化值*/
    ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);

    /*开启ADC，并开始转化*/
    ADC_Cmd(ADCx, ENABLE);

    /*初始化ADC 校准寄存器*/
    ADC_ResetCalibration(ADCx);

    /*等待校准寄存器初始化完成*/
    while(ADC_GetResetCalibrationStatus(ADCx));

    /*ADC 开始校准*/
    ADC_StartCalibration(ADCx);

    /*等待校准完成*/
    while(ADC_GetCalibrationStatus(ADCx));

    /*由于没有采用外部触发，所有使用软件触发ADC 转化*/
    ADC_SoftwareStartConvCmd(ADCx, ENABLE);
}

/**
 *  @brief  ADC 中断初始化
 *  @param  无
 *  @retval 无
 */
static void ADCx_NVIC_Config(void){

    NVIC_InitTypeDef NVIC_InitSTructure;

    /*优先级分组*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /*配置中断优先级*/
	NVIC_InitSTructure.NVIC_IRQChannel = ADC_IRQ;
    NVIC_InitSTructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitSTructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitSTructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitSTructure);
}

/**
 *  @brief  ADC 初始化配置
 *  @param  无
 *  @retval 无
 */
void ADCx_Init(void){
    
    /*ADC 初始化函数*/
    ADCx_GPIO_Config();
    /*ADC 模式初始化*/
    ADCx_Mode_Config();
    /*ADC 中断初始化*/
    ADCx_NVIC_Config();
}
