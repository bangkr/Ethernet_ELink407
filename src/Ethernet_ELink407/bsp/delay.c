#include "delay.h"
#include "stm32f4xx.h"

unsigned int TimingDelay;

void init_delay(void)
{
	/* 
	������શ�ʱ����1us�жϣ� 
	����SysTick_Config()������CMSIS�����һ��������ʵ���������� 
		- �����Ĳ��������ؼĴ���reloadҪ����ĳ�ֵ
  	- ������શ�ʱ�������ȼ���������ȼ�15
  	- ����HCLK��Ϊϵͳ��ʱ��Դ
  	- ʹ����શ�ʱ���ж�
  	- ������શ�ʱ������ 
	*/ 
	if (SysTick_Config(SystemCoreClock / 1000000)) 
	{ 
		/* ���� */ 
		while (1); 
	} 
}

void TimingDelay_Decrement(void) 
{ 
	if (TimingDelay != 0) 
	{ 
		TimingDelay--; 
	} 
} 

void delay_ms( unsigned int mTime) 
{ 
	TimingDelay = mTime*1000; 
	while(TimingDelay != 0); 
}

void delay_us(unsigned int uTime)
{		
	TimingDelay = uTime; 
	while(TimingDelay != 0); 	 
}


void mydelay(int delaytime)
{
	delay_ms(delaytime);
	
#if 0     //ʹ�ñ�׼��ʱ����
	int i;
	
	for(;delaytime>0;delaytime--)
				for(i=0;i<1000;i++)
#endif
						;		
}  
