#include <stdio.h>
#include <stdlib.h>
int check_row(int **p, int m, int n);
int check_col(int ** p, int m, int n);
int main() {
	int m,n, i, j, k;
	scanf("%d %d",&m, &n);
	int** arr = (int**)malloc(sizeof(int*)*m);
	for (i = 0; i < m; i++) {
		arr[i] = (int*)calloc(n,sizeof(int));
	}
	while (1) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		getchar();
		if(x==0 && y==0 && z==0)
			break;
		arr[x][y] = z;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	if (check_col(arr, m, n) > check_row(arr, m, n)) {
		printf("%d",check_col(arr, m, n));
	}
	else {
		printf("%d",check_row(arr, m, n));
	}

	for (i = 0; i < m; i++) {
		free(arr[i]);
	}
	free(arr);
}

int check_row(int** p, int m, int n)
{
	int i,j;
	int maxCnt=0;
	int cnt=0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (p[i][j] == 0) {
				cnt++;
			}
			else if (p[i][j] != 0) {
				if (maxCnt < cnt) {
					maxCnt = cnt;
				}
				cnt=0;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
		}
		cnt = 0;
	}
	return maxCnt;
}

int check_col(int** p, int m, int n)
{
	int i, j;
	int maxCnt = 0;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (p[j][i] == 0) {
				cnt++;
			}
			else if (p[j][i] != 0) {
				if (maxCnt < cnt) {
					maxCnt = cnt;
				}
				cnt = 0;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
		}
		cnt = 0;
	}
	return maxCnt;
}
