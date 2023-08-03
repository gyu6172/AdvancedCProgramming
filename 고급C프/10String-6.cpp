#include <stdio.h>
int main() {
	char str1[41], str2[21];
	int index;
	int reverse;
	scanf("%s", &str1);
	scanf("%s", &str2);
	scanf("%d", &index);
	scanf("%d", &reverse);
	int i, j, k;
	int str1Len = 0, str2Len = 0;
	for (i = 0; str1[i] != NULL; i++) {
		str1Len++;
	}
	for (i = 0; str2[i] != NULL; i++) {
		str2Len++;
	}
	if (reverse) {
		for (i = 0, j = str2Len - 1; i < j; i++, j--) {
			char a = str2[i];
			str2[i] = str2[j];
			str2[j] = a;
		}
	}
	for (i = 0; i < str2Len; i++) {
		for (j = str1Len + i; j > index; j--) {
			str1[j] = str1[j - 1];
		}
	}
	for (i = 0; i < str2Len; i++) {
		str1[i + index] = str2[i];
	}
	str1Len += str2Len;
	str1[str1Len] = NULL;
	printf("%s", str1);
}