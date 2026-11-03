#include "system.h"


__attribute__((weak)) void _close(void){}
__attribute__((weak)) void _lseek(void){}
__attribute__((weak)) void _read(void){}
__attribute__((weak)) void _write(void){}

volatile uint32_t  uwTick;
uint32_t SystemCoreClock=72000000 ;

void DWT_Init(void){
	if (ARM_CM_DWT_CTRL != 0) {

		ARM_CM_DEMCR      |= 1 << 24;
		ARM_CM_DWT_CYCCNT  = 0;
		ARM_CM_DWT_CTRL   |= 1 << 0;
	}
}

void X_Delay_ms(uint32_t Delay){

	uint32_t tickstart = uwTick;
	uint32_t wait = Delay;

	while ((uwTick - tickstart) < wait);
}

void X_System_Init(void){

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_1;

	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4__4_pre_0_sub);

	// Config systick
	SysTick_Config( SystemCoreClock/1000);

	// systick interrupt
	uint32_t prioritygroup = NVIC_GetPriorityGrouping();
	NVIC_SetPriority(SysTick_IRQn , NVIC_EncodePriority(prioritygroup, 0, 0));


}
void X_Clock_Init(void){

	volatile uint32_t counter=0;

	RCC->CR &= ~RCC_CR_HSEBYP;
	RCC->CR |= RCC_CR_HSEON;

	do{
		counter++;
	}while( ((RCC->CR & RCC_CR_HSERDY)==0x0) && (counter<0x500) );

	if( (RCC->CR & RCC_CR_HSERDY)!=0x0  ){

		FLASH->ACR |= FLASH_ACR_PRFTBE;

		FLASH->ACR &= ~FLASH_ACR_LATENCY;
		FLASH->ACR |= FLASH_ACR_LATENCY_1;

		RCC->CFGR &= ~RCC_CFGR_HPRE;

		RCC->CFGR &= ~RCC_CFGR_PPRE1;
		RCC->CFGR |= RCC_CFGR_PPRE1_2;

		RCC->CFGR &= ~RCC_CFGR_PPRE2;

		RCC->CFGR &= ~RCC_CFGR_ADCPRE;
		RCC->CFGR |= RCC_CFGR_ADCPRE_1;

		RCC->CFGR &= ~RCC_CFGR_USBPRE;

		RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;

		RCC->CFGR |= RCC_CFGR_PLLSRC;

		RCC->CFGR &= ~RCC_CFGR_PLLMULL;
		RCC->CFGR |= RCC_CFGR_PLLMULL9;

		RCC->CR |= RCC_CR_PLLON;

		while( (RCC->CR & RCC_CR_PLLRDY)==0x0 );

		RCC->CFGR &= ~RCC_CFGR_SW;
		RCC->CFGR |= RCC_CFGR_SW_PLL;

		while( (RCC->CFGR & RCC_CFGR_SWS) != 0x08 );

	}else{

	}


	RCC->CR |= RCC_CR_CSSON;
}


