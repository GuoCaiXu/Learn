# include "./adc/bsp_adc.h"

uint16_t ADC_ConvertedValue[NOFCHANEL] = {0, 0, 0, 0, 0, 0};

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
    GPIO_InitStructure.GPIO_Pin = ADC_PIN1|ADC_PIN2|ADC_PIN3|ADC_PIN4
                                |ADC_PIN5|ADC_PIN6;
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

    DMA_InitTypeDef DMA_InitStructre;
    ADC_InitTypeDef ADC_InitStructre;


    /*打开DMA 时钟*/
    DMA_APBxClock_FUN( ADC_DMA_CLK, ENABLE );
    /*打开ADC 时钟*/
    ADC_APBxClock_FUN( ADC_CLK, ENABLE );

    /*复位DMA 控制器*/
    DMA_DeInit(ADC_DMA_CHANNEL);

    /*配置DMA 初始化结构体*/
    /*外设基址为：ADC 数据寄存器地址*/
    DMA_InitStructre.DMA_PeripheralBaseAddr = (u32)(&(ADC_x->DR));

    /*储存器地址*/
    DMA_InitStructre.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;

    /*数据源来自外设*/
    DMA_InitStructre.DMA_DIR = DMA_DIR_PeripheralSRC;

    /*缓冲区大小，应该等于数据目的地的大小*/
    DMA_InitStructre.DMA_BufferSize = NOFCHANEL;

    /*外设寄存器只有一个，地址不用递增*/
    DMA_InitStructre.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

    /*寄存器地址递增*/
    DMA_InitStructre.DMA_MemoryInc = DMA_MemoryInc_Enable;

    /*外设数据大小为半字，即两个字节*/
    DMA_InitStructre.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;

    /*内存数据大小也为半字，跟外设数据大小相同*/
    DMA_InitStructre.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;

    /*循环传输模式*/
    DMA_InitStructre.DMA_Mode = DMA_Mode_Circular;

    /*DMA 传输通道优先级为高，当使用一个DMA 通道时，优先级设置不影响*/
    DMA_InitStructre.DMA_Priority = DMA_Priority_High;

    /*禁止储存器到储存器模式，因为是从外设到储存器*/
    DMA_InitStructre.DMA_M2M = DMA_M2M_Disable;

    /*初始化DMA*/
    DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructre);

    /*使能 DMA 通道*/
    DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

    /*ADC 模式配置*/
    /*只使用一个ADC，属于单模式*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_Independent;

    /*扫描模式*/
    ADC_InitStructre.ADC_ScanConvMode = ENABLE;

    /*连续转化模式*/
    ADC_InitStructre.ADC_ContinuousConvMode = ENABLE;

    /*不用外部触发转化，软件开启即可*/
    ADC_InitStructre.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

    /*转化结果右对齐*/
    ADC_InitStructre.ADC_DataAlign = ADC_DataAlign_Right;

    /*转化通道的个数*/
    ADC_InitStructre.ADC_NbrOfChannel = NOFCHANEL;

    /*初始化ADC*/
    ADC_Init( ADC_x, &ADC_InitStructre );

    /*配置ADC 时钟为CLK2的8分频，即9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*配置 ADC 通道转化顺序和采样时间*/
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL1, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL2, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL3, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL4, 4, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL5, 5, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL6, 6, ADC_SampleTime_55Cycles5);

    /*使能ADC DMA 请求*/
    ADC_DMACmd(ADC_x, ENABLE);

    /*开启ADC，并开始转化*/
    ADC_Cmd(ADC_x, ENABLE);

    /*初始化ADC 校准寄存器*/
    ADC_ResetCalibration(ADC_x);

    /*等待校准寄存器初始化完成*/
    while(ADC_GetResetCalibrationStatus(ADC_x));

    /*ADC 开始校准*/
    ADC_StartCalibration(ADC_x);

    /*等待校准完成*/
    while(ADC_GetCalibrationStatus(ADC_x));

    /*由于没有采用外部触发，所有使用软件触发ADC 转化*/
    ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
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
}

