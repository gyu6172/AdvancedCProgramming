#include <stdio.h>
void addArray(int* p1, int* p2, int* p3, int size);

int main() {
	int n;
	int x[20], y[20], z[20];
	scanf("%d", &n);
	int* p;
	for (p = x; p < x + n; p++) {
		scanf("%d", p);
	}
	for (p = y; p < y + n; p++) {
		scanf("%d", p);
	}
	addArray(x, y, z, n);
	for (p = z; p < z + n; p++) {
		printf(" %d", *p);
	}
}
void addArray(int* p1, int* p2, int* p3, int size)
{
	for (int i = 0; i < size; i++) {
		*(p3 + i) = *(p1 + i) + *(p2 + (size - i - 1));
	}
}