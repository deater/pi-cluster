/* Makes a sine wave */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <math.h>

#include "led_display.h"

#define XSIZE 8
#define YSIZE 8

#define PI 3.14159265358979323846264338327950

/* Draw one frame */
/* dx is the only data needed to be saved across calls */
int sine_demo(void) {

	int x,y;
	double temp_dx,dy,dxscroll=PI/8.0;
	double dx=0.0;

	while(1) {

		clear_display(BLACK);

		for(x=0;x<XSIZE;x++) {

			temp_dx=dx+((double)x *(PI/8.0));
			dy=sin(temp_dx);
			y=(int)round((3.5+(dy*3.5)));
			// if (y>7) printf("Error y too big!\n");
			green_on(x,y);

			dy=cos(temp_dx);
			// if (y>7) printf("Error y too big!\n");
			y=(int)round((3.5+(dy*3.5)));
			red_on(x,y);
		}

		dx+=dxscroll;

		sync_display();

		usleep(50000);
	}

	return 0;
}


