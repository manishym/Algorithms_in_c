#include "seed.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#ifndef __APPLE__
       #include <sys/types.h> 
       #include <sys/stat.h>  
       #include <fcntl.h>     

int seed_random(){
	int fd = open("/dev/random", O_RDONLY);
	int ret, seed ; 
	time_t now ;
	
	if(fd < 0) {
		perror ("open(): ");

		goto bail;
	}
	
	ret = read(fd, &seed, sizeof(int));
	if(ret < 0) {
		perror( "read(): " );
		goto bail;
	}
	srand(seed);
	return 0;
bail:
	time(&now);
	srand(now);
	return -1;

}
#endif
int seed_array(int array[], int max, int length) {
	int i;
#ifdef __APPLE__
	srandomdev();
#else
	seed_random();
#endif
	
	for(i = 0; i < length; i++){
		array[i] = (int)random() % max;
	}
	srand(array[5]);
    

}
int *swap (int * a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return a;
}

