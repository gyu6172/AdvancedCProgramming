#include <stdio.h>
#include <string.h>
int check(char* p);
int main() {
	char str[31];
	scanf("%s", str);
	printf("%d %d", strlen(str), check(str));
}
int check(char* p)
{
	int len = strlen(p);
	char* q = p + len - 1;
	for (; p < q; p++, q--) {
		if (*p != *q) {
			return 0;
		}
	}
	return 1;
}
