#include <stdio.h>
#include "seed.h"

int main (void)
{
	int array[100], i;
	seed_array(array, 100, 100);
	for(i = 0; i < 100; i++)
		printf("%d\n", array[i]);
}
