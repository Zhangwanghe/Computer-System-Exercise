#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if (exp == 0xFF && frac != 0) {
		return f;
	}
	
	return (f & 0x7FFFFFFF) | ((-1 + sign) & 0X80000000);
}

int main(int argc, char *argv[])
{
	for (unsigned i = 0; i <= 0x7F800000; ++i) {
		float f = *(float*)&i;
		float sys_result = -f;
		float_bits my_result = float_negate(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	for (unsigned i = 0x80000000; i <= 0xFF800000; ++i) {
		float f = *(float*)&i;
		float sys_result = -f;
		float_bits my_result = float_negate(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	printf("finish\n");
	
	return 0;
}