#include <string.h>
#include <stdio.h>
int main() {
	char str[201];
	char strArr[20][200];

	gets_s(str);

	int i,j,arrIter=0;
	char tmp[201];
	int tmpIter=0;
	for (i = 0; i <= strlen(str); i++) {
		if (str[i] == ' ' || str[i] == NULL) {
			tmp[tmpIter]=0;
			tmpIter=0;
			strcpy(strArr[arrIter++], tmp);
		}
		else {
			tmp[tmpIter++] = str[i];
		}
	}

	for (i = 0; i < arrIter; i++) {
		printf("%s\n",strArr[i]);
	}

	for (i = 0; i < arrIter; i++) {
		for (j = i; j < arrIter; j++) {
			if (strcmp(strArr[i], strArr[j]) > 0) {
				char tmp[201];
				strcpy(tmp, strArr[i]);
				strcpy(strArr[i], strArr[j]);
				strcpy(strArr[j], tmp);
			}
		}
	}

	for (i = 0; i < arrIter; i++) {
		printf("%s ", strArr[i]);
	}
}