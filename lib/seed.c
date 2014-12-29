#include "seed.h"
#include <stdio.h>

int seed_array(int array[], int max, int length) {
	int i;
	srandomdev();
	for(i = 0; i < length; i++){
		array[i] = (int)random() % max;
	}
    

}
int *swap (int * a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return a;
}

