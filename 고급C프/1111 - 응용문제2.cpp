#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string {
	char* str;
	int words;
}String;
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	String* strs = (String*)malloc(sizeof(String) * n);

	int i, j, k;
	for (i = 0; i < n; i++) {
		char tmp[101];
		gets_s(tmp);
		strs[i].str = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(strs[i].str, tmp);
	}
	for (i = 0; i < n; i++) {
		int blankCnt = 0;
		for (j = 0; j < strlen(strs[i].str); j++) {
			if (strs[i].str[j] == ' ') {
				blankCnt++;
			}
		}
		strs[i].words = blankCnt + 1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strs[j].words < strs[j + 1].words) {
				String tmpString = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = tmpString;
			}
		}
	}

	for (i = 0; i < n; i++) {
		char **wordsArr = (char**)malloc(sizeof(char*)*(strs[i].words));
		int wordsIter=0;
		char tmp[101]="";
		int tmpIter=0;
		for (j = 0; j < strlen(strs[i].str); j++) {
			if (strs[i].str[j] == ' ') {
				tmp[tmpIter++] = NULL;
				wordsArr[wordsIter] = (char*)malloc(sizeof(char)*tmpIter);
				strcpy(wordsArr[wordsIter++], tmp);
				tmpIter=0;
			}
			else {
				tmp[tmpIter++] = strs[i].str[j];
			}
		}
		tmp[tmpIter++] = NULL;
		wordsArr[wordsIter] = (char*)malloc(sizeof(char) * tmpIter);
		strcpy(wordsArr[wordsIter++], tmp);
		tmpIter = 0;

		int maxWordCnt=0;
		char maxWord[101]="";
		for (j = 0; j < wordsIter; j++) {
			int wordsCnt=0;
			for (k = 0; k < wordsIter; k++) {
				if (strcmp(wordsArr[j], wordsArr[k]) == 0) {
					wordsCnt++;
				}
			}
			if (maxWordCnt < wordsCnt) {
				maxWordCnt = wordsCnt;
				strcpy(maxWord, wordsArr[j]);
			}
			else if (maxWordCnt == wordsCnt) {
				if (strcmp(maxWord, wordsArr[j]) > 0) {
					maxWordCnt = wordsCnt;
					strcpy(maxWord, wordsArr[j]);
				}
			}
		}

		printf("%s %d %s %d\n",strs[i].str, strs[i].words, maxWord, maxWordCnt);

		for (j = 0; j < wordsIter; j++) {
			free(wordsArr[j]);
		}
		free(wordsArr);
	}

	for (i = 0; i < n; i++) {
		free(strs[i].str);
	}
	free(strs);


}