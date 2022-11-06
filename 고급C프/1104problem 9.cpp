#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	getchar();
	char** str = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		char tmp[101];
		gets_s(tmp);
		str[i] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(str[i], tmp);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (strlen(str[j]) < strlen(str[j+1])) {
				char* s = str[j];
				str[j] = str[j+1];
				str[j+1] = s;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n",str[i]);
	}
	for (i = 0; i < n; i++) {
		free(str[i]);
	}
	free(str);
}