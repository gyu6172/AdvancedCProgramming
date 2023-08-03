#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
}