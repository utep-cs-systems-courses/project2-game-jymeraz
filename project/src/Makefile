# makfile configuration
COMMON_OBJECTS  = main.o buzzer.o switches.o led.o led-sequences.o interruptHandler.o oncePerSecond-c.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: led.elf  

#additional rules for files
led-c.elf: ${COMMON_OBJECTS} oncePerSecond-c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a
led-s.elf: ${COMMON_OBJECTS} oncePerSecond-s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load-c: led-c.elf
	msp430loader.sh $^
load-s: led-s.elf
	msp430loader.sh $^

load: led.elf 
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

led.o: led.c led.h
oncePerSecond-s.o: led-sequences.h

interruptHandler.o: led.h switches.h led-sequences.h

led-sequences.o: led.h led-sequences.h #oncePerSecond-c.h
