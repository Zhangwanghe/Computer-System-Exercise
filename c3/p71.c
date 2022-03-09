#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERL 10

void good_echo() 
{
	char *buffer = (char*)malloc(BUFFERL);
	if (buffer == NULL)
	{
		printf("error malloc\n");
		return;
	}
	
	while (1) {
		char *ret = fgets(buffer, BUFFERL, stdin);
		if (ret != buffer || feof(stdin)) {
			break;
		}
		
		printf("%s", buffer);
		
		if (strlen(buffer) < BUFFERL - 1) {
			break;
		}
	}
	
	if (ferror(stdin)) 
	{
		 puts("Error indicator set");
	}
}

int main(int argc, char *argv[])
{
	good_echo();
}