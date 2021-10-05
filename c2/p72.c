#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;
int intSize = sizeof(int) << 3;

int copy_int(int val, void* buf, int maxbytes){
	//if (maxbytes - sizeof(val) >= 0) {
	if (maxbytes >= 0 && maxbytes >= sizeof(val)) {
		memcpy(buf, (void*)&val, sizeof(val));
	}
}

int main(int argc, char *argv[])
{
	copy_int
	
	return 0;
}