#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int leftmost_one(unsigned x){
	x |= (x >> 16);
	x |= (x >> 8);
	x |= (x >> 4);
	x |= (x >> 2);
	x |= (x >> 1);
	
	return ((x + 1) >> 1) | (((!(x + 1) << 31) >> 31) & INT_MIN);
}

int main(int argc, char *argv[])
{
	printf("%.2x\n", leftmost_one(0x6600));
	printf("%.2x\n", leftmost_one(0x80000001));
	
	return 0;
}