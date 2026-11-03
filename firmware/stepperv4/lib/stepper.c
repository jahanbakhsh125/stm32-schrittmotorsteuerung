#include "stepper.h"

#define __LED_OFF GPIOC->BSRR=GPIO_BSRR_BS13
#define __LED_ON GPIOC->BSRR=GPIO_BSRR_BR13

void stepper_finish(void){


	__LED_OFF;

}



void stepper_start(uint32_t pulse,uint16_t RPM,uint8_t DIR){

	if(pulse == 0){
		return;
	}

	uint32_t R=0;
	uint16_t Q=0;

	Q = pulse / 65536U;
	R = pulse % 65536U;

	if(R==0){
		R=65536U;
		Q=Q-1;
	}


	if(DIR){
		__PB5_HIGH;
	}else{
		__PB5_LOW;
	}


	TIM3->PSC = (uint16_t)(337500/(1+RPM));
	TIM3->EGR = TIM_EGR_UG;

	TIM4->CNT = Q;
	TIM2->CNT = R-1;


	__LED_ON;

	TIM3->CR1 |= TIM_CR1_CEN;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM4->CR1 |= TIM_CR1_CEN;

}

void stepper_init(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH &= ~(GPIO_CRH_MODE13|GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13_1;

	__LED_OFF;

	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	//PB4 AF PP
	GPIOB->CRL &= ~(GPIO_CRL_MODE4|GPIO_CRL_CNF4);
	GPIOB->CRL |= (GPIO_CRL_MODE4_1|GPIO_CRL_CNF4_1);

	//PB5 GP PP
	GPIOB->CRL &= ~(GPIO_CRL_MODE5|GPIO_CRL_CNF5);
	GPIOB->CRL |= GPIO_CRL_MODE5_1;

	AFIO->MAPR &= ~AFIO_MAPR_TIM3_REMAP;
	AFIO->MAPR |= AFIO_MAPR_TIM3_REMAP_1;

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	TIM3->CR1 &= ~(TIM_CR1_CMS|TIM_CR1_DIR);
	TIM3->PSC = 0xFFFF;
	TIM3->ARR = (uint16_t)1;
	TIM3->CCR1=(uint16_t)1;

	TIM3->CCMR1 |= TIM_CCMR1_CC1S;
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM3->CCMR1 &= ~TIM_CCMR1_CC1S;
	TIM3->CCMR1 |= TIM_CCMR1_OC1M;
	TIM3->CCER   &= ~TIM_CCER_CC1P;
	TIM3->CCER |= TIM_CCER_CC1E;

	TIM3->EGR = TIM_EGR_UG;
	TIM3->SR = ~TIM_SR_UIF;


	//TIM2 TIMBase
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->CR1 = 0x0U;
	TIM2->CR1 |= TIM_CR1_DIR;
	TIM2->PSC = 0x0;
	TIM2->ARR = 0xffff;




	//TIM4 TIMBase
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	TIM4->CR1 = 0x0U;
	TIM4->CR1 |= (TIM_CR1_DIR|TIM_CR1_OPM);
	TIM4->PSC = 0x0;
	TIM4->ARR = 0xffff;



	//1st master(TIM3)/slave(TIM2) TIM2 counts number of TIM3 UE

	//TIM3-Master TRGO:update MMS=0b010
	TIM3->CR2 &= ~TIM_CR2_MMS;
	TIM3->CR2 |= TIM_CR2_MMS_1;

	//TIM2-Slave Trigger coming from TIM3 : ITR2 TS=0b010
	TIM2->SMCR &= ~TIM_SMCR_TS;
	TIM2->SMCR |= TIM_SMCR_TS_1;

	//TIM2-Slave TRGI clocks the counter : external clock mode1 SMS=0b111
	TIM2->SMCR |= TIM_SMCR_SMS;


	//2nd master(TIM2)/slave(TIM4) TIM4 count TIM2 update event

	//TIM2-Master TRGO:update MMS=0b010
	TIM2->CR2 &= ~TIM_CR2_MMS;
	TIM2->CR2 |= TIM_CR2_MMS_1;

	//TIM4-Slave Trigger coming from TIM2 : ITR1 TS=0b001
	TIM4->SMCR &= ~TIM_SMCR_TS;
	TIM4->SMCR |= TIM_SMCR_TS_0;

	//TIM4-Slave TRGI clocks the counter : external clock mode1 SMS=0b111
	TIM4->SMCR |= TIM_SMCR_SMS;

	//3rd master(TIM4)/slave(TIM3) TIM4 Stops TIM3

	//TIM4-Master TRGO:enable signal MMS=0b001
	TIM4->CR2 &= ~TIM_CR2_MMS;
	TIM4->CR2 |= TIM_CR2_MMS_0;

	//TIM3-Slave Trigger coming from TIM4 : ITR3 TS=0b011
	TIM3->SMCR &= ~TIM_SMCR_TS;
	TIM3->SMCR |= (TIM_SMCR_TS_0|TIM_SMCR_TS_1);

	//TIM3-Slave Gated mode : SMS=0b101
	TIM3->SMCR &= ~TIM_SMCR_SMS;
	TIM3->SMCR |= (TIM_SMCR_SMS_2|TIM_SMCR_SMS_0);




	//TIM4 Update interrupt
	TIM4->SR = ~TIM_SR_UIF;
	TIM4->DIER |= TIM_DIER_UIE;

	X_CallBack_TIM4.UP = stepper_finish;

	uint32_t PG= NVIC_GetPriorityGrouping();
	NVIC_SetPriority(TIM4_IRQn,NVIC_EncodePriority(PG, 5, 0));
	NVIC_EnableIRQ(TIM4_IRQn);



}



