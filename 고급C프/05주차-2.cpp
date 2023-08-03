#include <stdio.h>
#include <string.h>
int main() {
	char str[201], maxLenStr[401], nowStr[401];
	gets_s(str);
	int len = strlen(str);
	int i;
	int maxCnt = 0;
	int nowCnt = 0;
	for (i = 0; i < len; i++) {
		if (str[i] != ' ') {
			nowStr[nowCnt] = str[i];
			nowCnt++;
		}
		else {
			if (nowCnt > maxCnt) {
				maxCnt = nowCnt;
				//nowStr[nowCnt] = NULL;
				strcpy(maxLenStr, nowStr);
			}
			nowCnt = 0;
		}
	}
	if (nowCnt > maxCnt) {
		maxCnt = nowCnt;
		//nowStr[nowCnt] = NULL;
		strcpy(maxLenStr, nowStr);
	}
	printf("%s", maxLenStr);
}