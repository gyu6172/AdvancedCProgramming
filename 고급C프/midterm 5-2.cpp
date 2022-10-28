#include <stdio.h>
#include <string.h>
//redorange redyellow greenred bluepurple yellow
//red
//white
int main() {
	char A[101], B[11], C[11], D[251] = "";
	int Diter = 0;
	gets_s(A);
	scanf("%s %s", B, C);
	int Alen = strlen(A);
	int Blen = strlen(B);
	int Clen = strlen(C);
	char* p = A;
	int i, j, k;
	int cnt = 0;
	for (p = A, i = 0; p < A + Alen; p++, i++) {
		if (strncmp(p, B, Blen) == 0) {
			cnt++;
			p += Blen - 1;
			i += Blen - 1;
			strcat(D, C);
			Diter += Clen;
		}
		else {
			D[Diter++] = A[i];
		}
	}
	printf("%d\n", cnt);
	printf("%s\n%s", D, A);

}