#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st {
	char *str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
}St;
int main() {
	int n,i,j;
	scanf("%d",&n);
	St* stArr=(St*)malloc(sizeof(St)*n);
	if (stArr == NULL) {
		printf("Not Enough Memory");
		return -1;
	}
	for (i = 0; i < n; i++) {
		char str[101];
		getchar();
		scanf("%s",str);
		int len=strlen(str);
		stArr[i].str = (char*)malloc(sizeof(char)*(len+1));
		if (stArr[i].str == NULL) {
			printf("Not Enough Memory");
			return -1;
		}
		strcpy(stArr[i].str, str);
	}
	for (i = 0; i < n; i++) {
		int moumCnt=0;
		for (j = 0; j < strlen(stArr[i].str); j++) {
			if (stArr[i].str[j] == 'a' || stArr[i].str[j] == 'e' || stArr[i].str[j] == 'i' || stArr[i].str[j] == 'o' || stArr[i].str[j] == 'u'
				|| stArr[i].str[j] == 'A' || stArr[i].str[j] == 'E' || stArr[i].str[j] == 'I' || stArr[i].str[j] == 'O' || stArr[i].str[j] == 'U') {
				moumCnt++;
			}
			else if ('0' <= stArr[i].str[j] && stArr[i].str[j] <= '9') {
				stArr[i].num = stArr[i].str[j] - '0';
				stArr[i].pos = j+1;
			}
		}
		stArr[i].cnt1 = strlen(stArr[i].str) - moumCnt - 1;
		stArr[i].cnt2 = strlen(stArr[i].str);
		stArr[i].result = (stArr[i].cnt1)*(stArr[i].cnt2)*(stArr[i].num)*(stArr[i].pos);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (stArr[j].result < stArr[j + 1].result) {
				St tmp = stArr[j];
				stArr[j] = stArr[j+1];
				stArr[j+1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s\n",stArr[i].str);
	}

	for (i = 0; i < n; i++) {
		free(stArr[i].str);
	}
	free(stArr);
}