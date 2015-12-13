#include <stdio.h>

#include "demo_names.h"
#include "led_display.h"

static int display_red[8],display_green[8];

int green_on(int x, int y) {
	int offset;
	offset=1<<(7-x);
	display_green[y]|=offset;
	return 0;
}

int red_on(int x, int y) {
	int offset;
	offset=1<<(7-x);
	display_red[y]|=offset;
	return 0;
}

int putpixel(int x, int y, int color) {

	int offset;

	offset=1<<(7-x);

	display_red[y]&=~offset;
	display_green[y]&=~offset;

	if ((color==RED) || (color==YELLOW)) {
		display_red[y]|=offset;
	}

	if ((color==GREEN) || (color==YELLOW)) {
		display_green[y]|=offset;
	}

	return 0;
}

/* Graphics Routines */
int hline(int x1, int x2, int y, int color) {

	int x;

	for(x=x1;x<=x2;x++) {
		putpixel(x,y,color);
	}

	return 0;

}

int vline(int y1, int y2, int x, int color) {

	int y;

	for(y=y1;y<=y2;y++) {
		putpixel(x,y,color);
	}

	return 0;

}

int clear_display(int color) {

	int y;

	for(y=0;y<8;y++) {
		hline(0,7,y,color);
	}
	return 0;
}

int sync_display(void) {

	int i,j,red,green,oldcolor,newcolor;

	/* Clear screen */
        printf("\033[2J\033[0;0m\n");

        /* move to upper left */
        printf("\033[1;1H");

	oldcolor=0xff;

	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			red=!!(display_red[i]&(1<<(7-j)));
			green=!!(display_green[i]&(1<<(7-j)));
			newcolor=(green<<1)|red;

			if (newcolor!=oldcolor) {
				if (newcolor==0) printf("\033[30m");
				if (newcolor==1) printf("\033[31m");
				if (newcolor==2) printf("\033[32m");
				if (newcolor==3) printf("\033[33m");
			}
			oldcolor=newcolor;

			printf("**");

		}
		printf("\n");

	}

	return 0;
}

int main(int argc, char **argv) {

	/* Clear Display */
	clear_display(BLACK);

	/* Open i2c port */

	/* Open network socket to listen for commands */

//	stripes_demo(0);
//	sine_demo();
	cpu_demo();

	return 0;
}
