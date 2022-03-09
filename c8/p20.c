#include <unistd.h>

int main(int argc, char** argv, char** env)
{
	execve("/bin/ls", argv, env);
}