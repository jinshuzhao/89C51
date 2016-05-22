#include<reg52.h>


void main(void){

unsigned char i;
void delay1s(void);

	while(1){
		P1 = 0xfe;
		for(i=0;i<8;i++){
			delay1s();
			P1<<=1;
			P1 |=0x01;
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