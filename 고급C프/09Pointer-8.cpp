#include <stdio.h>
void swap(int* a, int* b);
int main() {
	int n;
	scanf("%d", &n);

	int ar[50];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}

	int a, b;
	scanf("%d %d", &a, &b);
	swap(&ar[a], &ar[b]);

	for (int i = 0; i < n; i++) {
		printf(" %d", ar[i]);
	}
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}