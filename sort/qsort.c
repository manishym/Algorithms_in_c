#include <stdio.h>
#include "../lib/seed.h"


int quick_sort(int array[], int len){
	int pivot=array[len/2];
	int i=0, j=len - 1;
	if(len <= 1)
		return array[0];
	while( i < j) {
		while (array[i] <= pivot && i < j) i++;
		while (array[j] > pivot && i < j) j--;
		if(i >= j)
			break ;
		if(array[i] > array[j])
			swap(&array[i], &array[j]);
	}
	for(j = 0; j < len; j++){
	}
	quick_sort(&array[0], i);
	quick_sort(&array[i], len - i);
}

int main(int argc, char *argv[])
{
	int array[10], i;
	seed_array(array, 10, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
	quick_sort(array, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
}
// replock-migrate.sh
