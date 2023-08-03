#include <stdio.h>
#include <string.h>
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char longStr[101], shortStr[101];
	int longStrlen=0, shortStrlen=101;

	int i,j;
	for (i = 0; i < n; i++) {
		char inputStr[101];
		gets_s(inputStr);
		if (strlen(inputStr) > longStrlen) {
			strcpy(longStr, inputStr);
			longStrlen = strlen(longStr);
		}
		else if (strlen(inputStr) < shortStrlen) {
			strcpy(shortStr, inputStr);
			shortStrlen = strlen(shortStr);
		}
	}

	char longStrWords[20][101], shortStrWords[20][101];
	char tmpStr[101];
	int tmpIter=0, longStrWordsIter=0, shortStrWordsIter=0;
	for (i = 0; i <= strlen(longStr); i++) {
		if (longStr[i] == ' ' || longStr[i] == NULL) {
			tmpStr[tmpIter++]=NULL;
			strcpy(longStrWords[longStrWordsIter++],tmpStr);
			tmpIter=0;
		}
		else {
			tmpStr[tmpIter++] = longStr[i];
		}
	}
	for (i = 0; i <= strlen(shortStr); i++) {
		if (shortStr[i] == ' ' || shortStr[i] == NULL) {
			tmpStr[tmpIter++] = NULL;
			strcpy(shortStrWords[shortStrWordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = shortStr[i];
		}
	}


	char longStrShortWord[101];
	int longStrShortWordLen = 101;
	for (i = 0; i < longStrWordsIter; i++) {
		if (strlen(longStrWords[i]) < longStrShortWordLen) {
			strcpy(longStrShortWord, longStrWords[i]);
			longStrShortWordLen = strlen(longStrShortWord);
		}
	}

	char shortStrLongWord[101];
	int shortStrLongWordLen = 0;
	for (i = 0; i < shortStrWordsIter; i++) {
		if (strlen(shortStrWords[i]) > shortStrLongWordLen) {
			strcpy(shortStrLongWord, shortStrWords[i]);
			shortStrLongWordLen = strlen(shortStrLongWord);
		}
	}
	printf("%s\n%s\n", longStr, shortStr);
	if (strcmp(longStrShortWord, shortStrLongWord) > 0) {
		printf("%s%s",shortStrLongWord, longStrShortWord);
	}
	else {
		printf("%s%s", longStrShortWord, shortStrLongWord);
	}


}