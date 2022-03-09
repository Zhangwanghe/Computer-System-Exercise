#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <FCNTL.H>
#include <sys/stat.h>

int main(int argc, char** argv, char** env)
{
	if (argc < 2)
	{
		return 0;
	}
	
	int fd = open(argv[1], O_RDWR, 0777);
	if (fd == -1)
	{
		printf("open file error: %s\n", argv[1]);
	}
	
	struct stat fileState;	
	fstat(fd, &fileState);
	int filesize = fileState.st_size;
	
	char* buf = mmap(NULL, filesize, PROT_WRITE | PROT_WRITE, MAP_SHARED, fd, 0);
	buf[0] = 'J';
	close(fd);
	
	munmap(buf, filesize);
	
	return 0;
}