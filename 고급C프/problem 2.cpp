#include <stdio.h>
int main() {
	int arr[100];
	int n,m,i,j,k,p,q;
	scanf("%d %d",&n,&m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d",&arr[j]);
		}
		for (p = 0; p < m; p++) {
			int maxCnt = 0;
			int maxNum = 0;
			for (j = 0; j < m; j++) {
				int cnt = 0;
				for (k = 0; k < m; k++) {
					if (arr[j] == arr[k] && arr[j] > 0) {
						cnt++;
					}
				}
				if (cnt > maxCnt) {
					maxCnt = cnt;
					maxNum = arr[j];
				}
			}
			for (j = 0; j < m; j++) {
				if (maxNum == arr[j]) {
					printf("%d ", arr[j]);
					arr[j] = 0;
					break;
				}
			}
		}
		printf("\n");
	}
}