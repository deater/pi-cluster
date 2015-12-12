CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =

all:	led_display

led_display:	led_display.o
	$(CC) $(LFLAGS) -o led_display led_display.o

led_display.o:	led_display.c
	$(CC) $(CFLAGS) -c led_display.c

clean:	
	rm -f *~ *.o led_display

