#include <stdio.h>
#include <string.h>
int main() {
	char str[100], arr[100][100] ,tmp[100];
	gets_s(str);
	int n = strlen(str);
	int i, j, arrIter=0, tmpIter=0;
	for (i = 0; i < n; i++) {
		if (str[i] == ' ') {
			tmp[tmpIter]=NULL;
			strcpy(arr[arrIter++], tmp);
			tmpIter=0;
		}	
		else {
			tmp[tmpIter++] = str[i];
		}
	}
	tmp[tmpIter] = NULL;
	strcpy(arr[arrIter++], tmp);
	char result[100];
	strcpy(result, arr[0]);
	for (i = 0; i < arrIter; i++) {
		if (strcmp(arr[i], result)<0 && strcmp(arr[i],"")!=0) {
			strcpy(result, arr[i]);
		}
	}
	printf("%s",result);

}