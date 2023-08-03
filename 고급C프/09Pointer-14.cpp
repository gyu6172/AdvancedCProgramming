#include <stdio.h>
int add_to_k(int* p1, int* p2);

int main() {
	int d[100];
	int n;
	scanf("%d", &n);
	int* p;
	for (p = d; p < d + n; p++) {
		scanf("%d", p);
	}
	int sum = 0;
	p = d;
	for (int i = 0; i < n; i++) {
		sum += add_to_k(p, p + i);
	}
	printf("%d", sum);
}
int add_to_k(int* p1, int* p2)
{
	int sum = 0;
	for (int* p = p1; p <= p2; p++) {
		sum += *p;
	}
	return sum;
}