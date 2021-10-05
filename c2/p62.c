#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

int int_shifts_are_arithmetic(){
	return (-1 >> 1) == -1	;
}

int main(int argc, char *argv[])
{
	printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}