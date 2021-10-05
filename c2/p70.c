#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int fits_bits(int x, int n){
	int offset = intSize - n;
	return (x << offset) >> offset == x;
}

int main(int argc, char *argv[])
{
	printf("%d\n", fits_bits(-32768, 16));
	printf("%d\n", fits_bits(32767, 16));
	printf("%d\n", fits_bits(INT_MAX, 32));
	printf("%d\n", fits_bits(INT_MIN, 32));
	printf("%d\n", fits_bits(0, 16));
	printf("%d\n", fits_bits(0, 32));
	printf("%d\n", fits_bits(32768, 16));
	printf("%d\n", fits_bits(-32769, 16));
	printf("%d\n", fits_bits(INT_MIN, 31));
	printf("%d\n", fits_bits(INT_MAX, 31));
	
	return 0;
}