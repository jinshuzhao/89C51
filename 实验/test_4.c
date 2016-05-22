#include<reg51.h>
#define uchar unsigned char
uchar k,m;
uchar num[]={0xff,0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(uchar x)
{ uchar i,j;
  for(i=x;i>0;i--)
  for(j=248;j>0;j--);
}
uchar keyscan()
{ uchar temp;
  P1=0xf0;
  temp=P1&0xf0;
  if(temp!=0xf0)
  { delay(10);
   if(temp!=0xf0)
   {   P1=0xfe;
	   temp=P1;
	  switch(temp)
		  {	
		   case 0xee:k=1;break;
		   case 0xde:k=2;break;
		   case 0xbe:k=3;break;
		   case 0x7e:k=4;break;
		  }
	   P1=0xfd;
	   temp=P1;
	  switch(temp)
		  {	
		   case 0xed:k=5;break;
		   case 0xdd:k=6;break;
		   case 0xbd:k=7;break;
		   case 0x7d:k=8;break;
		  }
   }
 }
  return k;
}
void display()
{
  P0=num[m];
}
void main()
{ while(1)
  {m=keyscan();
   display();
  }
}
