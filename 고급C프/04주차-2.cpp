#include <stdio.h>
#include <string.h>
int main() {
	char A[90];
	char ch = 'A';
	int n;
	scanf("%s", A);
	scanf("%d", &n);
	int i, j;
	int cnt = 0;
	int ALen = strlen(A);
	int chk = 0;
	for (i = 0; i < ALen; i++) {
		if ('1' <= A[i] && A[i] <= '9') {
			if ('0' <= A[i + 1] && A[i + 1] <= '9') {
				chk = 2;
				cnt = (A[i] - '0') * 10 + (A[i + 1] - '0');
				ch = (ch + cnt - 1);

				for (i = 0; i < ALen; i++) {
					if ('1' <= A[i] && A[i] <= '9') {
						for (j = ALen; j > i; j--) {
							A[j + n - chk] = A[j];
						}

						for (j = i; j < i + n; j++) {
							A[j] = ch;
						}
					}
				}
				break;
			}
			else {
				chk = 1;
				cnt = A[i] - '0';
				ch = (ch + cnt - 1);

				for (i = 0; i < ALen; i++) {
					if ('1' <= A[i] && A[i] <= '9') {
						for (j = ALen; j > i; j--) {
							A[j + n - chk] = A[j];
						}

						for (j = i; j < i + n; j++) {
							A[j] = ch;
						}
					}
				}
				break;
			}
		}
	}
	printf("%s\n", A);

}