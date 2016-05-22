 #include<reg51.h>
#define uchar unsigned char
uchar number[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};
 uchar s=0,f=0,h=0;
 sbit P1_0=P1^0;
 sbit P1_6=P1^6;
 sbit P1_7=P1^7;
 sbit P1_1=P1^1;
 void main()
{
TMOD=0x01;
TH0=(65536-1000)/256;
TL0=(65536-1000)%256;
ET0=1;
EA=1;
TR0=1;
while(1);
}


void tiner0_int(void) interrupt 1
{ uchar j,m;
unsigned int k;
TH0=(65536-1000)/256;
TL0=(65536-1000)%256;
 k++;m++;
switch(j)
{
case 0:P2=0x01;P0=number[h/10];break;
case 1:P2=0x02;P0=number[h%10];break;
case 2:P2=0x04;P0=number[10];break;
case 3:P2=0x08;P0=number[f/10];break;
case 4:P2=0x10;P0=number[f%10];break;
case 5:P2=0x20;P0=number[10];break;
case 6:P2=0x40;P0=number[s/10];break;
case 7:P2=0x80;P0=number[s%10];break;
}
 j++;
if(j==8)
 j=0;
if(k==1000)
 {  k=0;
   if(P1_0==0)
  { if(s==0)
    { s=59;
	  if(f==0)
	    {f=59;
		 if(h==0)
		  h=23;
		else 
		 h--;
		}
	  else 
	   f--;
  	}
	else
    s--;
  }				  
 else if(P1_0==1)
  { s++;
    if(s==60)
    { s=0;
	  f++;
	  if(f==60)
	    {f=0;
		 h++;
		 if(h==24)
		   h=0;
  		}
    }
  }
 }
 if(m==100)
   { m=0;
    if(P1_6==0)
	  { f++;
	  if(f==60)
	    f=0;
	  }
    if(P1_7==0)
	  {h++;
	   if(h==24)
	    h=0;
	  }
	if(P1_1==0)
	 { h=0;
	   f=0;
	   s=0;
	 }
   }
}
