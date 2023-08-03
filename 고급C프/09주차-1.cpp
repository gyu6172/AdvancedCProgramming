#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st {
	char* str;
	int cnt;
}St;
int main() {
	int n, i, j, k;
	scanf("%d", &n);
	St* strs = (St*)malloc(sizeof(St) * n);
	char tmpStr[101];
	for (i = 0; i < n; i++) {
		strs[i].str = (char*)malloc(sizeof(char) * 101);
	}
	for (i = 0; i < n; i++) {
		int cnt = 0;
		getchar();
		scanf("%s", tmpStr);
		strcpy((strs + i)->str, tmpStr);
		for (j = 0; j < strlen(tmpStr); j++) {
			if (tmpStr[j] != 'a' && tmpStr[j] != 'e' && tmpStr[j] != 'i' && tmpStr[j] != 'o' && tmpStr[j] != 'u') {
				cnt++;
			}
		}
		(strs + i)->cnt = cnt;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (strs[i].cnt > strs[j].cnt) {
				St tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %d\n", strs[i].str, strs[i].cnt);
	}
	for (i = 0; i < n; i++) {
		free(strs[i].str);
	}
	free(strs);
}