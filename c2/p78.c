#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int int_size = sizeof(int) << 3;

int divide_power2(int x, int k){
	int sign_of_x = (unsigned)x >> (int_size - 1);
	int offset = ((unsigned)x >> (int_size - 1)) << k;

	return (x + offset - (1 & sign_of_x)) >> k;
}

int main(int argc, char *argv[])
{
	printf("%d\n", divide_power2(-9, 2));
	printf("%d\n", divide_power2(-11, 2));
	printf("%d\n", divide_power2(9, 2));
	printf("%d\n", divide_power2(11, 2));
	
	return 0;
}