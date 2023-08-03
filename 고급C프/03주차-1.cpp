#include <stdio.h>
int* MIN(int ar[]);
int* MAX(int ar[]);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int arr[100];
		int arrIter = 0;
		int a;
		for (int j = 0; j < 100; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] == 0)
				break;
		}

		printf("%d %d\n", *MAX(arr), *MIN(arr));
	}
}
int* MAX(int ar[])
{
	int* p;
	int* max = ar;
	for (p = ar; *p != 0; p++) {
		if (*max < *p) {
			int* tmp = max;
			max = p;
			p = tmp;
		}
	}
	return max;
}

int* MIN(int ar[])
{
	int* p;
	int* min = ar;
	for (p = ar; *p != 0; p++) {
		if (*min > *p) {
			int* tmp = min;
			min = p;
			p = tmp;
		}
	}
	return min;
}
