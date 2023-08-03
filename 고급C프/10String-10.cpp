#include <stdio.h>
#include <string.h>
int main() {
	int n, i;
	int min = 100;
	char minstr[200];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		char str[101];
		gets_s(str);
		if (strlen(str) < min) {
			min = strlen(str);
			strcpy(minstr, str);
		}
	}
	printf("%s", minstr);
}