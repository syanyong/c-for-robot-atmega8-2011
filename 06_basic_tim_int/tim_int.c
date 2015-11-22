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

	TCCR0 = (1<<CS02)|(0<<CS01)|(1<<CS00);
	TIMSK = (1<<TOIE0);
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

ISR(TIMER0_OVF_vect){
	if(toggle)
	{
		sbi(PORTB,1);
	}
	else{
		cbi(PORTB,1);
	}
	toggle = !toggle;
}
