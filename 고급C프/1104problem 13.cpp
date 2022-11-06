#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,i,j,d;
	scanf("%d",&n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		int id;
		scanf("%d",&id);
		arr[i] = id;
	}
	scanf("%d",&d);
	arr = (int*)realloc(arr,sizeof(int)*(n-d));
	for (i = 0; i < n - d; i++) {
		printf("%d\n",arr[i]);
	}
}