
#include "stm32f10x.h"
//----------------APB2??????? ---------------------
#define RCC_APB2ENR		*((unsigned volatile int*)0x40021018)
//----------------GPIOA????? -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB????? -----------------------
#define GPIOB_CRL		*((unsigned volatile int*)0x40010C00)
#define	GPIOB_ODR		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC????? -----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR		*((unsigned volatile int*)0x4001100C)


//????
 void Delay()
 {
   u32 i=0;
   for(;i<5000000;i++);
 }
 int main(void)
 {	
	RCC_APB2ENR|=1<<2|1<<3|1<<4;			//APB2-GPIOA?GPIOB?GPIOC??????	
	
	GPIOA_CRL&=0xFFF0FFFF;		//??? ??	
	GPIOA_CRL|=0x00020000;		//PB5????
	GPIOA_ODR&=~(1<<4);			//???????
	
	GPIOB_CRL&=0xFF0FFFFF;		//??? ??	
	GPIOB_CRL|=0x00200000;		//PB5????
	GPIOB_ODR&=~(1<<5);			//???????
	 
	GPIOC_CRH&=0xF0FFFFFF;		//??? ??	
	GPIOC_CRH|=0x02000000;		//PB5????
	GPIOC_ODR&=~(1<<14);			//???????		
	 

	 

	while(1){
		//A?
		GPIOA_ODR|=1<<4;		//PB5???
	 	Delay();
		GPIOA_ODR&=~(1<<4);		//PB5???,????0,??????


		
		//B?
		GPIOB_ODR|=1<<5;		//PB5???
	 	Delay();
		GPIOB_ODR&=~(1<<5);		//PB5???,????0,??????


		
		
		//C?
		GPIOC_ODR|=1<<14;		//PB5???
	 	Delay();
		GPIOC_ODR&=~(1<<14);		//PB5???,????0,??????


		
		}
}





