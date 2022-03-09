/* 
 * hello.c - Pthreads "hello, world" program 
 */
/* $begin hello */
#include "csapp.h"
void *thread(void *vargp);                    //line:conc:hello:prototype
void usage();

int main(int argc, char** argv)                                    //line:conc:hello:main
{
	if (argc < 2) {
		usage(argv);
	}
	
	int thread_num = atoi(argv[1]);
	if (thread_num < 0) {
		usage(argv);
	}
	
    pthread_t *tid = (pthread_t*)malloc(thread_num * sizeof(pthread_t));                            
	for (int i = 0; i < thread_num; ++i) {
		Pthread_create(tid + i, NULL, thread, NULL); //line:conc:hello:create
    }
	
	for (int i = 0; i < thread_num; ++i) {
		Pthread_join(*(tid + i), NULL);  
    }
	
    exit(0);                                  //line:conc:hello:exit
}

void usage(char** argv)
{
	printf("usage: %s [thread num]\n", argv[0]);
	exit(1);
}

void *thread(void *vargp) /* thread routine */  //line:conc:hello:beginthread
{
    printf("Hello, world!\n");                 
    return NULL;                               //line:conc:hello:return
}                                              //line:conc:hello:endthread
/* $end hello */
