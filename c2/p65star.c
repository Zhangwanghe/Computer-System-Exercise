#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int odd_ones(unsigned x)
{
	x ^= (x >> 16);
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	
	return x & 0x1;
}
int main(int argc, char *argv[])
{
	printf("%d\n", odd_ones(9));
	
	return 0;
}