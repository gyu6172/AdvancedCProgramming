#include <stdio.h>
#include <string.h>
int main() {
	char str1[101], str2[101];
	gets_s(str1);
	scanf("%s", str2);
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	int i, j, k;
	int cnt = 0;
	for (i = 0; i < str1Len; i++) {
		if (str1[i] == str2[0]) {
			int chk = 1;
			for (j = 0; j < str2Len; j++) {
				if (str1[i + j] != str2[j]) {
					chk = 0;
					break;
				}
			}
			if (chk) {
				cnt++;
				i += str2Len - 1;
			}
		}
	}
	printf("%d", cnt);
}