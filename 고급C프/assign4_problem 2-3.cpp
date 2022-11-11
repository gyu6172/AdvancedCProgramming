#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char A[101], B[101];
	gets_s(A);
	gets_s(B);

	int AblankCnt = 0, BblankCnt = 0;
	int i, j, k;
	for (i = 0; i < strlen(A); i++) {
		if (A[i] == ' ') {
			AblankCnt++;
		}
	}
	for (i = 0; i < strlen(B); i++) {
		if (B[i] == ' ') {
			BblankCnt++;
		}
	}

	char** Awords = (char**)malloc(sizeof(char*) * (AblankCnt + 1));
	char** Bwords = (char**)malloc(sizeof(char*) * (BblankCnt + 1));

	if (Awords == NULL || Bwords == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}

	char tmpStr[101];
	int tmpIter = 0;
	int AwordsIter = 0;
	for (i = 0; i < strlen(A); i++) {
		if (A[i] == ' ') {
			tmpStr[tmpIter++] = NULL;
			Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			if (Awords[AwordsIter] == NULL) {
				printf("Not Enough Memory!");
				return -1;
			}
			strcpy(Awords[AwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = A[i];
		}
	}
	tmpStr[tmpIter++] = NULL;
	Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Awords[AwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Awords[AwordsIter++], tmpStr);
	tmpIter = 0;

	int BwordsIter = 0;
	for (i = 0; i < strlen(B); i++) {
		if (B[i] == ' ') {
			tmpStr[tmpIter++] = NULL;
			Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			if (Bwords[BwordsIter] == NULL) {
				printf("Not Enough Memory!");
				return -1;
			}
			strcpy(Bwords[BwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = B[i];
		}
	}
	tmpStr[tmpIter++] = NULL;
	Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Bwords[BwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Bwords[BwordsIter++], tmpStr);
	tmpIter = 0;

	//printf("Aword : %d, Bword : %d\n",AwordsIter, BwordsIter);
	//for (i = 0; i < AwordsIter; i++) {
	//	printf("%s\n",Awords[i]);
	//}
	//for (i = 0; i < BwordsIter; i++) {
	//	printf("%s\n", Bwords[i]);
	//}

	char resultStr[101][101];
	int resultIter = 0;

	for (i = 0; i < AwordsIter; i++) {
		for (j = i + 1; j < AwordsIter; j++) {
			//AcombStr1은 Awords[i] 뒤에 Awords[j]를 붙인 것이고,
			//AcombStr2는 Awords[j] 뒤에 Awords[i]를 붙인 것이다.
			char AcombStr1[201], AcombStr2[201];
			strcpy(AcombStr1, Awords[i]);
			strcat(AcombStr1, Awords[j]);

			strcpy(AcombStr2, Awords[j]);
			strcat(AcombStr2, Awords[i]);

			for (k = 0; k < BwordsIter; k++) {
				if (strcmp(AcombStr1, Bwords[k]) == 0 || strcmp(AcombStr2, Bwords[k]) == 0) {
					strcpy(resultStr[resultIter++], Bwords[k]);
				}
			}

		}
	}

	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			if (strlen(resultStr[i]) < strlen(resultStr[j])) {
				char tmpStr1[101];
				strcpy(tmpStr1, resultStr[i]);
				strcpy(resultStr[i], resultStr[j]);
				strcpy(resultStr[j], tmpStr1);
			}
		}
	}

	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			if (strlen(resultStr[i]) == strlen(resultStr[j])) {
				if (strcmp(resultStr[i], resultStr[j]) > 0) {
					char tmpStr1[101];
					strcpy(tmpStr1, resultStr[i]);
					strcpy(resultStr[i], resultStr[j]);
					strcpy(resultStr[j], tmpStr1);
				}
			}
		}
	}

	for (i = 0; i < resultIter; i++) {
		if (i == 0) {
			printf("%s\n", resultStr[i]);
		}
		else if (strcmp(resultStr[i], resultStr[i - 1])!=0) {
			printf("%s\n", resultStr[i]);
		}
	}


}