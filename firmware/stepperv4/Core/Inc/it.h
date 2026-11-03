#pragma once



 typedef struct{
 	void (*UP)  (void);
 	void (*CC1) (void);
 	void (*CC2) (void);
 	void (*CC3) (void);
 	void (*CC4) (void);
 	void (*COM) (void);
 	void (*TRG) (void);
 	void (*BRK) (void);
 } TIM1_CallBack_Typedef;

 typedef struct{
 	void (*UP)  (void);
 	void (*CC1) (void);
 	void (*CC2) (void);
 	void (*CC3) (void);
 	void (*CC4) (void);
 	void (*TRG) (void);
 } TIM2_CallBack_Typedef;

 // Typedef for DMA interrupt function pointers
 typedef struct{
 	void (*HT)  (void);
 	void (*TC)  (void);
 	void (*TE)  (void);
 } DMA_CallBack_Typedef;


extern void (*X_CallBack_EXTI[18])(void);
extern TIM2_CallBack_Typedef  X_CallBack_TIM2;
extern TIM2_CallBack_Typedef  X_CallBack_TIM3;
extern TIM2_CallBack_Typedef  X_CallBack_TIM4;

extern TIM1_CallBack_Typedef  X_CallBack_TIM1;

extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch1;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch2;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch3;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch4;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch5;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch6;
extern DMA_CallBack_Typedef   X_CallBack_DMA1_Ch7;
