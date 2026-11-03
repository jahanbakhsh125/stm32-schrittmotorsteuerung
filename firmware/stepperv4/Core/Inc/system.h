#pragma once


#include "stm32f103xb.h"


// CORTEX Preemption Priority Group
#define NVIC_PRIORITYGROUP_0__0_pre_4_sub               0x7U
#define NVIC_PRIORITYGROUP_1__1_pre_3_sub               0x6U
#define NVIC_PRIORITYGROUP_2__2_pre_2_sub               0x5U
#define NVIC_PRIORITYGROUP_3__3_pre_1_sub               0x4U
#define NVIC_PRIORITYGROUP_4__4_pre_0_sub               0x3U


#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)
#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)
#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
#define  ARM_CYCLE (*(uint32_t *)0xE0001004)


#define EXTI_LINE_0                                     0x0U
#define EXTI_LINE_1                                     0x1U
#define EXTI_LINE_2                                     0x2U
#define EXTI_LINE_3                                     0x3U
#define EXTI_LINE_4                                     0x4U
#define EXTI_LINE_5                                     0x5U
#define EXTI_LINE_6                                     0x6U
#define EXTI_LINE_7                                     0x7U
#define EXTI_LINE_8                                     0x8U
#define EXTI_LINE_9                                     0x9U
#define EXTI_LINE_10                                     0xAU
#define EXTI_LINE_11                                     0xBU
#define EXTI_LINE_12                                     0xCU
#define EXTI_LINE_13                                     0xDU
#define EXTI_LINE_14                                     0xEU
#define EXTI_LINE_15                                     0xFU
#define EXTI_LINE_16                                     0x10U
#define EXTI_LINE_17                                     0x11U
#define EXTI_LINE_18                                     0x12U




void X_System_Init(void);
void X_Clock_Init(void);
void DWT_Init(void);
void X_Delay_ms(uint32_t Delay);

