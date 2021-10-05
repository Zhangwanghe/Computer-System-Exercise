#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int int_size = sizeof(int) << 3;

int test_condition(int j, int k) {
	int cond1 = (-1) << k;
	int cond2 = (~(-1 << k)) << j;
	printf("%.2x %.2x\n", cond1, cond2);
}

int main(int argc, char *argv[])
{
	test_condition(2, 5);
	
	return 0;
}