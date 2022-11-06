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
		for (j = i; j < n; j++) {
			if (strcmp(str[i],str[j])>0) {
				char* s = str[i];
				str[i] = str[j];
				str[j] = s;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}
	for (i = 0; i < n; i++) {
		free(str[i]);
	}
	free(str);
}