/* $begin cpfile */
#include "csapp.h"

int main(int argc, char **argv) 
{
    int n;
    rio_t rio;
    char buf[MAXLINE];
	
	int fd = -1;
	if (argc > 1) {
		fd = Open(argv[1], O_RDONLY, 0);
		dup2(fd, STDIN_FILENO);
	}
	
    Rio_readinitb(&rio, STDIN_FILENO);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) 
	Rio_writen(STDOUT_FILENO, buf, n);

	if (fd >= 0) {
		Close(fd);
	}
	
    /* $end cpfile */
    exit(0);
    /* $begin cpfile */
}
/* $end cpfile */



