#include <stdio.h>
int main() {
	int n;
	int ar[100];
	int arIter = 0;
	int i, j;
	while (1) {
		scanf("%d", &n);
		if (n < 0)
			break;

		int chk = 0;
		for (i = 0; i < arIter; i++) {
			if (ar[i] == n) {
				chk = 1;
				break;
			}
		}
		if (!chk) {
			printf("1");
			ar[arIter] = n;
			arIter++;
		}
		else {
			printf("0");
		}
	}
}