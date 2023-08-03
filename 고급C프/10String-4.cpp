#include <stdio.h>
int main() {
	char str1[100], str2[100];
	scanf("%s", &str1);
	scanf("%s", &str2);

	int i;
	int n = 0;
	for (i = 0; str1[i] != NULL; i++) {
		n++;
	}
	int chk = 1;
	for (i = 0; i < n; i++) {
		if (str1[i] != str2[i] || str2[i] == NULL) {
			chk = 0;
			break;
		}
	}
	printf("%d %d", n, chk);
}