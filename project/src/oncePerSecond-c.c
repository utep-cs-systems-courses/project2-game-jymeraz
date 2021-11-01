#include <msp430.h>
#include "led-sequences.h" 

void oncePerSecond() // repeatedly start dim, get bright, get dim, then change directions
{
  if (blinkLimit >= 8) { 
      direction = 0;
      color ^= 1;
  }
  if (blinkLimit <= 0) {
      direction = 1;
  }
 
  if (direction == 1) {
    blinkLimit ++;
  } else {
    blinkLimit --;
  }
}
