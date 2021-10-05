#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

unsigned rotate_left(unsigned x, int n){
	int high = x >> (intSize - n);
	int rotate = high | (x << n);
	return rotate;
}

int main(int argc, char *argv[])
{
	printf("%.2x\n", rotate_left(0x12345678, 4));
	printf("%.2x\n", rotate_left(0x12345678, 20));
	printf("%.2x\n", rotate_left(0x12345678, 0));
	
	return 0;
}