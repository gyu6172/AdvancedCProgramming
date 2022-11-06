#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_c(char* p, int m);
int main() {
	char strArr[10][101];
	int arrIter=0;
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	getchar();
	for (i = 0; i < n; i++) {
		char str[101];
		gets_s(str);
		strcpy(strArr[arrIter++], str);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (count_c(strArr[j],m) < count_c(strArr[j+1],m)) {
				char s[101];
				strcpy(s, strArr[j]);
				strcpy(strArr[j], strArr[j+1]);
				strcpy(strArr[j+1], s);
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (count_c(strArr[i], m) == 0) {
			continue;
		}
		printf("%s\n",strArr[i]);
	}

}

int count_c(char* p, int m)
{
	int len = strlen(p);
	if (m > len) {
		m = len;
	}
	char* iter;
	int i,j;
	int cnt=0;
	for (i = 0; i < m; i++) {
		if ('a' <= p[i] && p[i] <= 'z') {
			cnt++;
		}
		else if ('A' <= p[i] && p[i] <= 'Z') {
			cnt++;
		}
		else if(p[i] == ' ')
			cnt++;
	}

	return m-cnt;
}
