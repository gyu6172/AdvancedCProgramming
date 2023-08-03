#include <stdio.h>
int main() {
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	unsigned int n;

	n = (a<<24)+(b<<16)+(c<<8)+(d);

	printf("%d", n);
}