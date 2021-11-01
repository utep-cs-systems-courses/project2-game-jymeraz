#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
}

void greenControl(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

void redControl(int on)
{
  if (on) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

void ledsOff() {
  greenControl(0);
  redControl(0);
}
