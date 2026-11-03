#include "general.h"
#include "it_functions.h"

extern uint32_t  uwTick;

void (*X_CallBack_EXTI[18])(void);
TIM2_CallBack_Typedef  X_CallBack_TIM2;
TIM2_CallBack_Typedef  X_CallBack_TIM3;
TIM2_CallBack_Typedef  X_CallBack_TIM4;
TIM1_CallBack_Typedef  X_CallBack_TIM1;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch1;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch2;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch3;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch4;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch5;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch6;
DMA_CallBack_Typedef   X_CallBack_DMA1_Ch7;

void NMI_Handler(void){
	while(1){

	}
}

void HardFault_Handler(void){
	while(1){

	}
}

void MemManage_Handler(void){
	while(1){

	}
}
void BusFault_Handler(void){
	while(1){

	}
}

void UsageFault_Handler(void){
	while(1){

	}
}

void SVC_Handler(void){}
void DebugMon_Handler(void){}

void PendSV_Handler             (void){}
void SysTick_Handler            (void){
	uwTick+=1;
}
void WWDG_IRQHandler            (void){}
void PVD_IRQHandler             (void){}
void TAMPER_IRQHandler          (void){}
void RTC_IRQHandler             (void){}
void FLASH_IRQHandler           (void){}
void RCC_IRQHandler             (void){}
void EXTI0_IRQHandler           (void){
	X_EXTI_IRQHandler(EXTI_PR_PR0,EXTI_LINE_0);
}
void EXTI1_IRQHandler           (void){
	X_EXTI_IRQHandler(EXTI_PR_PR1,EXTI_LINE_1);
}
void EXTI2_IRQHandler           (void){
	X_EXTI_IRQHandler(EXTI_PR_PR2,EXTI_LINE_2);
}
void EXTI3_IRQHandler           (void){
	X_EXTI_IRQHandler(EXTI_PR_PR3,EXTI_LINE_3);
}
void EXTI4_IRQHandler           (void){
	X_EXTI_IRQHandler(EXTI_PR_PR4,EXTI_LINE_4);
}

void DMA1_Channel1_IRQHandler(void){
	X_DMA1_Channel1_IRQHandler();
}

void DMA1_Channel2_IRQHandler(void){
	X_DMA1_Channel2_IRQHandler();
}

void DMA1_Channel3_IRQHandler(void){
	X_DMA1_Channel3_IRQHandler();
}

void DMA1_Channel4_IRQHandler(void){
	 X_DMA1_Channel4_IRQHandler();
}

void DMA1_Channel5_IRQHandler(void){
	X_DMA1_Channel5_IRQHandler();
}

void DMA1_Channel6_IRQHandler(void){
	X_DMA1_Channel6_IRQHandler();
}

void DMA1_Channel7_IRQHandler (void){
	X_DMA1_Channel7_IRQHandler();
}

void ADC1_2_IRQHandler          (void){}
void USB_HP_CAN1_TX_IRQHandler  (void){}
void USB_LP_CAN1_RX0_IRQHandler (void){}
void CAN1_RX1_IRQHandler        (void){}
void CAN1_SCE_IRQHandler        (void){}
void EXTI9_5_IRQHandler         (void){

	X_EXTI_IRQHandler(EXTI_PR_PR5,EXTI_LINE_5);
	X_EXTI_IRQHandler(EXTI_PR_PR6,EXTI_LINE_6);
	X_EXTI_IRQHandler(EXTI_PR_PR7,EXTI_LINE_7);
	X_EXTI_IRQHandler(EXTI_PR_PR8,EXTI_LINE_8);
	X_EXTI_IRQHandler(EXTI_PR_PR9,EXTI_LINE_9);
}
void TIM1_BRK_IRQHandler(void){
    X_TIM1_BRK_IRQHandler();
}

void TIM1_UP_IRQHandler(void){
    X_TIM1_UP_IRQHandler();
}

void TIM1_TRG_COM_IRQHandler(void){
    X_TIM1_TRG_COM_IRQHandler();
}

void TIM1_CC_IRQHandler(void){
    X_TIM1_CC_IRQHandler();
}
void TIM2_IRQHandler            (void){
	X_TIM2_IRQHandler(TIM2,&X_CallBack_TIM2);
}
void TIM3_IRQHandler            (void){
	X_TIM2_IRQHandler(TIM3,&X_CallBack_TIM3);
}
void TIM4_IRQHandler            (void){
	X_TIM2_IRQHandler(TIM4,&X_CallBack_TIM4);
}
void I2C1_EV_IRQHandler         (void){}
void I2C1_ER_IRQHandler         (void){}
void I2C2_EV_IRQHandler         (void){}
void I2C2_ER_IRQHandler         (void){}
void SPI1_IRQHandler            (void){}
void SPI2_IRQHandler            (void){}
void USART1_IRQHandler          (void){}
void USART2_IRQHandler          (void){}
void USART3_IRQHandler          (void){}
void EXTI15_10_IRQHandler       (void){
	X_EXTI_IRQHandler(EXTI_PR_PR10,EXTI_LINE_10);
	X_EXTI_IRQHandler(EXTI_PR_PR11,EXTI_LINE_11);
	X_EXTI_IRQHandler(EXTI_PR_PR12,EXTI_LINE_12);
	X_EXTI_IRQHandler(EXTI_PR_PR13,EXTI_LINE_13);
	X_EXTI_IRQHandler(EXTI_PR_PR14,EXTI_LINE_14);
	X_EXTI_IRQHandler(EXTI_PR_PR15,EXTI_LINE_15);

}
void RTC_Alarm_IRQHandler       (void){}
void USBWakeUp_IRQHandler       (void){}


