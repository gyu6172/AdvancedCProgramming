#include <stdio.h>
#include <string.h>
int main() {
	char str[21];
	int n;
	gets_s(str);
	scanf("%d", &n);
	char newstr[201];
	int newiter = 0;
	int i, j;
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			newstr[newiter] = str[i] - n;
			newiter++;
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			newstr[newiter] = str[i] + n;
			newiter++;
		}
		else if ('0' <= str[i] && str[i] <= '9') {
			int num = str[i] - '0';
			if ('0' <= str[i + 1] && str[i + 1] <= '9') {
				num = num * 10 + str[i + 1] - '0';
				i++;
			}
			for (j = 0; j < n; j++) {
				newstr[newiter] = 'A' + num - 1;
				newiter++;
			}
		}
		else {
			newstr[newiter] = ' ';
			newiter++;
		}
	}
	newstr[newiter] = NULL;
	printf("%s", newstr);
}