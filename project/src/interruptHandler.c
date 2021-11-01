#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led-sequences.h" 
#include "led.h" 

void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  if (sw1 == 1) {
    buzzerOff();
    buttonOne();
  } else if (sw2 == 1) {
    buzzerOff();
    buttonTwo();
  } else if (sw3 == 1) {
    ledsOff();
    songOne();
  } else if (sw4 == 1) {
    songTwo();
  }
} 

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
