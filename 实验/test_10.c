#include<reg52.h>

#define DataPort P0
sbit CH1= P2^6; 
sbit CH2 = P2^7;
 
void Delay(unsigned int t);


void main(void){
	while(1){
		DataPort = 0x7e;//λ����
		CH2 = 1;
		CH2 = 0;

		DataPort = 0x4f;//������
		CH1 = 1;
		CH1 = 0;
	}
	


}

void Delay(unsigned int t)
{
 while(--t);
}