#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(char* command)
{
	int status, pid;
	
	if ((pid = fork()) == 0) {
		execl("/bin/sh", "sh", "-c", command, (char *) 0);
	} else {
		waitpid(-1, &status, 0);
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		} else if (WIFSIGNALED(status)) {
			return WTERMSIG(status);
		} else{
			return 0;
		}
	}		
}

int main(int argc, char** argv) {
	if (argc < 2) {
		return -1;
	}
	
	mysystem(argv[1]);
}