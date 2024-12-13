
 Calculations 
 


 

Q : Timer time period =10ms
    Fosc =15MHz
```diff
-Timer Frequency = Fosc /(PRESCALE +1)
```
Timer Frequency = 1/10ms

Fosc =  15MHz

PRESCALE =?


PRESCALE = (15MHz * 10Ms)-1

PRESCALE = 149999

For 100ms wave
```diff
-Match value of Period = PWM Time Period / Timer Increment time
```
PWMMR0 = 100ms/10ms = 10 
 

For 50 % Duty Cycle = T ON = 50ms
Match value of high = 50ms/10ms = 5

**PWMMR3=5**






