#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int int_size_is_32(){
	/* 32位
	int set_msb = 1 << 31;
	int symbol = (set_msb - 1) >> 31;
	
	return !symbol;
	*/
	// 16位
	int set_eb16 = 1 << 15;
	int set_eb32 = set_eb16 << 15;
	int set_eb64 = set_eb32 << 15;
	return set_eb16 && set_eb32 && !set_eb64;
}

int main(int argc, char *argv[])
{
	printf("%d\n", int_size_is_32());
	
	return 0;
}