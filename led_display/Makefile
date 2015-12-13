CC = gcc
CFLAGS = -O2 -Wall
LFLAGS = -lm

all:	led_display send_command

send_command:	send_command.o
	$(CC) $(LFLAGS) -o send_command send_command.o

send_command.o:	send_command.c
	$(CC) $(CFLAGS) -c send_command.c



led_display:	led_display.o \
		cpu_demo.o \
		sine_demo.o \
		stripes_demo.o
	$(CC) $(LFLAGS) -o led_display led_display.o \
		cpu_demo.o \
		sine_demo.o \
		stripes_demo.o

led_display.o:	led_display.c
	$(CC) $(CFLAGS) -c led_display.c


cpu_demo.o:	cpu_demo.c
	$(CC) $(CFLAGS) -c cpu_demo.c

sine_demo.o:	sine_demo.c
	$(CC) $(CFLAGS) -c sine_demo.c

stripes_demo.o:	stripes_demo.c
	$(CC) $(CFLAGS) -c stripes_demo.c

clean:	
	rm -f *~ *.o led_display send_command

