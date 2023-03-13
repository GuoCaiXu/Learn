# include "./advancetime/bsp_advancetime.h"

/**
 *  @brief  �߼���ʱ����ʼ��
 *  @param  ��
 *  @retval ��
 */
static void ADVANCE_TIM_GPIO_Config(void){

    GPIO_InitTypeDef  GPIO_InitStruceure;

    /*����Ƚ�ͨ�� GPIO ��ʼ��*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_CH1_PIN;
    GPIO_InitStruceure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruceure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStruceure);

    /*����Ƚ�ͨ������ͨ�� GPIO ��ʼ��*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1N_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_CH1N_PIN;
    GPIO_Init(ADVANCE_TIM_CH1N_PORT, &GPIO_InitStruceure);

    /*����Ƚ�ͨ��ɲ��ͨ�� GPIO ��ʼ��*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CH1N_GPIO_CLK, ENABLE);
    GPIO_InitStruceure.GPIO_Pin = ADVANCE_TIM_BKIN_PIN;
    GPIO_Init(ADVANCE_TIM_BKIN_PORT, &GPIO_InitStruceure);

    /*BKIN ����Ĭ��������͵�ƽ*/
    GPIO_ResetBits(ADVANCE_TIM_BKIN_PORT, ADVANCE_TIM_BKIN_PIN);
}

/*
typedef struct
{
  uint16_t TIM_Prescaler;           //Ԥ��Ƶ��                                    
  uint16_t TIM_CounterMode;         //����ģʽ
  uint16_t TIM_Period;              //��ʱ������                        
  uint16_t TIM_ClockDivision;       //ʱ�ӷ�Ƶ
  uint8_t TIM_RepetitionCounter;    //�ظ�������
} TIM_TimeBaseInitTypeDef;


typedef struct
{
  uint16_t TIM_OCMode;              //�Ƚ����ģʽ
  uint16_t TIM_OutputState;         //�Ƚ����ʹ��
  uint16_t TIM_OutputNState;        //�Ƚϻ������ʹ��
  uint16_t TIM_Pulse;               //������
  uint16_t TIM_OCPolarity;          //�������
  uint16_t TIM_OCNPolarity;         //�����������
  uint16_t TIM_OCIdleState;         //����״̬�±Ƚ����״̬
  uint16_t TIM_OCNIdleState;        //����״̬�±Ƚϻ������״̬
} TIM_OCInitTypeDef;

���벶��ṹ��

*/

/**
 *  @brief  �߼���ʱ��ģʽ��ʼ��
 *  @param  ��
 *  @retval ��
 */

static void ADVANCE_TIM_Mode_Config(void){

    /*������ʱ��ʱ�ӣ����ڲ�ʱ��CK_INT=72M*/
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);


    /*********ʱ���ṹ���ʼ��*********/
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    /*�Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1 ��Ƶ�ʺ����һ�����»����ж�*/
    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_PERIOD;
    /*����CNT��������ʱ�� = Fck_int/(psc+1)     11*1/72*/
    TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_PSC;
    /*ʱ�ӷ�Ƶ���ӣ���������ʱ����Ҫ�õ�*/
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    /*����������ģʽ������Ϊ���ϼ���*/
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    /*�ظ���������ֵ��û�õ�����*/
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    /*��ʼ����ʱ��*/
    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);


    /*********����ȽϽṹ���ʼ��*********/
    TIM_OCInitTypeDef TiM_OCInitStructure;
    /*����ΪPWMģʽ1*/
    TiM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    /*���ʹ��*/
    TiM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    /*����ռ�ձȴ�С*/
    TiM_OCInitStructure.TIM_Pulse = ADVANCE_TIM_PULSE;
    /*�������ʹ��*/
    TiM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    /*���ͨ����ƽ��������*/
    TiM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    /*�������ͨ����ƽ��������*/
    TiM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    /*���ͨ�����е�ƽ��������*/
    TiM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    /*�������ͨ����ƽ��������*/
    TiM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
    TIM_OC1Init(ADVANCE_TIM, &TiM_OCInitStructure);
    TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);

    
    /*********ɲ���������ṹ���ʼ��*********/
    /*�й�ɲ���������ṹ��ĳ�Ա����ɲο�BDTR�Ĵ�������*/
    TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
    /*����Ƚ��ź�����ʱ�����ã�������μ���ɲο� BDTR:UTG[7:0]������*/
    /*�������õ���ȥʱ��Ϊ152ns*/
    TIM_BDTRInitStructure.TIM_DeadTime = 11;
    TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
    /*��BKIN���ż�⵽�ߵ�ƽ��ʱ������Ƚ��źű���ֹ���ͺ�����ɲ��һ��*/
    TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    TIM_BDTRConfig(ADVANCE_TIM, &TIM_BDTRInitStructure);


    /*ʹ�ܼ�����*/
    TIM_Cmd(ADVANCE_TIM, ENABLE);
    /*�����ʹ�ܣ���ʹ�õ���ͨ�ö�ʱ��ʱ��䲻��Ҫ*/
    TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
}

void ADVANCE_TIM_Init(void){
    
    ADVANCE_TIM_GPIO_Config();
    ADVANCE_TIM_Mode_Config();
}
