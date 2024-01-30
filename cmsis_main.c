#include "main.h"
void Delay_1_Ms(void);
void Delay_Ms(uint32_t u32Delay);

void Delay_1_Ms(void)
{
	SysTick->LOAD = 7999;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while(!(SysTick->CTRL & (1 << 16))) {
	}
}
void Delay_Ms(uint32_t u32Delay)
{
	while (u32Delay) {
		Delay_1_Ms();
		--u32Delay;
	}
}

int main(void)
{
	RCC->APB2ENR |= 0xFC; /* Enable GPIO ports clocks */
	 GPIOC->CRH = 0x44344444; /* PC13 as output */

  while (1)
  {
	  Delay_Ms(500);
	  GPIOC->ODR ^= (1<<13); /* toggle  PC13 */

  }
}
