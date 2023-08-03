#include <stdio.h>
int add(int x, int y);
int main() {
	int a;
	scanf("%d",&a);
	getchar();
	void *pa = &a;
	printf("%d\n", *((int*)pa));

	int x,y;
	scanf("%d %d",&x,&y);

	int (*ptrAdd)(int x, int y) = &add;
	printf("%d",ptrAdd(x,y));
}

int add(int x, int y)
{
	return x+y;
}
