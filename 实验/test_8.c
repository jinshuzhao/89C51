#include<reg52.h>


void main(void){
unsigned char i;
void delay1s(void);

while(1){
	P1=0xfc;
	for(i=0;i<7;i++){
		delay1s();
		P1 <<=1;
		P1 = P1|0x01;
	}

	P1=0x3f;
	for(i=0;i<7;i++){
		delay1s();
		P1 >>=1;
		P1 = P1|0x80;
	}

	for(i=0;i<3;i++){
		P1 = 0xff;
		delay1s();
		P1 = 0x00;
		delay1s();
	}

}

}

void delay1s(void)
{
	unsigned char h,i,j,k;
	for(h=5;h>0;h--)
	for(i=4;i>0;i--)
	for(j=116;j>0;j--)
	for(k=214;k>0;k--);
}