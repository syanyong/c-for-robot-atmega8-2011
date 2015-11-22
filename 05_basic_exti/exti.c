/*--- Include ------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <compat/deprecated.h>

#define F_CPU 1000000
#include <util/delay.h>

char toggle = 1;

int main(){
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRD = 0x00;

	MCUCR = (1<<ISC01)|(0<<ISC00);	
	GICR  = (1<<INT0);
	sei();

	while(1)
	{	
		sbi(PORTB,0);
		_delay_ms(500);
		cbi(PORTB,0);
		_delay_ms(500);
	}

	return 0;
}

ISR(INT0_vect){
	if(toggle)
	{
		sbi(PORTB,1);
	}
	else{
		cbi(PORTB,1);
	}
	toggle = !toggle;
}
