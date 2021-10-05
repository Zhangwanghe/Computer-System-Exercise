#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int any_odd_one(unsigned x){
	for (int i = 0; i < intSize; i += 2) {
		if ((x >> i) & 0x1 == 1) {
			return 1;
		}
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	printf("%d\n", any_odd_one(11));
	
	return 0;
}