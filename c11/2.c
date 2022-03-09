#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage: %s <hexidecimal ip address>", argv[0]);
		return 0;
	}
	
	struct in_addr inaddr;
	//uint32_t addr;	
	char buf[8192];

	//sscanf(argv[1], "%x", &addr);
	//inaddr.s_addr = htonl(addr);
	inaddr.s_addr = htonl(strtol(argv[1], NULL, 16));

	inet_ntop(AF_INET, &inaddr, buf, 256);
	printf("%s\n",buf);
	
	exit(0);
}