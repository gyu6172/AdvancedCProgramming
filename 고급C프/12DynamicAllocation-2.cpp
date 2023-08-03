#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int i;
	scanf("%d", &n);
	float* p = (float*)malloc(sizeof(float) * n);
	for (i = 0; i < n; i++) {
		scanf("%f", p + i);
	}

	float max = p[0];
	for (i = 0; i < n; i++) {
		if (max < p[i])
			max = p[i];
	}
	printf("%.2lf", max);
	free(p);
}