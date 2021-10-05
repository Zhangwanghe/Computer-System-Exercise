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

int mul3div4(int x){
	int one4th = divide_power2(x, 2);
	int rest = x - (one4th << 2);
	int one4th_rest = divide_power2(rest + rest + rest, 2);

	return one4th + one4th + one4th + one4th_rest;
}

int main(int argc, char *argv[])
{
	printf("%d\n", mul3div4(3));
	printf("%d\n", mul3div4(11));
	printf("%d\n", mul3div4(-9));
	printf("%d\n", mul3div4(-11));
	
	return 0;
}