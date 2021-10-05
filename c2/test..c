#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef unsigned char *byte_pointer;
int int_size = sizeof(int) << 3;

unsigned f2u(float x) {
	return *(unsigned*)&x;
}

int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
	
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	
	return (((ux - uy) ^ ux) >> 31) & 0x1;
}

int main(int argc, char *argv[])
{
	float a = (double)22.0 / (double)7.0;
	float b = (float)223.0 / (float)71.0;
	printf("%.2x\n%.2x\n", 22.0/7.0, 223.0 / 71.0);
	
	return 0;
}