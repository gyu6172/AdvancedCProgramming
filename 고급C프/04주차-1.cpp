#include <stdio.h>
int main() {
	char A[51];
	scanf("%s", &A);
	int i, j;
	int num = 0;
	int chk = 0;
	for (i = 0; A[i] != NULL; i++) {
		if ('0' <= A[i] && A[i] <= '9') {
			chk = 1;
			num = num * 10 + (A[i] - '0');
		}
		else {
			if (chk == 1) {
				printf("%d\n", num);
				num = 0;
				chk = 0;
			}
		}
	}
	if (chk == 1) {
		printf("%d\n", num);
	}
}