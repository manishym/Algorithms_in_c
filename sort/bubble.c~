#include <stdio.h>
#include "../lib/seed.h"


int selection_sort(int array[], int len){
	int i, j, temp;
	for(i = 0; i < len; i++){
		for( j = i; j < len; j++) {
			if(array[j] < array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
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
	selection_sort(array, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
}
