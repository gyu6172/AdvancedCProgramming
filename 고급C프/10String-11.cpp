#include <stdio.h>
#include <string.h>
int main() {
	char str1[81], str2[11];
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	int i, j;
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);

	for (i = 0; i < str1Len; i++) {
		if (str1[i] == str2[0]) {
			int chk = 1;
			for (j = 0; j < str2Len; j++) {
				if (str1[i + j] != str2[j]) {
					chk = 0;
				}
			}
			if (chk == 1) {
				printf("%d 1", str1Len);
				return 0;
			}
		}
	}
	printf("%d 0", str1Len);
}