#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

unsigned srl(unsigned x, int k) {
	unsigned xsra = (int)x >> k;

	int signedBits = -1 << (intSize - k);
	
	return (-1 - signedBits) & xsra;
}

int sra(int x, int k) {
	int xsrl = (unsigned)x >> k;
	
	int signedBits = -1 << (intSize - 1 - k);
	int sign = xsrl & signedBits;
	
	return ((0 - sign) & signedBits) | xsrl;
}

int main(int argc, char *argv[])
{
	printf("%.2x\n", 2569324697 >> 15);
	printf("%.2x\n", srl(2569324697, 15));
	printf("%.2x\n", 123456789 >> 15);
	printf("%.2x\n", srl(123456789, 15));
	
	printf("%.2x\n", 123456789 >> 15);
	printf("%.2x\n", sra(123456789, 15));
	printf("%.2x\n", -123456789 >> 15);
    printf("%.2x\n", sra(-123456789, 15));
	
	return 0;
}