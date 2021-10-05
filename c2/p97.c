#include <stdio.h>
#include <limits.h>
#include <string.h>

#define TESTONE 0
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

typedef unsigned float_bits;

float_bits float_i2f(int i) {
	if (i == 0) {
		return 0;
	}
	
	if (i == INT_MIN) {
		return 0xCF000000;
	}
	
	unsigned sign = (unsigned)i >> 31;
	if (sign == 0x1) {
		i = (~i) + 1;
	}
	
	unsigned frac = i &0x7FFFFFFF;
	unsigned exp = 0;
	while ((frac >> exp)> 1) {
		exp++;
		if (exp > 32) {
			printf("111 %d\n", i);
		}
	}
	
	frac = frac & ~(1 << exp);
	
	unsigned rounding = 0;
	if (exp > 23 && ((frac >> (exp - 24)) & 1) == 0x1) {
		if (exp == 24 || (frac << (56-exp)) == 0) {
			if (((frac >> (exp - 23)) & 1) == 0x1) {
				rounding = 1;
			}
		} else if (((frac >> (exp - 24)) & 1) == 0x1) {
			// >.5
			rounding = 1;
		}
	}
	
	if (exp <= 23) {
		frac <<= (23 - exp);
	} else {
		frac >>= (exp - 23);
	}
	
#if TESTONE == 1
	printf("%.2x %d %d %d %d %d\n", frac,(frac >> (exp - 24)) & 1, (frac >> (exp - 23)) & 1, exp, rounding, sign);
#endif
	return (sign << 31) | ((((exp + 127) << 23) | frac) + rounding);
}

int main(int argc, char *argv[])
{
#if TESTONE == 1
	int i = 2147483648;
	show_float((float)i);
	show_int(float_i2f(i));
#else
	for (unsigned i = 0; i < 0xFFFFFFFF; ++i) {
			float sys_result = (int)i;
			float_bits my_result = float_i2f(i);
			
			if (sys_result != *(float*)&my_result) {
				printf("wrong i = %d, sys_result = %f, *(float*)&my_result = %f\n", i, sys_result, *(float*)&my_result);
				break;
			}
		}	
#endif
	return 0;
}