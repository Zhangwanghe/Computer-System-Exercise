#include "csapp.h"

void alarm_handler(int) {
}

char* tfgets(char *s, int size, FILE *stream) {
	struct sigaction action, old_action;
    action.sa_handler = alarm_handler;  
    sigemptyset(&action.sa_mask); /* Block sigs of type being handled */
	sigaction(SIGALRM, &action, &old_action);
	
	alarm(5);
	
	char* ret = NULL;
	int count = read(fileno(stream), s, size);
	if (count < 0) {
		return NULL;
	} else {
		return s;
	}	
}

int main(int argc, char** argv) {
	char buffer[100] = {0};
	printf("ret:%s\n", tfgets(buffer, 100, stdin));
}