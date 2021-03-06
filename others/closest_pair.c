#include <stdio.h>
#include <unistd.h>
#include "../lib/seed.h"
#include <string.h>

#define LENGTH 50
#define MAX_INT 100000

typedef struct point {
	int x;
	int y;
}point ;

typedef struct pair {
	point p1;
	point p2;
	int distance ;
} pair ;

int seed_point(point p[], int len) {
	int a[len], b[len], i;
	int c[len], d[len];
	seed_array(a, len, len);
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

int comparey(void *a, void *b){
	point *p, *q ;
	p = a;
	q = b;
	return p->y > q->y ;
}
int comparex(void *a, void *b){
	point *p, *q ;
	p = a;
	q = b;
	return p->x > q->x ;
}
print_point_array (char *str, point p[], int len) {
	int i;
	printf ("%s", str);
	for(i=0; i<len; i++) {
		print_point(p[i]);
	}
}
pair combine(point x[], point y[], point p[], int len, int min){
	pair small;

}

pair closest(point x[], point y[], point p[], len) {
	pair right, left, comb;
	int min;
	if(len <= 1) {
		return MAX_INT ;
	}
	if (len == 2){
		return distance(x[0], x[1]);
	left = closest(x, len/2);
	right = closest(&x[len/2], len - len/2);
	m = min(left.distance, right.distance)
	comb = combine(x, y, p, len, m);
	return min(m, comb.length);

}


pair find_min(point p[], int len) {
	pair xy_right, xy_left;
	point x[len], y[len] ;
	memcpy(x, p, len*sizeof(p));
	memcpy(y, p, len*sizeof(p));
	qsort(x, len, sizeof(p), comparex);
	qsort(y, len, sizeof(p), comparey);
	xy = closest(x, y, p, len);
	print_point_array("After sorting x:\n", x, len);
	print_point_array("After sorting y:\n", y, len);
	return xy;


}

int main(int argc, char *argv[])
{
	int i;
	point p[LENGTH];
	seed_point(p, LENGTH);
	int j, min, dist;
	point min_p1, min_p2;
	pair closest ;
	int len=LENGTH;


	for(i=0; i < LENGTH; i++) {
		print_point (p[i]);
	}
	min = distance(p[1], p[0]);
	min_p1 = p[1];
	min_p2= p[0];
#ifdef ON2
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
#else
	closest = find_min(p, len);
#endif
	printf("The min points are:\n");
	print_point(min_p1);
	print_point(min_p2);
	printf("And min distance is: %d", min);


				
	printf("\n");
}
