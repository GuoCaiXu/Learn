# include "stm32f10x.h"
# include "./key/bsp_exti_key.h"
# include "./led/bsp_led.h"
# include "./iwdg/bsp_iwdg.h"

void delay(uint32_t n){
	while(n --);
}

int main(void){

	/*配置LED GPIO，并关闭LED*/
	LED_GPIO_Config();
	LED2_OFF;
	LED1_OFF;

	delay(0x8fffff);
	/*----------------------------------------------------*/
	/*检查是否为独立看门狗复位*/
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET){
	/*LED1亮*/
	LED1_ON;

	/*清除标志*/
	RCC_ClearFlag();

	/*如果一直不喂狗，会一直复位，加上前面的延时，会看到LED1闪烁
	在1s 时间内喂狗的话。则会持续亮绿灯*/
	}
	else{
		/*不是独立开门狗复位(可能为上电复位或者手动案件复位之类的)*/
		/*LED2闪烁一下*/
		LED2_ON;
		delay(0x0fffff);
		LED2_OFF;
		delay(0x0fffff);
	}

	/*----------------------------------------------------*/

	/*配置按键GPIO*/
	Key_GPIO_Config();
	/*IWDG 1s 超时溢出*/
	IWDG_Config(IWDG_Prescaler_64, 625);

	//while部分是我们在项目中具体需要写的代码，这部分的程序可以用独立看门狗来监控
    //如果我们知道这部分代码的执行时间，比如是500ms，那么我们可以设置独立看门狗的
	//溢出时间是600ms，比500ms多一点，如果要被监控的程序没有跑飞正常执行的话，那么
	//执行完毕之后就会执行喂狗的程序，如果程序跑飞了那程序就会超时，到达不了喂狗
	//的程序,此时就会产生系统复位。但是也不排除程序跑飞了又跑回来了，刚好喂狗了，
	//歪打正着。所以要想更精确的监控程序，可以使用窗口看门狗，窗口看门狗规定必须在
	//规定的窗口时间内喂狗。
	while(1){
		/*这里添加需要被监控的代码，如果有就去掉按键模拟喂狗，把按键扫描程序去掉*/

		/*----------------------------------------------------*/

		if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON){
			/*喂狗，如果不喂狗，系统则会复位，LED1则会灭一次，如果在1s
			时间内准时喂狗的话，则LED2会常亮*/
			IWDG_Feed();
			/*喂狗后LED2亮*/
			LED2_ON;
		}
	}
}
