#include <stdio.h>
int main() {
	char str1[50], str2[50], str3[100];
	int str3Iter = 0;
	int i = 0, j;
	scanf("%s", &str1);
	scanf("%s", &str2);

	while (1) {
		if (str1[i] > str2[i]) {
			for (j = 0; str1[j] != NULL; j++) {
				str3[str3Iter] = str1[j];
				str3Iter++;
			}
			for (j = 0; str2[j] != NULL; j++) {
				str3[str3Iter] = str2[j];
				str3Iter++;
			}
			break;
		}
		else if (str1[i] < str2[i]) {
			for (j = 0; str2[j] != NULL; j++) {
				str3[str3Iter] = str2[j];
				str3Iter++;
			}
			for (j = 0; str1[j] != NULL; j++) {
				str3[str3Iter] = str1[j];
				str3Iter++;
			}
			break;
		}
		else {
			i++;
		}
	}
	str3[str3Iter] = NULL;
	printf("%s", str3);
}