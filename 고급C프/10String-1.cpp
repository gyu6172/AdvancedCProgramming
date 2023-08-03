#include <stdio.h>
int main() {
	char str[20];
	scanf("%s", str);
	int i;
	for (i = 0; str[i] != NULL; i++) {
		if ('a' <= str[i] && str[i] <= 'z')
			printf("%c", str[i]);
	}
}