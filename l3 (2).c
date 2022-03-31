#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
	printf("\n i am in init function\n"); 
}

void *mythread(void *i)
{
	printf("\n  i am in my Thread \n");
	pthread_once(&once, (void *)myinit);
	printf("\n Exit from myThread : %d\n", (int *)i);
}


int main(){
	
	pthread_t thread, thread1, thread2;
	
	pthread_create(&thread,NULL, mythread, (void *)1);
	
	pthread_create(&thread,NULL, mythread, (void *)2);
	
	pthread_create(&thread,NULL, mythread, (void *)3);
		
	printf("\n Exit from main Thread\n");
	pthread_exit(NULL);
	
return 0;
}