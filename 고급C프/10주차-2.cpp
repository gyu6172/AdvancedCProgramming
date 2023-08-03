#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_c(char* p, char *q);
int main() {
	char strArr[10][101];
	int arrIter = 0;
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	getchar();
	for (i = 0; i < n; i++) {
		char str[101];
		gets_s(str);
		strcpy(strArr[arrIter++], str);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (count_c(strArr[j], strArr[j]+m) < count_c(strArr[j + 1], strArr[j+1]+m)) {
				char s[101];
				strcpy(s, strArr[j]);
				strcpy(strArr[j], strArr[j + 1]);
				strcpy(strArr[j + 1], s);
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (count_c(strArr[i], strArr[i]+m) == 0) {
			continue;
		}
		printf("%s %d\n", strArr[i], count_c(strArr[i], strArr[i] + m));
	}

}

int count_c(char* p, char* q)
{
	while (p+strlen(p)<q) {
		q--;
	}
	char* iter;
	int i, j;
	int cnt = 0;
	for (iter = p; iter <= q; iter++) {
		if ('a' <= *iter && *iter <= 'z') {
			cnt++;
		}
		else if ('A' <= *iter && *iter <= 'Z') {
			cnt++;
		}
		else if (*iter == ' ')
			cnt++;
	}
	i = 0;
	for (iter = p; iter <= q; iter++) {
		i++;
	}

	return (i - cnt);
}
