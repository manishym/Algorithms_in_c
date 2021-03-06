#include <stdio.h>
#include "../lib/seed.h"

int merge(int array[], int sub1[], int sub2[], int len){
	int i = 0, j = 0, k=0;
	while (k < len){
		if(i >= len/2) {
			array[k++] = sub2[j++] ;
			continue;
		}
		if(j >= len -  len/2) {
			array[k++] = sub1[i++] ;
			continue;
		}
		if(sub1[i] < sub2[j])
			array[k++] = sub1[i++] ;
		else 
			array[k++] = sub2[j++] ;
	}
	return k;
}

int * merge_sort(int array[], int len){
	int sub1[len/2];
	int sub2[len - len/2];
	int i;

	if (len <= 1){
		return array;
	}
	for(i = 0; i < len/2; i++){
		sub1[i] = array[i];
	}
	for(i = 0; i < len - len/2; i++){
		sub2[i] = array[i+len/2];
	}
	merge_sort(sub1, len/2)  ;
	merge_sort(sub2, len - len/2)  ;
	merge(array, sub1, sub2, len);
	return array;
}

int main(int argc, char *argv[])
{
	int array[10], i;
	seed_array(array, 10, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
	merge_sort(array, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
}
