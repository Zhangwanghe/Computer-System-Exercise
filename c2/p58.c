#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
	int a = 1;
	byte_pointer ca = (byte_pointer)&a;
	return *ca == 1;
}

int main(int argc, char *argv[])
{
	printf("is_little_endian = %d",is_little_endian());
    return 0;
}