## Description

This directory contains different sets of files and functions to implement
each state machine.

Program           | Description
----------------- | ------------------------------------------------
buzzer	          | Uses timer interrupts to play songs. The first song is the adventure time theme song and the if statements are used to determine when a note should be played. The second song is the happy birthday song, and it has led lights to accompany it.
interruptHandler  | Contains timer and switch interrupts
led-sequences	  | Uses timer interrupts to flash the leds
		  | The first pattern starts off as bright green, gets dimmer,
		  | then, the color changes to a dim red, gets brighter,
		  | then gets dimmer.
		  | this pattern continues and alternates leds
		  | The second pattern flashes the numbers for the
		  | fibonacci sequence
		  | the green color flashes the first number (1)
		  | the red color flashes the next number (2)
		  | the pattern continues infinitely
led		  | The leds are initialized and functionality to
		  | turn them on and off is simplified
main 		  | The leds, buzzer, switches, clocks, and
		  | interrupts are configured
oncePerSecond-c	  | C version of the function found in led-sequences
oncePerSecond-c   | Assembly version of the function found in led-sequences
switches	  | Initializes the switches and detects when one was pushed down

