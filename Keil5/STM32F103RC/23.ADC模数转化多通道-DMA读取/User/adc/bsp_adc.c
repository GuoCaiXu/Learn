# include "./adc/bsp_adc.h"

uint16_t ADC_ConvertedValue[NOFCHANEL] = {0, 0, 0, 0, 0, 0};

/**
 *  @brief  ADC ��ʼ������
 *  @param  ��
 *  @retval ��
 */
static void ADCx_GPIO_Config(void){
    GPIO_InitTypeDef    GPIO_InitStructure;

    /*��ADC IO ��ʱ��*/
    ADC_GPIO_APBxClock_FUN( ADC_GPIO_CLK, ENABLE );

    /*����ADC IO ����ģʽ*/
    /*����Ϊģ������*/
    GPIO_InitStructure.GPIO_Pin = ADC_PIN1|ADC_PIN2|ADC_PIN3|ADC_PIN4
                                |ADC_PIN5|ADC_PIN6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

    /*��ʼ�� ADC IO*/
    GPIO_Init(ADC_PORT, &GPIO_InitStructure);
}

/**
 *  @brief  ADC ģʽ��ʼ��
 *  @param  ��
 *  @retval ��
 */
static void ADCx_Mode_Config(void){

    DMA_InitTypeDef DMA_InitStructre;
    ADC_InitTypeDef ADC_InitStructre;


    /*��DMA ʱ��*/
    DMA_APBxClock_FUN( ADC_DMA_CLK, ENABLE );
    /*��ADC ʱ��*/
    ADC_APBxClock_FUN( ADC_CLK, ENABLE );

    /*��λDMA ������*/
    DMA_DeInit(ADC_DMA_CHANNEL);

    /*����DMA ��ʼ���ṹ��*/
    /*�����ַΪ��ADC ���ݼĴ�����ַ*/
    DMA_InitStructre.DMA_PeripheralBaseAddr = (u32)(&(ADC_x->DR));

    /*��������ַ*/
    DMA_InitStructre.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;

    /*����Դ��������*/
    DMA_InitStructre.DMA_DIR = DMA_DIR_PeripheralSRC;

    /*��������С��Ӧ�õ�������Ŀ�ĵصĴ�С*/
    DMA_InitStructre.DMA_BufferSize = NOFCHANEL;

    /*����Ĵ���ֻ��һ������ַ���õ���*/
    DMA_InitStructre.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

    /*�Ĵ�����ַ����*/
    DMA_InitStructre.DMA_MemoryInc = DMA_MemoryInc_Enable;

    /*�������ݴ�СΪ���֣��������ֽ�*/
    DMA_InitStructre.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;

    /*�ڴ����ݴ�СҲΪ���֣����������ݴ�С��ͬ*/
    DMA_InitStructre.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;

    /*ѭ������ģʽ*/
    DMA_InitStructre.DMA_Mode = DMA_Mode_Circular;

    /*DMA ����ͨ�����ȼ�Ϊ�ߣ���ʹ��һ��DMA ͨ��ʱ�����ȼ����ò�Ӱ��*/
    DMA_InitStructre.DMA_Priority = DMA_Priority_High;

    /*��ֹ��������������ģʽ����Ϊ�Ǵ����赽������*/
    DMA_InitStructre.DMA_M2M = DMA_M2M_Disable;

    /*��ʼ��DMA*/
    DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructre);

    /*ʹ�� DMA ͨ��*/
    DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

    /*ADC ģʽ����*/
    /*ֻʹ��һ��ADC�����ڵ�ģʽ*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_Independent;

    /*ɨ��ģʽ*/
    ADC_InitStructre.ADC_ScanConvMode = ENABLE;

    /*����ת��ģʽ*/
    ADC_InitStructre.ADC_ContinuousConvMode = ENABLE;

    /*�����ⲿ����ת���������������*/
    ADC_InitStructre.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

    /*ת������Ҷ���*/
    ADC_InitStructre.ADC_DataAlign = ADC_DataAlign_Right;

    /*ת��ͨ���ĸ���*/
    ADC_InitStructre.ADC_NbrOfChannel = NOFCHANEL;

    /*��ʼ��ADC*/
    ADC_Init( ADC_x, &ADC_InitStructre );

    /*����ADC ʱ��ΪCLK2��8��Ƶ����9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*���� ADC ͨ��ת��˳��Ͳ���ʱ��*/
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL1, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL2, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL3, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL4, 4, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL5, 5, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL6, 6, ADC_SampleTime_55Cycles5);

    /*ʹ��ADC DMA ����*/
    ADC_DMACmd(ADC_x, ENABLE);

    /*����ADC������ʼת��*/
    ADC_Cmd(ADC_x, ENABLE);

    /*��ʼ��ADC У׼�Ĵ���*/
    ADC_ResetCalibration(ADC_x);

    /*�ȴ�У׼�Ĵ�����ʼ�����*/
    while(ADC_GetResetCalibrationStatus(ADC_x));

    /*ADC ��ʼУ׼*/
    ADC_StartCalibration(ADC_x);

    /*�ȴ�У׼���*/
    while(ADC_GetCalibrationStatus(ADC_x));

    /*����û�в����ⲿ����������ʹ���������ADC ת��*/
    ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
}

/**
 *  @brief  ADC ��ʼ������
 *  @param  ��
 *  @retval ��
 */
void ADCx_Init(void){
    
    /*ADC ��ʼ������*/
    ADCx_GPIO_Config();
    /*ADC ģʽ��ʼ��*/
    ADCx_Mode_Config();
}

