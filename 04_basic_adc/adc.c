/*--- Include ------------------------------------------------*/
#include <avr/io.h>
#include <compat/deprecated.h>

/**
  * @Function->   Initial Analog to Digital Convertor
  */
void InitADC(void){										

	ADCSRA 	= (1 << 7)|(0 << 5);					
	ADCSRA |= (0 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);

}

/**
  * @Function->   Initial Analog to Digital Convertor
  */
unsigned int ReadADC(volatile unsigned char ucMUX){		

	ADMUX = (0 << REFS1)|(1 << REFS0)|(ucMUX);
	ADCSRA |= (1 << ADSC);
	while(!(ADCSRA&(1 << ADIF)));

	return ADCW;

}

/**
  * @Function->   Main Program.
  */
int main(){
	InitADC();

	DDRD = 0xFF;
	while(1){

		if((ReadADC(0) >= 300)&&(ReadADC(0) <= 1023))
		{
			sbi(PORTD,0);
		}
		else
		{
			cbi(PORTD,0);
		}


	}
	return 0;
}
