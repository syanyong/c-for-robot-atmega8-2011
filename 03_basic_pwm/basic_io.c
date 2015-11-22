/* Include */
#include <avr/io.h>
#include <compat/deprecated.h>


/* Function */



/*
	Main Function.
*/
int main()
{
	DDRB = 0xFE;	
	PORTB = 0x00;

	DDRC = 0xFF;
	PORTC = 0x00;

	/* PWM */
	TCCR1A = 0xA2;
	TCCR1B = 0x11;
	ICR1 = 10000;

	OCR1A = 9000;
	OCR1B = 9000;
	
	sbi(PORTC,0);
	cbi(PORTC,1);

	while(1)
	{
		if( bit_is_clear(PINB,0) )
		{
			sbi(PORTC,0);
			cbi(PORTC,1);
			cbi(PORTC,2);
			sbi(PORTC,3);	
		}
		else
		{
			sbi(PORTC,0);
			cbi(PORTC,1);
			sbi(PORTC,2);
			cbi(PORTC,3);
		}
	}

	return 0;
}
