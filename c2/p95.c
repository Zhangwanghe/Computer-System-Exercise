#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned remainder = f & 0x1;
	unsigned ret = 0x0;
	if (exp == 0x0) {
		ret = (sign << 31) | (exp << 23) | (frac >> 1);
	} else if(exp == 0xFF) {
		return f;
	} else if (exp == 0x01) {
		ret = (sign << 31) | (frac >> 1) | 0x400000; 
	} else {
		return (sign << 31) | (exp - 1) << 23 | frac;
	}

	if ((ret & 0x1) == 0x1) {
		ret += remainder;
	}
	
	return ret;
}

int main(int argc, char *argv[])
{
	/*unsigned x = 0x7f7fffff;
	float a = *(float*)&x;
	printf("%f\n", a/2);*/
	for (unsigned i = 0; i <= 0x7F800000; ++i) {
		float f = *(float*)&i;
		float sys_result = f / 2.0;
		float_bits my_result = float_half(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	for (unsigned i = 0x80000000; i <= 0xFF800000; ++i) {
		float f = *(float*)&i;
		float sys_result = f / 2.0;
		float_bits my_result = float_half(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	return 0;
}