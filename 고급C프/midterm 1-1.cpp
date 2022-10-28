#include <stdio.h>
#include <string.h>
//i am looking forward to seeing the next one
int main() {
	char str[201];
	char divStr[20][201];
	gets_s(str);
	int i, j, divIter = 0, tmpIter = 0;
	int n = strlen(str);
	char tmp[201] = "";
	for (i = 0; i < n; i++) {
		if (str[i] == ' ') {
			tmp[tmpIter] = NULL;
			int chk = 0;
			for (j = 0; j < divIter; j++) {
				if (strcmp(tmp, divStr[j]) == 0) {
					chk = 1;
					break;
				}
			}
			if (!chk) {
				strcpy(divStr[divIter], tmp);
				divIter++;
			}
			tmpIter = 0;
		}
		else {
			tmp[tmpIter++] = str[i];
		}
	}
	tmp[tmpIter] = NULL;
	int chk = 0;
	for (j = 0; j < divIter; j++) {
		if (strcmp(tmp, divStr[j]) == 0) {
			chk = 1;
			break;
		}
	}
	if (!chk) {
		strcpy(divStr[divIter], tmp);
		divIter++;
	}
	tmpIter = 0;
	for (i = 0; i < divIter; i++) {
		for (j = 0; j < i; j++) {
			int iLen = strlen(divStr[i]);
			int jLen = strlen(divStr[j]);
			if (iLen < jLen) {
				char tmpStr[201];
				strcpy(tmpStr, divStr[i]);
				strcpy(divStr[i], divStr[j]);
				strcpy(divStr[j], tmpStr);
			}
		}
	}


	for (i = 0; i < divIter; i++) {
		printf("%s\n", divStr[i]);
	}



}