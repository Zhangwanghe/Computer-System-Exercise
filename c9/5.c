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
	
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("open file error: %s\n", argv[1]);
	}
	
	struct stat fileState;	
	fstat(fd, &fileState);
	int filesize = fileState.st_size;
	char* buf = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
	write(STDOUT_FILENO, buf, filesize);
	
	close(fd);
	
	return 0;
}