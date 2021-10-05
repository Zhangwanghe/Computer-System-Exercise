#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* my_calloc(size_t nmemb, size_t size) {
	if (nmemb == 0 || size == 0) {
		return NULL;
	}
	
	size_t real_size = nmemb * size;
	if (real_size / size != nmemb) {
		return NULL;
	}
	
	void* ret = malloc(real_size);
	memset(ret, 0, real_size);
	
	return ret;
}

int main(int argc, char *argv[])
{

	return 0;
}