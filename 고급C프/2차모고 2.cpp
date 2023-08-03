#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, i, j, k;
	char x[101];
	scanf("%d %s",&n, x);
	getchar();
	char** Y = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++) {
		char input[101];
		gets_s(input);
		if (Y == NULL) {
			printf("Not Enough Memory!\n");
			return -1;
		}
		Y[i] = (char*)malloc(sizeof(char) * (strlen(input) + 1));
		strcpy(Y[i], input);
	}
	int maxCnt=0;
	char finalStr[101]="";
	for (i = 0; i < n; i++) {
		int cnt=0;
		for (j = 0; j < strlen(Y[i]); j++) {
			if (Y[i][j] == x[0]) {
				char comStr[101];
				for (k = 0; k < strlen(x); k++) {
					comStr[k] = Y[i][j+k];
				}
				comStr[k]=NULL;
				if (strcmp(comStr, x) == 0) {
					cnt++;
					j += strlen(x)-1;
				}
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
			strcpy(finalStr,Y[i]);
		}
	}
	if (maxCnt == 0) {
		printf("NONE");
	}
	else {
		printf("%s",finalStr);
	}

	for (i = 0; i < n; i++) {
		free(Y[i]);
	}
	free(Y);
}