#include <stdio.h>
void input(int* a, int* b, int* c);
void output(int* a, int* b, int* c);
int main() {
	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);
}
void input(int* a, int* b, int* c)
{
	scanf("%d %d %d", a, b, c);
}

void output(int* a, int* b, int* c)
{
	printf("%d %d %d", *a, *b, *c);
}