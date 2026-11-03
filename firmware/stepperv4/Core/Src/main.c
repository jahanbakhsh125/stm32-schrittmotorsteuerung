
#include "general.h"
#include "rotary.h"

#include "stepper.h"



int main(void){


	X_System_Init();
	X_Clock_Init();



	stepper_init();

	stepper_start(9600,50, __DIR_CW);








	while(1){

	}
}
