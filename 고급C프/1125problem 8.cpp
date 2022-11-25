#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int main() {
	int (*handle[3]) (int, int) = { add, sub, multiply };

	int a,b;
	scanf("%d %d",&a,&b);

	printf("%d %d %d",handle[0](a,b), handle[1](a,b), handle[2](a,b));
}
int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x-y;
}

int multiply(int x, int y)
{
	return x*y;
}