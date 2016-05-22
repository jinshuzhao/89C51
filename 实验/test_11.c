#include<reg52.h>

#define DataPort P0
void Delay(unsigned int t);
sbit CH1= P2^6; 
sbit CH2 = P2^7;

unsigned char code duanma[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code weima[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char i=0;

void main(void){
	while(1){
		for(i=0;i<8;i++){
			DataPort = weima[i];//仿真软件正常运行必须先点位码
			CH2 = 1;
			CH2 = 0;

			DataPort = duanma[i];
			CH1 = 1;
			CH1 = 0;
			Delay(100);	
		}
	}
}


void Delay(unsigned int t)
{
 while(--t);
}