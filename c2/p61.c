#include <stdio.h>

typedef unsigned char *byte_pointer;

int intSize = sizeof(int) << 3;

int test_condition(int x) {
	int cond1 = ((x & 0xFF) + 1) >> 8;
	int cond2 = (0x100 - ((x >> (intSize - 8)) & 0xFF)) >> 8;
	return cond1 + cond2;
}

int main(int argc, char *argv[])
{
	printf("%d\n", test_condition(0x00FFFFFE));
    return 0;
}