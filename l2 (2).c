#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

struct data{
int i;
char g;
char c[60];
};

void* structure(void *param)
{
 struct data *s;
 s = (struct data *) param;
 printf("structure is: \t \nname: %s \t age= %i \t gender: %c\n",s->c,s->i,s->g);
 return NULL;
}

int main()
{
 pthread_t thread1;
 pthread_t thread2;

 struct data thread1_args;
 struct data thread2_args;

 pthread_create(&thread1, NULL, structure, (void *)&thread1_args);
 pthread_create(&thread2, NULL, structure, (void *)&thread2_args);

 thread1_args.i = 21;
 strcpy(thread1_args.c, "sanket\n");
 thread1_args.g = 'M';

 thread2_args.i = 21;
 strcpy(thread2_args.c, "raju\n");
 thread2_args.g = 'F';

 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);

 return 0;
}
