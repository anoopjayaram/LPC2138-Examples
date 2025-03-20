#include<lpc213x.h>
void isr()__irq
{ 
int i,j;
IO0PIN=~IO0PIN;
EXTINT=1<<1;	 
 
}
void main()
{
IO0DIR=~(1<<3);
PINSEL0=1<<7|1<<6;
VICIntSelect=~(1<<15);  // ASSIGNED TO IRQ CATAGORY
VICIntEnClr=1<<15;  //CLEAR INTERRUPT
VICIntEnable=1<<15;  //ENABLE
VICVectCntl0=1<<5|15;  // bit no:only
VICVectAddr0=(unsigned int)isr;//address of interrupt fun
EXTINT=1<<1;   //for ext1
EXTMODE=1<<1;// edge or level
EXTPOLAR=1<<1;//rising edge or falling
IO0CLR=~0;
while(1);  
}
