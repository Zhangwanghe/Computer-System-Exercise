#include <stdio.h>

typedef unsigned char *byte_pointer;

int generate(int x, int y) {
	return (x & 0xFF) | ((y >> 8) << 8);
}

int main(int argc, char *argv[])
{
	int x = 0x89abcdef;
	int y = 0x76543210;
	printf("generate (%2x, %2x) = %2x", x, y, generate(x, y));
    return 0;
}