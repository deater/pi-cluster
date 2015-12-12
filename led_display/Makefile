CC = gcc
CFLAGS = -O2 -Wall
LFLAGS = -lm

all:	led_display

led_display:	led_display.o \
		sine_demo.o \
		stripes_demo.o
	$(CC) $(LFLAGS) -o led_display led_display.o \
		sine_demo.o \
		stripes_demo.o

led_display.o:	led_display.c
	$(CC) $(CFLAGS) -c led_display.c


sine_demo.o:	sine_demo.c
	$(CC) $(CFLAGS) -c sine_demo.c

stripes_demo.o:	stripes_demo.c
	$(CC) $(CFLAGS) -c stripes_demo.c

clean:	
	rm -f *~ *.o led_display

