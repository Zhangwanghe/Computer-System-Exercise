#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage: %s <ip>", argv[0]);
		return 0;
	}
	
	struct in_addr inaddr;
	inet_pton(AF_INET, argv[1], &inaddr);	
	printf("0x%x\n", ntohl(inaddr.s_addr));
	
	exit(0);
}