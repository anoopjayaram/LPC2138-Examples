
/*Calculations*/
/*

```diff
 

Q : Timer time period =10ms
    Fosc =15MHz

-Timer Frequency = Fosc /(PRESCALE +1)

Timer Frequency = 1/10ms
Fosc =  15MHz
PRESCALE =?

PRESCALE = (15MHz * 10Ms)-1
PRESCALE = 149999

For 100ms wave 
-Match value of Period = PWM Time Period / Timer Increment time
                      = 100ms/10ms = 10
@PWMMR0=10

For 50 % Duty Cycle = T ON = 50ms
Match value of high = 50ms/10ms = 5

PWMMR3=5

*/

```
#include<lpc213x.h>

void main()
{

PINSEL0=1<<3;  

IO0DIR=~0;

PWMMR0=10; //COMPARED TO TIMER / C VALUE  - PERIOD 300 * 1mS

PWMMR3=5;

PWMTCR=2;

PWMTCR=1|1<<3;  

PWMMCR=1<<1;		

PWMPR=149999;      //1  mS

PWMTC=0;  

PWMPC=0;
PWMPCR=1<<11;  
while(1)
{

}
}





