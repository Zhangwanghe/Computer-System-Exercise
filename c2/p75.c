#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int signed_high_prod(int x, int y) {
	long xl = x;
	long yl = y;
	long result = xl * yl;

	return (result >> 32) & 0xFFFFFFFF;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
	int offset = intSize - 1;
	int signed_prod = signed_high_prod(x, y);
	
	int maskx = (int)x >> offset;
	int masky = (int)y >> offset;
	int w = (x & masky) + (y & maskx);
	printf("%.2x, %.2x, %.2x, %.2x, %.2x, %.2x\n", signed_prod, maskx, masky, w, x, y);
	
	return w + signed_prod;
}

int main(int argc, char *argv[])
{
	printf("%.2x\n", unsigned_high_prod(123456, 2222245678));
	printf("%.2x\n", unsigned_high_prod(2222245678, 2222245678));
	return 0;
}