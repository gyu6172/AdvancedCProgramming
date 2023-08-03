#include <stdio.h>
int isEnd(char a);
int main() {
	char str[1001];
	char* p = str;
	char* q;
	while (1) {
		scanf("%c", p);
		if (isEnd(*p) == 1)
			break;
		p++;
	}
	char a;
	for (p = str;; p++) {
		if (isEnd(*p) == 1) {
			a = *p;
			break;
		}
	}
	p--;

	for (p = p; isEnd(*p) != 1; p--) {
		if (isEnd(*p) == 2) {
			for (q = p + 1; isEnd(*q) == 0; q++) {
				printf("%c", *q);
			}
			printf(" ");
		}
		else if (p == str) {
			for (q = p; isEnd(*q) == 0; q++) {
				printf("%c", *q);
			}
			printf("%c", a);
		}
	}
}

int isEnd(char a)
{
	if (a == '!' || a == '?' || a == '.') {
		return 1;
	}
	else if (a == ' ')
		return 2;
	else {
		return 0;
	}
}