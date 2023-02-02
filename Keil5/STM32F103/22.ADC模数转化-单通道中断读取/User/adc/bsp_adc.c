# include "./adc/bsp_adc.h"

uint16_t ADC_ConvertedValue;

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
    GPIO_InitStructure.GPIO_Pin = ADC_PIN;
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

    ADC_InitTypeDef ADC_InitStructre;

    /*��ADC ʱ��*/
    ADC_APBxClock_FUN( ADC_CLK, ENABLE );

    /*ADC ģʽ����*/
    /*ֻʹ��һ��ADC�����ڶ���ģʽ*/
    ADC_InitStructre.ADC_Mode = ADC_Mode_Independent;

    /*��ֹɨ��ģʽ����ͨ����Ҫ����ͨ������Ҫ*/
    ADC_InitStructre.ADC_ContinuousConvMode = DISABLE;

    /*����ת��ģʽ*/
    ADC_InitStructre.ADC_ContinuousConvMode = ENABLE;

    /*�����ⲿ����ת���������������*/
    ADC_InitStructre.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

    /*ת������Ҷ���*/
    ADC_InitStructre.ADC_DataAlign = ADC_DataAlign_Right;

    /*ת��ͨ��1��*/
    ADC_InitStructre.ADC_NbrOfChannel = 1;

    /*��ʼ��ADC*/
    ADC_Init( ADCx, &ADC_InitStructre );

    /*����ADC ʱ��ΪCLK2��8��Ƶ����9MHz*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    /*���� ADC ͨ��ת��˳��Ͳ���ʱ��*/
    ADC_RegularChannelConfig(ADCx, ADC_CHANNEL, 1,
                            ADC_SampleTime_55Cycles5);

    /*ADC ת�����������жϣ����жϺ�����������ж�ȡת��ֵ*/
    ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);

    /*����ADC������ʼת��*/
    ADC_Cmd(ADCx, ENABLE);

    /*��ʼ��ADC У׼�Ĵ���*/
    ADC_ResetCalibration(ADCx);

    /*�ȴ�У׼�Ĵ�����ʼ�����*/
    while(ADC_GetResetCalibrationStatus(ADCx));

    /*ADC ��ʼУ׼*/
    ADC_StartCalibration(ADCx);

    /*�ȴ�У׼���*/
    while(ADC_GetCalibrationStatus(ADCx));

    /*����û�в����ⲿ����������ʹ���������ADC ת��*/
    ADC_SoftwareStartConvCmd(ADCx, ENABLE);
}

/**
 *  @brief  ADC �жϳ�ʼ��
 *  @param  ��
 *  @retval ��
 */
static void ADCx_NVIC_Config(void){

    NVIC_InitTypeDef NVIC_InitSTructure;

    /*���ȼ�����*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /*�����ж����ȼ�*/
	NVIC_InitSTructure.NVIC_IRQChannel = ADC_IRQ;
    NVIC_InitSTructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitSTructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitSTructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitSTructure);
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
    /*ADC �жϳ�ʼ��*/
    ADCx_NVIC_Config();
}
