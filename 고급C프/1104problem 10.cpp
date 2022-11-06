#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,i,j;
	scanf("%d",&n);
	int* arrN = (int*)malloc(sizeof(int)*n);
	int* arrM = (int*)malloc(sizeof(int)*(n-1));
	for (i = 0; i < n; i++) {
		arrN[i] = i;
	}
	int iter=0;
	for (i = 0; i < n; i++) {
		if (i == (n - 1) / 2) {
			continue;
		}	
		arrM[iter++] = i;
	}

	for (i = 0; i < n-1; i++) {
		printf(" %d",arrM[i]);
	}
	free(arrN);
	free(arrM);
}