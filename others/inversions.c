#include <stdio.h>
#include "../lib/seed.h"

int across_inv(int array[], int sub1[], int sub2[], int len){
	int i = 0, j = 0, k=0;
	int inversions=0 ;
	while (k < len){
		if(i >= len/2) {
			array[k++] = sub2[j++] ;
			continue;
		}
		if(j >= len -  len/2) {
			array[k++] = sub1[i++] ;
			continue;
		}
		if(sub1[i] <= sub2[j])
			array[k++] = sub1[i++] ;
		else 
		{
			array[k++] = sub2[j++] ;
			inversions += len/2 - i;
		}
	}
	return inversions;
}

int count_inversions(int array[], int len){
	int sub1[len/2];
	int sub2[len - len/2];
	int i, left = 0, right = 0, across = 0;

	if (len <= 1){
		return 0;
	}
	for(i = 0; i < len/2; i++){
		sub1[i] = array[i];
	}
	for(i = 0; i < len - len/2; i++){
		sub2[i] = array[i+len/2];
	}
	left = count_inversions(sub1, len/2)  ;
	right = count_inversions(sub2, len - len/2)  ;
	across= across_inv(array, sub1, sub2, len);
	return left+right+across;
}

int main(int argc, char *argv[])
{
	int array[10], i;
	seed_array(array, 10, 10);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
	i = count_inversions(array, 10);
	printf("inversions: %d\n", i);
	for(i=0; i < 10; i++) {
		printf ("%d\t", array[i]);
	}
	printf("\n");
}
