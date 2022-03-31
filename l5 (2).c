#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <bits/types.h>
#include <sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
	int rc;
	int count = 0;
	printf("Entered Thread is%d, getting spin lock \n",(int *)i);
	rc = pthread_spin_lock(&spinlock);
	
	printf("%dThread that unlock the spin lock\n", (int *)i);
	rc = pthread_spin_unlock(&spinlock);
	printf("%d Thread completed.",(int *)i);
	return NULL;
}


int main(){
	
	int rc = 0;
	pthread_t thread, thread1;
	
	if(pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE)!=0)
	perror("init");
	printf("main, getspin lock\n");
	rc = pthread_spin_lock(&spinlock);
	
	printf("main, create spin lock thread:\n");
	rc = pthread_create(&thread, NULL, spinlockthread, (int *)1);
	
	printf("main, waiting\n");
	sleep(10);
	
	printf("main, now the spinlock is unlocked\n");
	
	rc = pthread_spin_unlock(&spinlock);
	
	if(rc == 0)
	{
		printf("\n main Thread unlocked sucessfully\n");
	}
	else{
		printf("\n mainThread unlocked Failed\n");
	}
	
	printf("main, wait for the Thread to stop\n");
	rc = pthread_join(thread, NULL);
	
	printf("main Task completed\n");
	
return 0;
}