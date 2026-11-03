#include "general.h"

#undef NULL
#define NULL 0
#define __CALL(F_PTR) ( (F_PTR != NULL) ? F_PTR() : (void)0U)


static inline void X_EXTI_IRQHandler(uint32_t EXTI_PR_MSK,uint32_t EXTI_LINE){

	if(EXTI->PR & EXTI_PR_MSK){
		EXTI->PR = EXTI_PR_MSK;

		__CALL(X_CallBack_EXTI[EXTI_LINE]);

	}

}


static inline void X_TIM2_IRQHandler(TIM_TypeDef * TIM,TIM2_CallBack_Typedef * Callback){

	if( (TIM->SR & TIM_SR_UIF) && (TIM->DIER & TIM_DIER_UIE) ){
		TIM->SR = ~TIM_SR_UIF;
		__CALL(Callback->UP);

	}

	if( (TIM->SR & TIM_SR_CC1IF) && (TIM->DIER & TIM_DIER_CC1IE) ){
		TIM->SR = ~TIM_SR_CC1IF;
		__CALL(Callback->CC1);
	}

	if( (TIM->SR & TIM_SR_CC2IF) && (TIM->DIER & TIM_DIER_CC2IE) ){
		TIM->SR = ~TIM_SR_CC2IF;
		__CALL(Callback->CC2);
	}

	if( (TIM->SR & TIM_SR_CC3IF) && (TIM->DIER & TIM_DIER_CC3IE) ){
		TIM->SR = ~TIM_SR_CC3IF;
		__CALL(Callback->CC3);
	}

	if( (TIM->SR & TIM_SR_CC4IF) && (TIM->DIER & TIM_DIER_CC4IE) ){
		TIM->SR = ~TIM_SR_CC4IF;
		__CALL(Callback->CC4);
	}

	if( (TIM->SR & TIM_SR_TIF) && (TIM->DIER & TIM_DIER_TIE) ){
		TIM->SR = ~TIM_SR_TIF;
		__CALL(Callback->TRG);
	}


}

// X_IRQHandler for TIM1_BRK

static inline void X_TIM1_BRK_IRQHandler(void){
	TIM1->SR = ~TIM_SR_BIF;
	__CALL( X_CallBack_TIM1.BRK);
}

// X_IRQHandler for TIM1_UP

static inline void X_TIM1_UP_IRQHandler(void){
		TIM1->SR = ~TIM_SR_UIF;
		__CALL( X_CallBack_TIM1.UP);
}

// X_IRQHandler for TIM1_TRG_COM
static inline void X_TIM1_TRG_COM_IRQHandler(void){

	if( (TIM1->DIER & TIM_DIER_TIE) && (TIM1->SR & TIM_SR_TIF) ){
		TIM1->SR = ~TIM_SR_TIF;
		__CALL( X_CallBack_TIM1.TRG );}

	if( (TIM1->DIER & TIM_DIER_COMIE) && (TIM1->SR & TIM_SR_COMIF) ){
		TIM1->SR = ~TIM_SR_COMIF;
		__CALL( X_CallBack_TIM1.COM);}

}

static inline void X_TIM1_CC_IRQHandler(void){

	if( (TIM1->DIER & TIM_DIER_CC1IE) && (TIM1->SR & TIM_SR_CC1IF)){
		TIM1->SR = ~TIM_SR_CC1IF;
		__CALL(X_CallBack_TIM1.CC1);}

	if( (TIM1->DIER & TIM_DIER_CC2IE) && (TIM1->SR & TIM_SR_CC2IF)){
		TIM1->SR = ~TIM_SR_CC2IF;
		__CALL(X_CallBack_TIM1.CC2);}

	if( (TIM1->DIER & TIM_DIER_CC3IE) && (TIM1->SR & TIM_SR_CC3IF)){
		TIM1->SR = ~TIM_SR_CC3IF;
		__CALL(X_CallBack_TIM1.CC3);}

	if( (TIM1->DIER & TIM_DIER_CC4IE) && (TIM1->SR & TIM_SR_CC4IF)){
		TIM1->SR = ~TIM_SR_CC4IF;
		__CALL(X_CallBack_TIM1.CC4);}
}



static inline void X_DMA1_Channel1_IRQHandler(void){

  	if( (DMA1->ISR & DMA_ISR_TCIF1) && (DMA1_Channel1->CCR & DMA_CCR_TCIE) ){
  			DMA1->IFCR = DMA_IFCR_CTCIF1;
  			__CALL( X_CallBack_DMA1_Ch1.TC);}

  	if( (DMA1->ISR & DMA_ISR_HTIF1) && (DMA1_Channel1->CCR & DMA_CCR_HTIE) ){
  			DMA1->IFCR = DMA_IFCR_CHTIF1;
  			__CALL( X_CallBack_DMA1_Ch1.HT);}

  	if( (DMA1->ISR & DMA_ISR_TEIF1) && (DMA1_Channel1->CCR & DMA_CCR_TEIE) ){
  			DMA1->IFCR = DMA_IFCR_CTEIF1;
  			__CALL( X_CallBack_DMA1_Ch1.TE);}
}
 // X_IRQHandler for DMA1_Channel2
static inline void X_DMA1_Channel2_IRQHandler(void){

  	if( (DMA1->ISR & DMA_ISR_TCIF2) && (DMA1_Channel2->CCR & DMA_CCR_TCIE) ){
  			DMA1->IFCR = DMA_IFCR_CTCIF2;
  			__CALL( X_CallBack_DMA1_Ch2.TC);}

  	if( (DMA1->ISR & DMA_ISR_HTIF2) && (DMA1_Channel2->CCR & DMA_CCR_HTIE) ){
  			DMA1->IFCR = DMA_IFCR_CHTIF2;
  			__CALL( X_CallBack_DMA1_Ch2.HT);}

  	if( (DMA1->ISR & DMA_ISR_TEIF2) && (DMA1_Channel2->CCR & DMA_CCR_TEIE) ){
  			DMA1->IFCR = DMA_IFCR_CTEIF2;
  			__CALL( X_CallBack_DMA1_Ch2.TE);}
}
 // X_IRQHandler for DMA1_Channel3
static inline void X_DMA1_Channel3_IRQHandler(void){

	if( (DMA1->ISR & DMA_ISR_TCIF3) && (DMA1_Channel3->CCR & DMA_CCR_TCIE) ){
		DMA1->IFCR = DMA_IFCR_CTCIF3;
  		__CALL( X_CallBack_DMA1_Ch3.TC);}

  	if( (DMA1->ISR & DMA_ISR_HTIF3) && (DMA1_Channel3->CCR & DMA_CCR_HTIE) ){
  			DMA1->IFCR = DMA_IFCR_CHTIF3;
  			__CALL( X_CallBack_DMA1_Ch3.HT);}

  	if( (DMA1->ISR & DMA_ISR_TEIF3) && (DMA1_Channel3->CCR & DMA_CCR_TEIE) ){
  			DMA1->IFCR = DMA_IFCR_CTEIF3;
  			__CALL( X_CallBack_DMA1_Ch3.TE);}
 }


static inline void X_DMA1_Channel4_IRQHandler(void){

 	if( (DMA1->ISR & DMA_ISR_TCIF4) && (DMA1_Channel4->CCR & DMA_CCR_TCIE) ){
 			DMA1->IFCR = DMA_IFCR_CTCIF4;
 			__CALL( X_CallBack_DMA1_Ch4.TC);}

 	if( (DMA1->ISR & DMA_ISR_HTIF4) && (DMA1_Channel4->CCR & DMA_CCR_HTIE) ){
 			DMA1->IFCR = DMA_IFCR_CHTIF4;
 			__CALL( X_CallBack_DMA1_Ch4.HT);}

 	if( (DMA1->ISR & DMA_ISR_TEIF4) && (DMA1_Channel4->CCR & DMA_CCR_TEIE) ){
 			DMA1->IFCR = DMA_IFCR_CTEIF4;
 			__CALL( X_CallBack_DMA1_Ch4.TE);}
}

static inline void X_DMA1_Channel5_IRQHandler(void){

  	if( (DMA1->ISR & DMA_ISR_TCIF5) && (DMA1_Channel5->CCR & DMA_CCR_TCIE) ){
  			DMA1->IFCR = DMA_IFCR_CTCIF5;
  			__CALL( X_CallBack_DMA1_Ch5.TC);}

  	if( (DMA1->ISR & DMA_ISR_HTIF5) && (DMA1_Channel5->CCR & DMA_CCR_HTIE) ){
  			DMA1->IFCR = DMA_IFCR_CHTIF5;
  			__CALL( X_CallBack_DMA1_Ch5.HT);}

  	if( (DMA1->ISR & DMA_ISR_TEIF5) && (DMA1_Channel5->CCR & DMA_CCR_TEIE) ){
  			DMA1->IFCR = DMA_IFCR_CTEIF5;
  			__CALL( X_CallBack_DMA1_Ch5.TE);}
}

static inline void X_DMA1_Channel6_IRQHandler(void){

 	if( (DMA1->ISR & DMA_ISR_TCIF6) && (DMA1_Channel6->CCR & DMA_CCR_TCIE) ){
 			DMA1->IFCR = DMA_IFCR_CTCIF6;
 			__CALL( X_CallBack_DMA1_Ch6.TC);}

 	if( (DMA1->ISR & DMA_ISR_HTIF6) && (DMA1_Channel6->CCR & DMA_CCR_HTIE) ){
 			DMA1->IFCR = DMA_IFCR_CHTIF6;
 			__CALL( X_CallBack_DMA1_Ch6.HT);}

 	if( (DMA1->ISR & DMA_ISR_TEIF6) && (DMA1_Channel6->CCR & DMA_CCR_TEIE) ){
 			DMA1->IFCR = DMA_IFCR_CTEIF6;
 			__CALL( X_CallBack_DMA1_Ch6.TE);}
}

static inline void X_DMA1_Channel7_IRQHandler(void){

 	if( (DMA1->ISR & DMA_ISR_TCIF7) && (DMA1_Channel7->CCR & DMA_CCR_TCIE) ){
 			DMA1->IFCR = DMA_IFCR_CTCIF7;
 			__CALL( X_CallBack_DMA1_Ch7.TC);}

 	if( (DMA1->ISR & DMA_ISR_HTIF7) && (DMA1_Channel7->CCR & DMA_CCR_HTIE) ){
 			DMA1->IFCR = DMA_IFCR_CHTIF7;
 			__CALL( X_CallBack_DMA1_Ch7.HT);}

 	if( (DMA1->ISR & DMA_ISR_TEIF7) && (DMA1_Channel7->CCR & DMA_CCR_TEIE) ){
 			DMA1->IFCR = DMA_IFCR_CTEIF7;
 			__CALL( X_CallBack_DMA1_Ch7.TE);}
}
