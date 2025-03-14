#include<lpc213x.h>
void delay(int);
void cmd(int);  
void data(char);  
void main()
{
int a;    

IO1DIR=0XFFFFFFFF;		 
IO0DIR=0XF0FFFFFF;
PINSEL1=0X15400000;//ad 0.0
cmd(0X38);                                          
cmd(0X80);                    
cmd(0X01);
cmd(0X06); //Entry mode
cmd(0X0E);
  while(1)
  {
  delay(50);
  AD0CR=0X01200401; //EDGE =1 |START CONVERSION |10 BITS |  
  while(!(AD0GDR&(1<<31))); //WAITS IF DONE IS 0
  a=(AD0GDR>>6)&0x3ff;  // 0011 1111 1111
  data((a/1000)+48);
  data(((a/100)%10)+48);
  data((a%100)/10+48);
  data(a%10+48);
  delay(50);
  cmd(0X01);
  
  }
}
void cmd(int a)
{

IO1CLR=0XFFFFFFFF;
IO1SET=a<<16;
IO1SET=0X20000000;
delay(50);
IO1CLR=0X20000000;
delay(50);
}



void data(char b)
{

IO1CLR=0XFFFFFFFF;
IO1SET=b<<16;
IO1SET=0X30000000;
delay(50);
IO1CLR=0X20000000;
delay(50);
}

 
void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
for(j=0;j<500;j++);
}
