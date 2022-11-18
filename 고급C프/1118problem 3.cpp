#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char A[101], B[101];
	gets_s(A);
	gets_s(B);

	int i, j, k;
	int AblankCnt = 0;
	for (i = 0; i < strlen(A); i++) {
		if (A[i] == ' ') {
			AblankCnt++;
		}
	}
	int BblankCnt = 0;
	for (i = 0; i < strlen(B); i++) {
		if (B[i] == ' ') {
			BblankCnt++;
		}
	}

	char** Awords = (char**)malloc(sizeof(char*) * (AblankCnt + 1));
	char** Bwords = (char**)malloc(sizeof(char*) * (BblankCnt + 1));

	char tmpStr[101];
	int tmpIter = 0, AwordsIter = 0, BwordsIter = 0;
	for (i = 0; i <= strlen(A); i++) {
		if (A[i] == ' ' || A[i] == NULL) {
			tmpStr[tmpIter++] = NULL;
			Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			strcpy(Awords[AwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = A[i];
		}
	}
	for (i = 0; i <= strlen(B); i++) {
		if (B[i] == ' ' || B[i] == NULL) {
			tmpStr[tmpIter++] = NULL;
			Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			strcpy(Bwords[BwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = B[i];
		}
	}

	char resultWords[101][101];
	int resultIter = 0;

	for (i = 0; i < AwordsIter; i++) {
		for (j = i + 1; j < AwordsIter; j++) {
			char str1[101] = "", str2[101] = "";
			strcat(str1, Awords[i]);
			strcat(str1, Awords[j]);

			strcat(str2, Awords[j]);
			strcat(str2, Awords[i]);

			for (k = 0; k < BwordsIter; k++) {
				if (strcmp(Bwords[k], str1) == 0 || strcmp(Bwords[k], str2) == 0) {
					strcpy(resultWords[resultIter++], Bwords[k]);
				}
			}
		}
	}

	char resultStr[101] = "";
	int resultStrlen = 0;

	for (i = 0; i < resultIter; i++) {
		if (resultStrlen < strlen(resultWords[i])) {
			strcpy(resultStr, resultWords[i]);
			resultStrlen = strlen(resultStr);
		}
	}

	for (i = 0; i < resultIter; i++) {
		if (resultStrlen == strlen(resultWords[i])) {
			if (strcmp(resultStr, resultWords[i]) > 0) {
				strcpy(resultStr, resultWords[i]);
			}
		}
	}
	printf("%s", resultStr);
}