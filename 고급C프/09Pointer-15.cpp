#include <stdio.h>
void ABC(int* p, int k);
int main() {
	int arr[20];
	int* p;
	for (p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}
	int k;
	for (p = arr, k = 10; p < arr + 10; p++, k--) {
		ABC(p, k);
	}
	for (p = arr; p < arr + 10; p++) {
		printf(" %d", *p);
	}
}
void ABC(int* p, int k)
{
	int* max = p;
	int* x;
	for (x = p; x < p + k; x++) {
		if (*max < *x) {
			int* tmp = max;
			max = x;
			x = tmp;
		}
	}
	int tmp = *p;
	*p = *max;
	*max = tmp;
}