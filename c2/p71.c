#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum){
	int offset = intSize - 8;
	int eb_at_low = word >> (bytenum  << 3);
	int eb_at_high = eb_at_low << offset;
	return  eb_at_high >> offset;
}

int main(int argc, char *argv[])
{
	packed_t word = 0x8008FF00;
	printf("%d\n", xbyte(word, 0));
	printf("%d\n", xbyte(word, 1));
	printf("%d\n", xbyte(word, 2));
	printf("%d\n", xbyte(word, 3));
	
	return 0;
}