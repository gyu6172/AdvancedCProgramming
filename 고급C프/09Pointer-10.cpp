#include <stdio.h>
void gcdlcm(int a, int b, int* p1, int* p2);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int n1, n2;
	gcdlcm(a, b, &n1, &n2);
	printf("%d %d", n1, n2);
}

void gcdlcm(int a, int b, int* p1, int* p2)
{
	int i, j;
	int n1, n2;
	for (i = a; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			n1 = i;
			break;
		}
	}
	for (i = a;; i++) {
		if (i % a == 0 && i % b == 0) {
			n2 = i;
			break;
		}
	}
	*p1 = n1;
	*p2 = n2;
}
