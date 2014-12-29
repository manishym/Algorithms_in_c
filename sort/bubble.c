#include <stdio.h>
#include "../lib/seed.h"


int bubble_sort(int array[], int len){
	int i, j, temp;
	for(i = 0; i < len; i++){
		for( j = 0; j < i; j++) {
			if(array[j] > array[i]){
				swap(&array[j], &array[i]);

			}
		}
	}


}

int main(int argc, char *argv[])
{
	int array[10], i;
	seed_array(array, 10, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
	bubble_sort(array, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
}
