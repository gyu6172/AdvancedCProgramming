#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int* arr = (int*)malloc(sizeof(int)*5);
	int iter=0;
	int max=5;
	while (1) {
		int n;
		scanf("%d",&n);
		if (iter < max) {
			arr[iter++]=n;
		}
		else if (iter >= max) {
			arr = (int*)realloc(arr, sizeof(int)*(max+=3));
			arr[iter++] = n;
		}
		if(n==-1)
			break;
	}
	for (int i = 0; i < iter; i++) {
		printf(" %d",arr[i]);
	}
}