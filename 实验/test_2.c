#include <reg51.h>     
#define uint unsigned int
#define uchar unsigned char

sbit DQ =P2^4 ;//定义通信端口  
unsigned char tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xc6};

void delay(unsigned int i)   //延时子程序 
{
    while(i--);
}
//DB18B20初始化函数
Init_DS18B20(void)
{
unsigned char x=0;
DQ = 1;    //DQ复位
delay(8);  //稍做延时
DQ = 0;    //单片机将DQ拉低
delay(80); //精确延时 大于 480us
DQ = 1;    //拉高总线  
delay(14);
x=DQ;      //稍做延时后如果x=0则初始化成功 x=1则初始化失败
delay(20);
}  
ReadOneChar(void)   //读一个字节  
{
unsigned char i=0;
unsigned char dat = 0;
for (i=8;i>0;i--)
{
  DQ = 0; // 给脉冲信号
  dat>>=1;  // 逐位右移 
  DQ = 1; // 给脉冲信号   
  if(DQ)    //DQ为1 时，表示收到高电平1
  dat|=0x80;      //  把收到的高电平置给DAT的最高位
  delay(5);
}
return(dat);      
}
//写一个字节  
WriteOneChar(unsigned char dat)
{
unsigned char i=0;
for (i=8; i>0; i--)
{
  DQ = 0;
  DQ = dat&0x01;      //把要发送的高电平或者低电平给DQ 发送出去  
  delay(5);
  DQ = 1;
  dat>>=1;      //逐位右移
}
delay(4);
}                        
int  ReadTemperature()  //读取温度
{        
unsigned char a=0;
unsigned char b=0;
unsigned int t=0;
float tt=0;
Init_DS18B20();
WriteOneChar(0xCC); // 跳过读序号列号的操作     
WriteOneChar(0x44); // 启动温度转换
Init_DS18B20();
WriteOneChar(0xCC); //跳过读序号列号的操作           
WriteOneChar(0xBE); //读取温度寄存器等（共可读9个寄存器） 前两个就是温度             
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
 while(1) //主循环
{ temp=ReadTemperature();
 display_tempmain(temp);
}
}