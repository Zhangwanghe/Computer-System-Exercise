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
	printf("%d\n", float_le(2.5, 5.6));
	printf("%d\n", float_le(2.5, -5.6));
	printf("%d\n", float_le(-2.5, 5.6));
	printf("%d\n", float_le(-2.5, -5.6));
	
	return 0;
}