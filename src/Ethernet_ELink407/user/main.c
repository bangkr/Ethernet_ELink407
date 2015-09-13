#include "main.h"

#define SYSTEMTICK_PERIOD_MS  10
uint32_t timingdelay;
__IO u32 LocalTime=0; 

 


int main(void)
{

	COM1Init(115200);
	
	init_delay();
	
	ETH_BSP_Config();
	
 

	LwIP_Init();
	httpd_init();
  while (1)
  {  
    	if(ETH_CheckFrameReceived())//����Ƿ��յ����ݰ�
    	{ 
      		LwIP_Pkt_Handle();//�������ݰ�
    	}
    	LwIP_Periodic_Handle(LocalTime);
  }  
}

void Delay(uint32_t nCount)
{
  	timingdelay=LocalTime+nCount;  
  	while(timingdelay>LocalTime);
}

void Time_Update(void)
{
  	LocalTime+=SYSTEMTICK_PERIOD_MS;
}


