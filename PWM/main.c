#include<lpc213x.h>

void main() {

PINSEL0=1<<3;

IO0DIR=~0;

PWMMR0=10; //COMPARED TO TIMER / C VALUE - PERIOD 10 * 10mS = 100ms

PWMMR3=5; // 50% Duty Cycle 50ms ON Time

PWMTCR=2;

PWMTCR=1|1<<3;

PWMMCR=1<<1;

PWMPR=149999; //1 mS

PWMTC=0;

PWMPC=0; 
  PWMPCR=1<<11;
while(1) {

} }
