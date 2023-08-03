#include <stdio.h>
int* mid(int arr[]);
int main() {
	int x[3];
	int* p;
	p = x;
	scanf("%d %d %d", p, p + 1, p + 2);

	printf("%d", *mid(x));
}

int* mid(int ar[])
{
	int* a;
	int* b;
	int* c;
	a = ar;
	b = ar + 1;
	c = ar + 2;

	int* p = ar;

	if (*a >= *b && *a >= *c) {
		p = (*b > *c) ? b : c;
	}
	else if (*b >= *a && *b >= *c) {
		p = (*a > *c) ? a : c;
	}
	else if (*c >= *b && *c >= *a) {
		p = (*a > *b) ? a : b;
	}

	return p;
}