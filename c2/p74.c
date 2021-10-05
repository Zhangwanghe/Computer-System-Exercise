#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int tsub_ok(int x, int y){
	int sub = x - y;
	int offset = intSize - 1;
	
	int signedx = -(x >> offset);
	int signedy = -(y >> offset);
	int signedsum = -(sub >> offset);
	
	return ((signedx ^ signedy) & !(signedy ^ signedsum));
}

int main(int argc, char *argv[])
{
	printf("%d\n", tsub_ok(123456, 54321));
	printf("%d\n", tsub_ok(2147483647, -1));
	printf("%d\n", tsub_ok(-2147483648, 1));
	return 0;
}