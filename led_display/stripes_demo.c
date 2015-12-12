#include <stdio.h>
#include <unistd.h>

#include "demo_names.h"

#include "led_display.h"

int stripes_demo(int offset) {

	int i;

	for(i=0;i<8;i++) {
		hline(0,7,i,i&3);
	}

	while(1) {
		sync_display();
		sleep(1);
	}

	return 0;
}
