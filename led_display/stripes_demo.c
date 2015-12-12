#include <stdio.h>
#include <unistd.h>

#include "demo_names.h"

#include "led_display.h"

int stripes_demo(int offset) {

	int i;

	for(i=0;i<8;i++) {
		switch(i&3) {
			case 0:
				display_red[i]=0;
				display_green[i]=0;
				break;
			case 1:
				display_red[i]=0xff;
				display_green[i]=0;
				break;
			case 2:
				display_red[i]=0;
				display_green[i]=0xff;
				break;
			case 3:
				display_red[i]=0xff;
				display_green[i]=0xff;
				break;
		}
	}

	while(1) {
		sync_display();
		sleep(1);
	}

	return 0;
}
