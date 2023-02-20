# include "./adc/bsp_adc.h"

uint32_t ADC_ConvertedValue[NOFCHANEL] = {0};

/**
 *  @brief  ADC ��ʼ������
 *  @param  ��
 *  @retval ��
 */
static void ADCx_GPIO_Config(void){

    GPIO_InitTypeDef    GPIO_InitStructure;

    /*ADCx_1 GPIO ��ʼ��*/
    ADCx_1_GPIO_APBxClock_FUN( ADCx_1_GPIO_CLK, ENABLE );
    GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ADCx_1_PORT, &GPIO_InitStructure);

    /*ADCx_2 GPIO ��ʼ��*/
    ADCx_2_GPIO_APBxClock_FUN( ADCx_2_GPIO_CLK, ENABLE );
    GPIO_InitStructure.GPIO_Pin = ADCx_2_PIN;
    GPIO_Init(ADCx_2_PORT, &GPIO_InitStructure);
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
    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_DMA1, ENABLE );
    /*��ADC ʱ��*/
    ADCx_1_APBxClock_FUN( ADCx_1_CLK, ENABLE );
    ADCx_2_APBxClock_FUN( ADCx_2_CLK, ENABLE );

    /*------------DMA ģʽ����------------*/

    /*��λDMA ������*/
    DMA_DeInit(ADC_DMA_CHANNEL);

    /*����DMA ��ʼ���ṹ��*/
    /*�����ַΪ��ADC ���ݼĴ�����ַ*/
    DMA_InitStructre.DMA_PeripheralBaseAddr = (u32)(&(ADCx_1->DR));

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

    /*�������ݴ�СΪһ����*/
    DMA_InitStructre.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;

    /*�ڴ����ݴ�СҲΪһ���֣����������ݴ�С��ͬ*/
    DMA_InitStructre.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;

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

    /*------------ADCx_1 ģʽ����------------*/
    /*˫ADC �Ĺ���ͬ��*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_RegSimult;

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
    ADC_Init( ADCx_1, &ADC_InitStructre );

    /*����ADC ʱ��ΪCLK2��8��Ƶ����9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*���� ADC ͨ��ת��˳��Ͳ���ʱ��*/
    ADC_RegularChannelConfig(ADCx_1, ADCx_1_CHANNEL,
                             1, ADC_SampleTime_239Cycles5);

    /*ʹ��ADC DMA ����*/
    ADC_DMACmd(ADCx_1, ENABLE);

    /*------------ADCx_2 ģʽ����------------*/
    /*˫ADC �Ĺ���ͬ��*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_RegSimult;

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
    ADC_Init( ADCx_2, &ADC_InitStructre );

    /*����ADC ʱ��ΪCLK2��8��Ƶ����9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*���� ADC ͨ��ת��˳��Ͳ���ʱ��*/
    ADC_RegularChannelConfig(ADCx_2, ADCx_2_CHANNEL,
                             1, ADC_SampleTime_239Cycles5);

    /*ʹ��ADCx_2 �ⲿ����ת��*/
    ADC_ExternalTrigConvCmd(ADCx_2, ENABLE);

    /*------------ADCx_1 У׼------------*/
    /*����ADC������ʼת��*/
    ADC_Cmd(ADCx_1, ENABLE);

    /*��ʼ��ADC У׼�Ĵ���*/
    ADC_ResetCalibration(ADCx_1);

    /*�ȴ�У׼�Ĵ�����ʼ�����*/
    while(ADC_GetResetCalibrationStatus(ADCx_1));

    /*ADC ��ʼУ׼*/
    ADC_StartCalibration(ADCx_1);

    /*�ȴ�У׼���*/
    while(ADC_GetCalibrationStatus(ADCx_1));

    /*------------ADCx_2 У׼------------*/
    /*����ADC������ʼת��*/
    ADC_Cmd(ADCx_2, ENABLE);

    /*��ʼ��ADC У׼�Ĵ���*/
    ADC_ResetCalibration(ADCx_2);

    /*�ȴ�У׼�Ĵ�����ʼ�����*/
    while(ADC_GetResetCalibrationStatus(ADCx_2));

    /*ADC ��ʼУ׼*/
    ADC_StartCalibration(ADCx_2);

    /*�ȴ�У׼���*/
    while(ADC_GetCalibrationStatus(ADCx_2));

    /*����û�в����ⲿ����������ʹ���������ADC ת��*/
    ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
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

