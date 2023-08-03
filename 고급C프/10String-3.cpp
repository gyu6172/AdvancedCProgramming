#include <stdio.h>
int main() {
	char str[100];
	scanf("%s", &str);
	int i, j;
	int len = 0;
	for (i = 0; str[i] != NULL; i++) {
		len++;
	}
	for (i = 0; i < len; i++) {
		printf("%s\n", str);
		char a = str[0];
		for (j = 0; j < len - 1; j++) {
			str[j] = str[j + 1];
		}
		str[j] = a;

	}
}