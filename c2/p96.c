#include <stdio.h>
#include <limits.h>
#include <string.h>

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

float_bits float_f2i(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;

	if (exp < 126) {
		return 0;
	} else if (exp == (127 + 31) && sign == 0x1 && frac == 0x0){
		return INT_MIN;
	} else if (exp > (127 + 30)){
		return 0x80000000;
	} else {
		int offset_left = exp - (23 + 127);
		int ret = 0;
		if (offset_left < 0) {			
			//printf("%d %d\n", frac >> (-offset_left), 1 << (exp - 127));
			ret = ((sign << 31) | ((frac >> (-offset_left)) + (1 << (exp - 127))));
			//show_int(ret);
		} else {
			//printf("2\n");
			ret = (sign << 31) | ((frac << offset_left) + (1 << (exp - 127)));
		}
		
		// -0 -> +0
		if ((ret & 0x7FFFFFFF) == 0) {
			return 0;
		}
		
		// < 0
		if (sign != 0) {			
			ret = (sign << 31) | (INT_MIN - (ret & 0x7FFFFFFF));
		}
		
		return ret;
	}
}

int main(int argc, char *argv[])
{
	//printf("%d\n", float_f2i(0xBF800000));
	for (unsigned i = 0; i <= 0x7F800000; ++i) {
		float f = *(float*)&i;
		int sys_result = (int)f;
		float_bits my_result = float_f2i(i);
		
		if (sys_result != (int)my_result) {
			printf("wrong i = %d, sys_result = %d, *(float*)&my_result = %d\n", i, sys_result, *(float*)&my_result);
			show_int(i);
			show_int(my_result);
			show_int(sys_result);
			break;
		}
	}
	
	for (unsigned i = 0x80000000; i <= 0xFF800000; ++i) {
		float f = *(float*)&i;
		int sys_result = (int)f;
		float_bits my_result = float_f2i(i);
		
		if (sys_result != (int)my_result) {
			printf("wrong i = %d, sys_result = %d, *(float*)&my_result = %d\n", i, sys_result, my_result);
			break;
		}
	}
	
	return 0;
}