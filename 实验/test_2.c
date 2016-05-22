#include <reg51.h>     
#define uint unsigned int
#define uchar unsigned char

sbit DQ =P2^4 ;//����ͨ�Ŷ˿�  
unsigned char tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xc6};

void delay(unsigned int i)   //��ʱ�ӳ��� 
{
    while(i--);
}
//DB18B20��ʼ������
Init_DS18B20(void)
{
unsigned char x=0;
DQ = 1;    //DQ��λ
delay(8);  //������ʱ
DQ = 0;    //��Ƭ����DQ����
delay(80); //��ȷ��ʱ ���� 480us
DQ = 1;    //��������  
delay(14);
x=DQ;      //������ʱ�����x=0���ʼ���ɹ� x=1���ʼ��ʧ��
delay(20);
}  
ReadOneChar(void)   //��һ���ֽ�  
{
unsigned char i=0;
unsigned char dat = 0;
for (i=8;i>0;i--)
{
  DQ = 0; // �������ź�
  dat>>=1;  // ��λ���� 
  DQ = 1; // �������ź�   
  if(DQ)    //DQΪ1 ʱ����ʾ�յ��ߵ�ƽ1
  dat|=0x80;      //  ���յ��ĸߵ�ƽ�ø�DAT�����λ
  delay(5);
}
return(dat);      
}
//дһ���ֽ�  
WriteOneChar(unsigned char dat)
{
unsigned char i=0;
for (i=8; i>0; i--)
{
  DQ = 0;
  DQ = dat&0x01;      //��Ҫ���͵ĸߵ�ƽ���ߵ͵�ƽ��DQ ���ͳ�ȥ  
  delay(5);
  DQ = 1;
  dat>>=1;      //��λ����
}
delay(4);
}                        
int  ReadTemperature()  //��ȡ�¶�
{        
unsigned char a=0;
unsigned char b=0;
unsigned int t=0;
float tt=0;
Init_DS18B20();
WriteOneChar(0xCC); // ����������кŵĲ���     
WriteOneChar(0x44); // �����¶�ת��
Init_DS18B20();
WriteOneChar(0xCC); //����������кŵĲ���           
WriteOneChar(0xBE); //��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�             
a=ReadOneChar();
b=ReadOneChar();
t=b;
t<<=8;
t=t|a;
return(t);
} 

void display_tempmain(unsigned int i) 
{
float temp ,V;
unsigned char xiaoshu;
unsigned int zhengshu;
if((0xf000&i)==0xf000)
    {
     i=~i+1;	
     P0=0xff;
     P0=tab[10];
     P3=0x01;
     delay(700);
      }
if((0xf000&i)!=0xf000)
    {
	  P0=0xff; 
      P0=tab[zhengshu/100];
      P3=0x02;
      delay(700);
	  }

 V=	0x000f & i ;
 temp = V * 10.0*0.0625+0.375;
 xiaoshu = temp;
 zhengshu= i>>4;

 P0=0xff;
 P0=tab[zhengshu/10%10];
 P3=0x04;
 delay(700);

 P0=0xff;
 P0=tab[zhengshu%10]&0x7f;
 P3=0x08;
 delay(700);

 P0=0xff;
 P0=tab[xiaoshu];
 P3=0x10;
 delay(700);

 P0=0xff;
 P0=tab[11];
 P3=0x20;
 delay(700);

 P3=0x00;

}

void main(void)
{unsigned int temp;
 while(1) //��ѭ��
{ temp=ReadTemperature();
 display_tempmain(temp);
}
}