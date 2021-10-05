#include <stdio.h>

typedef unsigned char *byte_pointer;

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	int startBits = i * 8;
	int endBits = startBits + 8;
	unsigned high = (x >> endBits) << endBits;
	unsigned low = (x << startBits) >> startBits;
	return high | low | (b << startBits);
}

int main(int argc, char *argv[])
{
	unsigned x = 0x12345678;
	int i = 2;
	unsigned char b = 0xAB;
	printf("generate (%2x, %d, %2x) = %2x", x, i, b, replace_byte(x, i, b));
    return 0;
}