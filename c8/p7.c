#include "csapp.h"

int sleep_time = 0;
int total_time = 0;

void sigint_handler(int sig)
{
	printf("Slept %d for %d\n", sleep_time, total_time);
	exit(0);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		return 0;
	}
	
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		unix_error("signal error");
	}
	
	total_time = atoi(argv[1]);
	while(time > 0)
	{
		sleep(1);
		total_time--;
		sleep_time++;
	}

	return 0;	
}