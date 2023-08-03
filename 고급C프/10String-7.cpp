#include <stdio.h>
const char* numToStr(int n);
int main() {
	int n;
	scanf("%d", &n);
	char tho[4] = "THO";
	char hun[4] = "HUN";
	char ten[4] = "TEN";
	while (n != 0) {
		if (n / 1000 > 0) {
			printf("%s %s ", numToStr(n / 1000), tho);
			n = n % 1000;
		}
		else if (n / 100 > 0) {
			printf("%s %s ", numToStr(n / 100), hun);
			n = n % 100;
		}
		else if (n / 10 > 0) {
			printf("%s %s ", numToStr(n / 10), ten);
			n = n % 10;
		}
		else {
			printf("%s ", numToStr(n));
			break;
		}
	}
}
const char* numToStr(int n)
{
	switch (n) {
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	}

}