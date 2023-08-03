#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n,i,j;
	scanf("%d",&n);
	getchar();
	char** str = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++) {
		char tmp[101];
		gets_s(tmp);
		str[i] = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
		strcpy(str[i], tmp);
	}
	int minCnt=101;
	char finalStr[101]="";
	for (i = 0; i < n; i++) {
		if (strlen(str[i]) < minCnt) {
			minCnt = strlen(str[i]);
			strcpy(finalStr, str[i]);
		}
	}
	printf("%s",finalStr);
	for (i = 0; i < n; i++) {
		free(str[i]);
	}
	free(str);
}