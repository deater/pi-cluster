#include <stdio.h>
#include <unistd.h>

#include "demo_names.h"
#include "led_display.h"

#define MAX_CPUS	4

static struct cpu_load_t {
	long long user;
	long long nice;
	long long system;
	long long idle;
	long long iowait;
	long long irq;
	long long softirq;
} cpu_load[MAX_CPUS];

static long long old_load[MAX_CPUS];
static long long load[MAX_CPUS];

static int load_history[MAX_CPUS][8];

int cpu_demo(void) {

	FILE *fff;
	static int error_printed=0;
	int i,j;

	char string[BUFSIZ];

	for(i=0;i<MAX_CPUS;i++) {
		for(j=0;j<8;j++) {
			load_history[i][j]=0;
		}
	}



	while(1) {

		fff=fopen("/proc/stat","r");
		if (fff==NULL) {
			if (!error_printed) {
				fprintf(stderr,"stderr: error opening /proc/stat!\n");
				error_printed++;
			}
		}

		/* Total */
		fgets(string,BUFSIZ,fff);

		/* Shift load left */
		for(i=0;i<MAX_CPUS;i++) {
			for(j=0;j<7;j++) {
				load_history[i][j]=load_history[i][j+1];
			}
		}

		/* Read new load */
		for(i=0;i<MAX_CPUS;i++) {
			fgets(string,BUFSIZ,fff);
			sscanf(string,"%*s %lld %lld %lld",
				&cpu_load[i].user,
				&cpu_load[i].nice,
				&cpu_load[i].system);
			load[i]=cpu_load[i].user+cpu_load[i].nice+cpu_load[i].system;
			//printf("CPU%d %lld / %lld\n",i,load[i]-old_load[i],
			//	100LL);

			load_history[i][7]=load[i]-old_load[i];
			if (load_history[i][7]>100) load_history[i][7]=100;

			old_load[i]=load[i];

		}

		fclose(fff);

		clear_display(BLACK);

		/* Draw Load */
		for(i=0;i<8;i++) {
			int offset=7;

			for(j=0;j<MAX_CPUS;j++) {
				vline(offset-load_history[j][i]/50,offset,i,
					(j%3)+1);
				offset-=load_history[j][i]/50;
	//			printf("cpu=%d x=%d %d, ",j,i,load_history[j][i]);
			}

		}
	//	printf("\n");
		/* Write to display */
		sync_display();


		sleep(1);
	}

	return 0;
}
