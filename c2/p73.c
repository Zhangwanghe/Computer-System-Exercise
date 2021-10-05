#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int saturating_add(int x, int y){
	int sum = x + y;
	int offset = intSize - 1;
	
	int signedx = -(x >> offset);
	int signedy = -(y >> offset);
	int signedsum = -(sum >> offset);
	
	int saturate = (!(signedx ^ signedy) & (signedx ^ signedsum));
	int mask_sum = saturate - 1;
	int limits = INT_MIN - signedsum;
	
	return (sum & mask_sum) | (limits & ~mask_sum);
}

int main(int argc, char *argv[])
{
	printf("%d\n", saturating_add(123456, -54321));
	printf("%d\n", saturating_add(2147483647, 1));
	printf("%d\n", saturating_add(-2147483648, -1));
	return 0;
	
	return 0;
}