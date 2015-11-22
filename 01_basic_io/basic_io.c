#include <avr/io.h>
#include <compat/deprecated.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void delay_ms(unsigned int i)
{
	while(i-->0)
	{
		_delay_ms(1);
	}
}

int main()
{
	DDRB = 0xFF;
	PORTB = 0x00;
	while(1)
	{
		PORTB = 0xFF;
		delay_ms(1000);
		PORTB = 0x00;
		delay_ms(1000);
	}
	return 0;
}
