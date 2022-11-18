#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n;
	char x[101];
	scanf("%d %s",&n,x);
	getchar();
	
	int i,j,k;
	char **y = (char**)malloc(sizeof(char*)*n);

	for (i = 0; i < n; i++) {
		char tmpStr[101];
		gets_s(tmpStr);

		y[i] = (char*)malloc(sizeof(char)*(strlen(tmpStr)+1));
		strcpy(y[i], tmpStr);
	}
	
	char firstStr[101]="", secondStr[101]="";
	int firstRe=0, secondRe=0;
	for (i = 0; i < n; i++) {
		char tmpStr[101];
		strcpy(tmpStr, y[i]);
		int reCnt=0;
		for (j = 0; j < strlen(tmpStr); j++) {
			if (x[0] == tmpStr[j]) {
				int chk=1;
				for (k = 0; k < strlen(x); k++) {
					if (x[k] != tmpStr[j + k]) {
						chk=0;
					}
				}
				if (chk) {
					reCnt++;
					j += strlen(x)-1;
				}
			}
		}
		if (reCnt > firstRe) {
			secondRe = firstRe;
			firstRe = reCnt;
			strcpy(secondStr, firstStr);
			strcpy(firstStr,tmpStr);
		}
		else if (reCnt > secondRe) {
			secondRe = reCnt;
			strcpy(secondStr, tmpStr);
		}
	}
	printf("%s\n%s",firstStr, secondStr);

}