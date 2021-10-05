#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int low_one_mask(int n){
	int maskl32 = (1 << n) - 1;
	return maskl32 | (maskl32-1);
}

int main(int argc, char *argv[])
{
	printf("%.2x\n", low_one_mask(32));
	printf("%.2x\n", low_one_mask(5));
	
	return 0;
}