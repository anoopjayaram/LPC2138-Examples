#include<lpc21xx.h>
void delay();
void trans(char b);
void main()
{
int i;
char a[]="hello";


PINSEL0=0x00000001;
 U0LCR=0X83;
 U0DLL=0X62;
 U0DLM=0X00;
 U0LCR=0X03; 
 
while(1){
 for(i=0;a[i]!=0;i++)
 trans(a[i]);
 }
 //trans('\n');
	  }	   

void  trans(char b)
{
U0THR=b;
while((U0LSR&0X40)==0);	   //0: U0THR contains valid data.
delay();
 }

 void delay()
 {
 int i,j;
 for(i=0;i<300;i++)
 for(j=0;j<300;j++);
 }
