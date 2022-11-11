#include <stdio.h>
int factorial(int n);
int main() {
	int n;
	scanf("%d",&n);
	double rst=1.0;
	for (int i = 1; i <= n; i++) {
		rst += 1.0/factorial(i);
		
	}
	printf("%f",rst);
}
int factorial(int n) {
	if(n==1)
		return 1;
	return factorial(n - 1) * n;
}