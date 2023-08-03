#include <stdio.h>
#include <math.h>
typedef struct Point {
	int x;
	int y;
}POINT;
double distance(POINT *p1, POINT *p2);
int main() {
	POINT p1,p2;
	scanf("%d %d", &(p1.x), &(p1.y));
	scanf("%d %d", &(p2.x), &(p2.y));
	printf("%.4f",distance(&p1,&p2));
}

double distance(POINT* p1, POINT* p2)
{
	double rst = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
	return rst;
}
