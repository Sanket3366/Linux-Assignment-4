#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


void *my(void *i)
{
printf("\n I am in:%dThread\n",(int *)i);
}


int main(){
	
	
	struct sched_param param;
	
	int priority, policy, ret;
	
	ret = pthread_getschedparam(pthread_self(), &policy, &param);
	
	if (ret != 0)
	{
		perror("getschedparam");
	}
	
	printf("\n*****************main thread***************\n policy : %d \n priority : %d\n", policy, param.sched_priority);
	
	policy = SCHED_FIFO;
	param.sched_priority = 2;
	
	ret = pthread_getschedparam(pthread_self(), &policy, &param);
	if (ret != 0)
	{
		perror("getschedparam");
	}
	
	
	printf("\n************************main thread****************************\n policy : %d \n priority : %d\n", policy, param.sched_priority);
	
return 0;
}