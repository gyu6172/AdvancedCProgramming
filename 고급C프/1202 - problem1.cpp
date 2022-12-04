#include<stdio.h>
#define ABS(a)(a>=0)? a:-1*a
#define MAX(a,b) (a>b)? a : b
int main() {

	int arr[6];
	int i, j;
	for (i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
	}
	int max = arr[0];

	for (i = 0; i < 5; i++) {
		max = MAX(arr[i], max);
	}

	printf("%d %d", max, ABS(max));

	return 0;
}