#include <stdio.h>
#include <string.h>
int main() {
	char A[101], B[11], C[11];
	gets_s(A);
	scanf("%s %s", B, C);
	getchar();

	int len=strlen(A);

	int i,j,k;

	for (i = 0; i < len; i++) {
		if (A[i] == B[0]) {
			int chk=1;
			for (j = 0; j < strlen(B); j++) {
				if (A[i + j] != B[j]) {
					chk = 0;
				}
			}
			if (chk) {
				if (strlen(B) < strlen(C)) {
					int d = strlen(C)-strlen(B);
					len += d;
					for (j = len; j-d >= i; j--) {
						A[j] = A[j-d];
					}
				}

				else if (strlen(B) > strlen(C)) {
					int d = strlen(B) - strlen(C);
					for (j = i; j < len; j++) {
						A[j] = A[j+d];
					}
					len -= d;
				}

				for (j = 0; j < strlen(C); j++) {
					A[i+j] = C[j];
				}

				i += strlen(C) - 1;
			}
		}
	}
	printf("%s", A);
}