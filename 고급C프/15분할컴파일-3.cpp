#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m;
	scanf("%d %d", &m, &n);

	int** arr = (int**)malloc(sizeof(int*) * n);
	int i, j;
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * m);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		int cnt = 0;
		if (arr[i][0] == 1) {
			printf("0 ");
		}
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cnt++;
				if (arr[i][j + 1] == 1 || arr[i][j+1]==NULL) {
					printf("%d ",cnt);
					cnt=0;
				}
			}
			else if (arr[i][j] == 1) {
				cnt++;
				if (arr[i][j + 1] == 0 || arr[i][j + 1] == NULL) {
					printf("%d ", cnt);
					cnt = 0;
				}
			}
		}
		printf("\n");
	}
}