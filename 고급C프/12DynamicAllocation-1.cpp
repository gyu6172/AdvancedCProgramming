#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i;
	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += p[i];
	}
	printf("%d", sum);
	free(p);
}