#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define SIZE 1000 

int main(int argc, char * argv[])
{
	int matrix[SIZE][SIZE]; 
	int sum=0;
	int i,j;
	struct timeval t0,t1;
	gettimeofday(&t0, 0);
	
	  
	for(i=0;i<SIZE;i++) 
	{ 
		for(j=0;j<SIZE;j++) 
		{ 
			sum+=matrix[i][j]; 
		} 
	} 
	gettimeofday(&t1, 0);
 	long elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	
	gettimeofday(&t0, 0);
	sum=0; 
	for(i=0;i<SIZE;i++) 
	{ 
		for(j=0;j<SIZE;j++) 
		{ 
			sum+=matrix[j][i]; 
		} 
	} 
	gettimeofday(&t1, 0);
	long elapsed2 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	printf("temps 1 : %ld\n",elapsed1);
	printf("temps 2 : %ld\n",elapsed2);
	printf("le temps 1 est %ld fois plus court que le temps 2", (elapsed2/elapsed1));
	
	return (sum+1); 


} 
