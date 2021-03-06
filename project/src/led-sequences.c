#include <msp430.h>
#include "led-sequences.h"
#include "led.h"

int blinkLimit = 0;   //  state var representing the number of current maximum blinks
int direction = 1;  // state var representing whether its getting brighter or dimmer
int color = 0; // state var representing the color that is blinking

void blinkUpdate() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  static int blinkCount = 0; // state var representing blink state
  blinkCount ++;
  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    if (color == 0) {
      greenControl(1);
    } else {
      redControl(1);
    }
  } else {
    ledsOff();
  }
}

void secondUpdate()  // called every 1/250 sec 
{
  static int secondCount = 0; // state var representing elapsed time
  secondCount ++;
  if (secondCount >= 250) { // update blink limit once per second
    secondCount = 0;
    oncePerSecond();
  }
}

void buttonOne() // called every 1/250 sec
{
  blinkUpdate();
  secondUpdate();
}

static int on = 0; // state var representing whether an led is on or off
static int prev_one = 0; // variable keeping track of previous fibonacci variable
static int prev_two = 1; // variable keeping track of previous fibonacci variable
static int count = 1; // state var representing the current blink position of the led

void fibonacci()
{
  int next = prev_one + prev_two;
  if (count == 2*next) {
    prev_one = prev_two;
    prev_two = next;
    count = 0;
    color ^= 1;
  }
  count ++;
}

void buttonTwo() // toggle the led once per second
{
  static int secondCount = 0; // state var representing elapsed time
  secondCount ++;
  if (secondCount >= 250) { // update blink limit once per second
    ledsOff();
    fibonacci(); // update the led that will be turned on
    secondCount = 0;
    on ^= 1;  // toggle the led
    if (color == 0)
      greenControl(on);
    else
      redControl(on);
  }
}
