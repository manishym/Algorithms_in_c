#include <stdio.h>
#include <unistd.h>
#include "../lib/seed.h"

#define LENGTH 50

typedef struct point {
	int x;
	int y;
}point ;

int seed_point(point p[], int len) {
	int a[len], b[len], i;
	int c[len], d[len];
	seed_array(a, len, len);
#ifndef __APPLE__

#endif
	seed_array(b, len, len);
	for (i = 0; i < len; i++) {
		c[i] = i;
		d[i] = i;
	}
	for (i = 0; i < len; i++) {
		swap(&c[i], &c[a[i]]);
		swap(&d[i], &d[b[i]]);
	}
	for(i=0; i<len; i++){
		p[i].x = c[i];
		p[i].y = d[i];

	}
	return 0;
}
int square(int x) {
	return x * x;
}

int distance(point p1, point p2){
	return square(p1.x - p2.x) + square(p1.y - p2.y) ;


}

int print_point(point p){
	printf("(%d,%d)\n", p.x, p.y);
}
int main(int argc, char *argv[])
{
	int i;
	point p[LENGTH];
	seed_point(p, LENGTH);
	int j, min, dist;
	point min_p1, min_p2;


	for(i=0; i < LENGTH; i++) {
		print_point (p[i]);
	}
	min = distance(p[1], p[0]);
	min_p1 = p[1];
	min_p2= p[0];
	for(i = 0; i < LENGTH; i++) {
		for (j = i+1; j < LENGTH; j++) {
			dist = distance(p[i], p[j]);
			if(dist < min){
				min = dist;
				min_p1 = p[i];
				min_p2 = p[j] ;
			}
		}
	}
	printf("The min points are:\n");
	print_point(min_p1);
	print_point(min_p2);
	printf("And min distance is: %d", min);


				
	printf("\n");
}
