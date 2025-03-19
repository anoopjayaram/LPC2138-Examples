 #include<lpc21xx.h>
void delay();
void trans(char b);
char rec();
void main()
{
int i;
 
						 
PINSEL0=0x00000005;
 U0LCR=0X83;			 
 U0DLL=0X62;
 U0DLM=0X00;
 U0LCR=0X03;
while(1)
{ 
 char c=rec();
 trans(c);
   }
 }

void trans(char b)
{
U0THR=b;
while((U0LSR&0X40)==0); //0: U0THR contains valid data.
delay();
 }
 char rec()
{
while((U0LSR&0X01)==0);
return(U0RBR);
 }


 void delay()
 {
 int i,j;
 for(i=0;i<300;i++)
 for(j=0;j<300;j++);
 }
