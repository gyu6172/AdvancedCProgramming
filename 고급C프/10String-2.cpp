#include <stdio.h>
int main() {
	int n;
	char str[10];
	int strIter = 0;
	scanf("%d", &n);
	while (n != 0) {
		int a = n % 10;
		str[strIter] = (char)(a + 48);
		strIter++;
		n /= 10;
	}
	str[strIter] = '\0';
	printf("%s", str);
}