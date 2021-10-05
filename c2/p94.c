#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	if (exp == 0x0) {
		if ((frac >> 22) == 0x0) {
			return (sign << 31) | (exp << 23) | ((frac << 1) & 0x7FFFFF);
		} else {
			return (sign << 31) | (0x1 << 23) | ((frac << 1) & 0x7FFFFF);
		}
	} else if(exp == 0xFF) {
		return f;
	} else if (exp == 0xFE) {
		return (sign << 31) | (0xFF << 23); 
	} else {
		return (sign << 31) | (exp + 1) << 23 | frac;
	}
}

int main(int argc, char *argv[])
{
	/*unsigned x = 0x7f7fffff;
	float a = *(float*)&x;
	printf("%f\n", 2*a);*/
	for (unsigned i = 0; i <= 0x7F800000; ++i) {
		float f = *(float*)&i;
		float sys_result = f * 2.0;
		float_bits my_result = float_twice(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	for (unsigned i = 0x80000000; i <= 0xFF800000; ++i) {
		float f = *(float*)&i;
		float sys_result = f * 2.0;
		float_bits my_result = float_twice(i);
		
		if (sys_result != *(float*)&my_result) {
			printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
			break;
		}
	}
	
	return 0;
}