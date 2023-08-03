#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	char* str = (char*)malloc(sizeof(char) * (n + 1));
	getchar();
	scanf("%s", str);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'c' && str[i + 1] == 'a' && str[i + 2] == 't') {
			cnt++;
		}
	}
	printf("%d", cnt);
	free(str);
}