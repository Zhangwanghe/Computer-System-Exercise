#include <stdio.h>

typedef enum{NEG, ZERO, POS, OTHER} range_t;

range_t find_range_c(float x)
{
	int result;
	if (x < 0) 
		result = NEG;
	else if (x == 0)
		result = ZERO;
	else if (x > 0)
		result = POS;
	else
		result = OTHER;
	
	return result;
}

range_t find_range(float x)
{

	{
        asm volatile(
			"movq     $0, %rax            \n"
			"vxorps   %xmm1, %xmm1, %xmm1 \n"
			"vucomiss %xmm0, %xmm1        \n"
			"ja       .L1                 \n"
			"jp		  .L8                 \n"
			"je		  .L2                 \n"
			"jb		  .L3                 \n"			
			".L8:                         \n"
			"addq     $1, %rax            \n"
			".L3:                         \n"
			"addq     $1, %rax            \n"
			".L2:                         \n"
			"addq     $1, %rax            \n"
			".L1:                         \n"
        );
    }
}

int main(int argc, char *argv[])
{
	//int a = 0x7f800001;
	//printf("find_range %d\n", find_range_c(*(float*)&a));
	for (int i = 0; i < 0xFFFFFFFF; i++)
	{
		if (find_range(*(float*)&i) != find_range_c(*(float*)&i))
		{
			printf("i = %.8x", i);
			printf("find_range %d\n", find_range(*(float*)&i));
			printf("find_range_c %d\n", find_range_c(*(float*)&i));
			break;
		}
	}
}