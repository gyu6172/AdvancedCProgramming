#include <stdio.h>
void strcopy(char a[], char b[]);

int main() {
	char a[6], b[6];
	char* p = a;
	for (p = p; p < a + 6; p++) {
		scanf("%c", p);
	}

	strcopy(a, b);

	for (p = b; p < b + 6; p++) {
		printf("%c", *p);
	}
}
void strcopy(char a[], char b[])
{
	char* p1 = a;
	char* p2 = b;
	for (p1 = a, p2 = b; p1 < a + 6; p1++, p2++) {
		*p2 = *p1;
	}
}