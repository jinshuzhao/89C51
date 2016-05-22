#include<reg52.h>

void Delay(unsigned int t);


void main(void){
	unsigned int CYCLE=800,PWM_LOW=0;

	while(1){
		P1 = 0xff;
		Delay(60000);
		for(PWM_LOW=1;PWM_LOW<CYCLE;PWM_LOW++){
			P1 = 0x00;
			Delay(PWM_LOW);
			P1 = 0xff;
			Delay(CYCLE - PWM_LOW);	
		}

		P1 = 0x00;
		for(PWM_LOW=CYCLE - 1;PWM_LOW>0;PWM_LOW--){
			P1 = 0x00;
			Delay(PWM_LOW);
			P1 = 0xff;
			Delay(CYCLE - PWM_LOW);	
		}

	}
}

void Delay(unsigned int t)
{
 while(--t);
}