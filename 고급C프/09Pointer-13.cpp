#include <stdio.h>
int arrsum(int* s, int* e);

int main() {
	int n, s, e;
	int i, j;
	int arr[100];
	scanf("%d %d %d", &n, &s, &e);
	int* p = arr;
	for (p = p; p < arr + n; p++)
		scanf("%d", p);
	p = arr;
	printf("%d", arrsum(p + s, p + e));

}

int arrsum(int* s, int* e)
{
	int sum = 0;
	for (int* p = s; p <= e; p++) {
		sum += *p;
	}

	return sum;
}