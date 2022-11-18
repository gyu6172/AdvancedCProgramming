#include <stdio.h>
#include <string.h>
int main() {
	char A[101], B[101];
	gets_s(A);
	gets_s(B);

	int i, j, k;

	char Awords[101][101], Bwords[101][101];

	char tmpStr[101];
	int tmpIter = 0, AwordsIter = 0, BwordsIter = 0;
	for (i = 0; i <= strlen(A); i++) {
		if (A[i] == ' ' || A[i] == NULL) {
			tmpStr[tmpIter++] = NULL;
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
			strcpy(Bwords[BwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = B[i];
		}
	}

	int BswapIter=0;

	for (i = 0; i < AwordsIter; i++) {
		for (j = i - 1; j>= 0; j--) {
			if (strcmp(Awords[i], Awords[j]) == 0) {
				strcpy(Awords[i], Bwords[BswapIter++]);
			}
		}
	}

	char resultStr[251]="";
	for (i = 0; i < AwordsIter; i++) {
		strcat(resultStr, Awords[i]);
		strcat(resultStr, " ");
	}
	printf("%s",resultStr);
}