#include <stdio.h>
#include <string.h>
int main() {
	char A[101];
	gets_s(A);

	char B[11], C[11];
	scanf("%s %s", B, C);
	getchar();

	int i, j;
	int Alen = strlen(A);
	for (i = 0; i < Alen; i++) {
		if (A[i] == B[0]) {
			int chk = 1;
			for (j = 0; j < strlen(B); j++) {
				if (A[i + j] != B[j]) {
					chk = 0;
				}
			}
			if (chk) {
				if (strlen(B) > strlen(C)) {
					int d = strlen(B) - strlen(C);
					for (j = i; j < Alen; j++) {
						A[j] = A[j+d];
					}
					Alen -= d;
				}
				else if (strlen(B) < strlen(C)) {
					int d = strlen(C) - strlen(B);
					Alen += d;
					for (j = Alen; j-d >= i; j--) {
						A[j] = A[j - d];
					}
				}

				for (j = 0; j < strlen(C); j++) {
					A[i+j] = C[j];
				}

				i += strlen(C) - 1;
			}
		}
	}
	printf("%s",A);
}