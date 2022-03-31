#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void function(void *thread)
{
 int tid = (int)(thread);
 printf("Thread ID is: %u\n",tid);
 int p1;
 p1 = getpid();
 printf("PID:%d\n",p1);
}

int main()
{
 pthread_t tid;
 pthread_create(&tid, NULL, function, tid);
 pthread_join(tid, NULL);
 printf("Thread termination is started\n");
 pthread_exit(NULL);
 printf("Thread ID is: %u\n", tid);
 printf("Thread termination is completed sucessfully\n");
}