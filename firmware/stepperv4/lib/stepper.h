#include "general.h"

#define __DIR_CW (uint8_t)1
#define __DIR_CCW (uint8_t)0

#define __PB5_HIGH  GPIOB->BSRR = GPIO_BSRR_BS5
#define __PB5_LOW   GPIOB->BSRR = GPIO_BSRR_BR5


void stepper_start(uint32_t pulse,uint16_t RPM,uint8_t DIR);
void stepper_init(void);

