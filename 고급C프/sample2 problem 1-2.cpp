#include <stdio.h>
#include <string.h>
int main() {
	int n,m1,m2, i, j;
	int longLen=0, shortLen=101;
	char longStr[101], shortStr[101], finalStr[101]="";
	char longWord[101]="", shortWord[101]="";
	int longWordIter=0, shortWordIter=0;
	scanf("%d %d %d",&n,&m1,&m2);
	getchar();
	for (i = 0; i < n; i++) {
		char inputStr[101];
		gets_s(inputStr);
		if (longLen < strlen(inputStr)) {
			longLen = strlen(inputStr);
			strcpy(longStr, inputStr);
		}
		else if (shortLen > strlen(inputStr)) {
			shortLen = strlen(inputStr);
			strcpy(shortStr, inputStr);
		}
	}
	int longStrSpaceCnt=0;
	for (i = 0; i < longLen; i++) {
		if (longStrSpaceCnt == m1) {
			break;
		}
		if (longStr[i] == ' ') {
			longStrSpaceCnt++;
		}
	}
	for (i = i;; i++) {
		if (longStr[i] == ' ' || longStr[i] == NULL) {
			break;
		}
		longWord[longWordIter++] = longStr[i];
	}
	longWord[longWordIter++] = NULL;



	int shortStrSpaceCnt = 0;
	for (i = 0; i < shortLen; i++) {
		if (shortStrSpaceCnt == m2) {
			break;
		}
		if (shortStr[i] == ' ') {
			shortStrSpaceCnt++;
		}
	}
	for (i = i;; i++) {
		if (shortStr[i] == ' ' || shortStr[i] == NULL) {
			break;
		}
		shortWord[shortWordIter++] = shortStr[i];
	}
	shortWord[shortWordIter++] = NULL;

	if (strcmp(longWord, shortWord) > 0) {
		strcat(finalStr, shortWord);
		strcat(finalStr, longWord);
	}
	else {
		strcat(finalStr, longWord);
		strcat(finalStr, shortWord);
	}
	
	printf("%s\n%s\n%s",longStr, shortStr, finalStr);
}