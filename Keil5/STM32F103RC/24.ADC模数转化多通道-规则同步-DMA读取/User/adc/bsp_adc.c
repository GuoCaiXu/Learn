# include "./adc/bsp_adc.h"

uint32_t ADC_ConvertedValue[NOFCHANEL] = {0};

/**
 *  @brief  ADC 初始化函数
 *  @param  无
 *  @retval 无
 */
static void ADCx_GPIO_Config(void){

    GPIO_InitTypeDef    GPIO_InitStructure;

    /*ADCx_1 GPIO 初始化*/
    ADCx_1_GPIO_APBxClock_FUN( ADCx_1_GPIO_CLK, ENABLE );
    GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ADCx_1_PORT, &GPIO_InitStructure);

    /*ADCx_2 GPIO 初始化*/
    ADCx_2_GPIO_APBxClock_FUN( ADCx_2_GPIO_CLK, ENABLE );
    GPIO_InitStructure.GPIO_Pin = ADCx_2_PIN;
    GPIO_Init(ADCx_2_PORT, &GPIO_InitStructure);
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
    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_DMA1, ENABLE );
    /*打开ADC 时钟*/
    ADCx_1_APBxClock_FUN( ADCx_1_CLK, ENABLE );
    ADCx_2_APBxClock_FUN( ADCx_2_CLK, ENABLE );

    /*------------DMA 模式配置------------*/

    /*复位DMA 控制器*/
    DMA_DeInit(ADC_DMA_CHANNEL);

    /*配置DMA 初始化结构体*/
    /*外设基址为：ADC 数据寄存器地址*/
    DMA_InitStructre.DMA_PeripheralBaseAddr = (u32)(&(ADCx_1->DR));

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

    /*外设数据大小为一个字*/
    DMA_InitStructre.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;

    /*内存数据大小也为一个字，跟外设数据大小相同*/
    DMA_InitStructre.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;

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

    /*------------ADCx_1 模式配置------------*/
    /*双ADC 的规则同步*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_RegSimult;

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
    ADC_Init( ADCx_1, &ADC_InitStructre );

    /*配置ADC 时钟为CLK2的8分频，即9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*配置 ADC 通道转化顺序和采样时间*/
    ADC_RegularChannelConfig(ADCx_1, ADCx_1_CHANNEL,
                             1, ADC_SampleTime_239Cycles5);

    /*使能ADC DMA 请求*/
    ADC_DMACmd(ADCx_1, ENABLE);

    /*------------ADCx_2 模式配置------------*/
    /*双ADC 的规则同步*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_RegSimult;

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
    ADC_Init( ADCx_2, &ADC_InitStructre );

    /*配置ADC 时钟为CLK2的8分频，即9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*配置 ADC 通道转化顺序和采样时间*/
    ADC_RegularChannelConfig(ADCx_2, ADCx_2_CHANNEL,
                             1, ADC_SampleTime_239Cycles5);

    /*使能ADCx_2 外部触发转化*/
    ADC_ExternalTrigConvCmd(ADCx_2, ENABLE);

    /*------------ADCx_1 校准------------*/
    /*开启ADC，并开始转化*/
    ADC_Cmd(ADCx_1, ENABLE);

    /*初始化ADC 校准寄存器*/
    ADC_ResetCalibration(ADCx_1);

    /*等待校准寄存器初始化完成*/
    while(ADC_GetResetCalibrationStatus(ADCx_1));

    /*ADC 开始校准*/
    ADC_StartCalibration(ADCx_1);

    /*等待校准完成*/
    while(ADC_GetCalibrationStatus(ADCx_1));

    /*------------ADCx_2 校准------------*/
    /*开启ADC，并开始转化*/
    ADC_Cmd(ADCx_2, ENABLE);

    /*初始化ADC 校准寄存器*/
    ADC_ResetCalibration(ADCx_2);

    /*等待校准寄存器初始化完成*/
    while(ADC_GetResetCalibrationStatus(ADCx_2));

    /*ADC 开始校准*/
    ADC_StartCalibration(ADCx_2);

    /*等待校准完成*/
    while(ADC_GetCalibrationStatus(ADCx_2));

    /*由于没有采用外部触发，所有使用软件触发ADC 转化*/
    ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
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

