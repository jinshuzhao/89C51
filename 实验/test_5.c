#include<reg51.h>
#define uchar unsigned char
void delay()
{ uchar m,n,k;
 for(m=20;m>0;m--)
 for(k=40;k>0;k--)
 for(n=248;n>0;n--);
}
void display()
{uchar i,j;
  for(i=0x01;i<0x80;i<<=1) //两盏灯亮改i=0x03;i<0xc0
	 {P0=~i;
	  delay();
	 } 
  for(j=0x80;j>0x01;j>>=1) //两盏灯亮改i=0xc0;i<0x03
	 {P0=~j;
	  delay();
	 }
}
void main()
{while(1)
  {
   display();
  }
}