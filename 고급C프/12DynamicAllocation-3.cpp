#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j;
	char c1, c2;
	int cnt1 = 0, cnt2 = 0;
	scanf("%d", &n);
	getchar();
	char* pStr = (char*)malloc(sizeof(char) * (n + 1));
	scanf("%s", pStr);
	getchar();
	scanf("%c %c", &c1, &c2);
	for (i = 0; i < n; i++) {
		if (c1 == pStr[i])
			cnt1++;
		if (c2 == pStr[i])
			cnt2++;
	}
	printf("%d %d", cnt1, cnt2);
	free(pStr);
}