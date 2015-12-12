#include <stdio.h>

#include "demo_names.h"
#include "led_display.h"

int display_red[8],display_green[8];

static int init_display(void) {
	int i;

	for(i=0;i<8;i++) display_red[i]=0;
	for(i=0;i<8;i++) display_green[i]=0;

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
	init_display();

	/* Open i2c port */

	/* Open network socket to listen for commands */

	stripes_demo(0);

	return 0;
}
