#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h> 
#include <errno.h>

#define NTHREADS 6 

int global =0;
int increment(int i);
void *f(void * param);

int main (int argc, char *argv[]) 
{ 
	printf("\n\nDebut du programme \n\n\n");
	int err;
	pthread_t thread[NTHREADS];
	int i;
	for(i=0;i<NTHREADS;i++)
	{
		err=pthread_create(&(thread[i]),NULL,&f,NULL);
		if(err!=0)
		{
			error(err,"pthread_create");
		}
	}
	for(i=0;i<NTHREADS;i++)
	{
		err=pthread_join(thread[i],NULL);
		if(err !=0)
		{
			error(err,"pthread_join");
		}
	}
	
	
	printf("%d\n\n",global);
	
	return(EXIT_SUCCESS); 
} 
int increment(int i)
{
	
	return (i+1);
}
void *f(void * param)
{
	
	int i;
	for(i=0;i<100000;i++)
	{
		global=increment(global);
	}
	return(NULL);
}
