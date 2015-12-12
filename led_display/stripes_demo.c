#include <stdio.h>
#include <unistd.h>

#include "demo_names.h"

#include "led_display.h"

int stripes_demo(int offset) {

	int i,off=offset;

	while(1) {
		for(i=0;i<8;i++) {
			hline(0,7,i,(i+off)&3);
		}

		sync_display();
		sleep(1);

		off++;
		if (off>7) off=0;
	}

	return 0;
}
