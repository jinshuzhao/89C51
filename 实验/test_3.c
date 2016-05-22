#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar number1[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};
uchar number2[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
 uchar s=0,f=0,h=0,j,m,n,a,a1,b,b1,c,c1,d,d1,e,g,flg1,flg=0;
 uint year=2011,month=1,day=1;
 sbit P1_0=P1^0;
 sbit P1_1=P1^1;
 sbit P1_2=P1^2;
 sbit P1_3=P1^3;
 void delay(uchar x)
 { uchar i,j;
   for(i=0;i<=x;i++)
   for(j=0;j<=248;j++);
 }
 void display()
 { 	if(flg==0)
     {	 switch(j)
           {
			case 0:if(flg1==5) 
					   { a1++;
						if(a1<=50)P3=0x00;
						else P3=0x01;
						if(a1==100)
						 a1=0;
						}
						else
						P3=0x01;
						P0=number1[h/10];break;
			case 1:if(flg1==5)
					  { b1++;
						if(b1<=50)P3=0x00;
						else P3=0x02;
						if(b1==100)
						 b1=0;
					   }
						 else
						 P3=0x02;
						 P0=number1[h%10];break;
			case 2:P3=0x04;P0=number1[10];break;
			case 3:	if(flg1==6)
					  { c1++;
						if(c1<=50)P3=0x00;
						else P3=0x08;
						if(c1==100)
						 c1=0;
					  }
						 else
						 P3=0x08;
						 P0=number1[f/10];break;

			case 4:	if(flg1==6)
			          { d1++;
						if(d1<=50)P3=0x00;
						else P3=0x10;
						if(d1==100)
						 d1=0;
					  }
						 else
						 P3=0x10;
						 P0=number1[f%10];break;
			case 5:P3=0x20;P0=number1[10];break;
			case 6:P3=0x40;P0=number1[s/10];break;
			case 7:P3=0x80;P0=number1[s%10];break;
		   }
	 }
	if(flg==1)
	   { switch(j)
          { case 8:if(flg1==4)
				  { c++;
				    if(c<=50)
				    P3=0x00;
				  else 
				    P3=0x01;
				  if(c==100)
				     c=0;
				  }
				 else
				   P3=0x01;
				   P0=number1[year/1000];break;
 
		   

			case 9:if(flg1==4)
					{ d++;
					if(d<=50)
					  P3=0x00;
					else
					  P3=0x02;
					 if(d==100)
					  d=0;
					}
					else 
					  P3=0x02;
					  P0=number1[(year/100)%10];break;

			case 10:if(flg1==4)
					{ e++;
					 if(e<=50) 
					  P3=0x00;
					else 
					  P3=0x04;
					if(e==100)
				 	  e=0;
				    }
					else
					 P3=0x04;
					 P0=number1[(year/10)%10];
					break;

			case 11:if(flg1==4)
					{  g++;
					 if(g<=50)
					   P3=0x00;
					 else 
					  P3=0x08;
					 if(g==100)
					   g=0;
					}
					else
					  P3=0x08;
					  P0=number2[year%10];break;

			case 12:if(flg1==3)
					{ a++;
					  if(a<=50)
					  P3=0x00;
					 else
					  P3=0x10;
					  if(a==100)
					  a=0;
					}
					  else
					  P3=0x10;
					  P0=number1[month/10];break;

			case 13:if(flg1==3)
					{ b++;
					  if(b<=50)
				 	  P3=0x00;
					else 
					  P3=0x20;
					 if(b==100)
					    b=0;
					 }
					 else 
					 P3=0x20;
					 P0=number2[month%10];break;

			case 14:if(flg1==2)
				   { n++;
					if(n<=50)
					P3=0x00;
					else
					 P3=0x40;
					if(n==100)
					 n=0;
				   }
				  else
				  P3=0x40;
				  P0=number1[day/10];break;
			       
			case 15:if(flg1==2)
				   {  m++;
					if(m<=50) P3=0x00;
				   else 
					 P3=0x80;
				   if(m==100)
				  	 m=0;
				   }
					else
					P3=0x80;
				    P0=number1[day%10];break;
           }
	  }
}
  void  keyscan()
 {if(P1_0==0)
    { delay(50);
	  if(P1_0==0)
	    { if(flg==0)
		  { h++;
		   if(h==24)
		    h=0;
			flg1=5;
		   }
           else if(flg==1)
		    { year++;
		      flg1=4;
			}
		}
	}
  if(P1_1==0)
    { delay(50);
	  if(P1_1==0)
	    { if(flg==0)
		   {f++;
		    if(f==60)
		    f=0;
			flg1=6;
		   }
		   else if(flg==1)
		   { month++;
		     if(month==13)
		      month=1;
			  flg1=3;
		   }
		}
	}
  if(P1_2==0)
    { delay(50);
	  if(P1_2==0)
	    { if(flg==0)
		   { s=0;
		     h=0;
		     f=0;
		   }
		else
		  {day++;
		   if(day==32)
		   day=0;
		   flg1=2;
		  }
		}
	}
  if(P1_3==0)
    { delay(50);
	  if(P1_3==0)
	    { if(flg1!=0)
		    flg1=0;
			else
		    flg++;
		  if(flg==2)
		    {flg=0;
			 flg1=0;
			 j=0;
			}
		  else
		  j=8;
		}
	}
 }
   void update_day( )
 {     day++;  
	if(month%2!=0)
	  {	if(day==32)
	    {day=1;
		 month++;
	    }
	  }
	if (month==2)
	  {if ((year%4==0&&year%100!=0)||(year%400==0))
	    {if(day==30)
	     {day=1;
		  month++;
		 }
		}
		else
		if(day==29)
		 {day=1;
		  month++;
		 }
	  }
	if(month==8)
	  {if(day==32)
	    {day=1;
		 month++;
		}
	  }
	if(month==4)
	  {if(day==31)
	    {day=1;
		 month++;
		 }
	  }
   if(month==6)
	  {if(day==31)
	    {day=1;
		 month++;
		}
	  }
	if(month==10)
	  {if(day==31)
	    {day=1;
		 month++;
		}
	  }
	if(month==12)
	  {if(day==31)
	    {day=1;
		 month++;
		}
	  }
	if(month==13)
	{  month=1;
	   year++;
	} 
  }	 

 void main()
{
TMOD=0x01;
TH0=(65536-1000)/256;
TL0=(65536-1000)%256;
ET0=1;
EA=1;
TR0=1;
while(1)
  {  
   keyscan();
   }
}


 void timer0_int(void) interrupt 1
{   unsigned int k;
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	k++;
	if(k==1000)
	 {  k=0;
	    s++;
	    if(s==60)
	    { s=0;
		  f++;
		  if(f==60)
		    {f=0;
			 h++;
			 if(h==24)
			  {  h=0;
			    update_day(); 
		      }
		   }
	   }
	 }
    j++;
   if(flg==0)
	   {if(j==8)
	    j=0;
	   }
   else
	   if(j==16)
	    j=0;
	  display();
  }
