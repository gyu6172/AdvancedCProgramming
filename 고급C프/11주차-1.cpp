#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string {
	char *str;
	int words;
}String;
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	String* strs = (String*)malloc(sizeof(String)*n);
	if(strs==NULL)
		return -1;

	int i,j;
	for (i = 0; i < n; i++) {
		char tmp[101];
		gets_s(tmp);
		strs[i].str = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
		if(strs[i].str == NULL)
			return -1;
		strcpy(strs[i].str, tmp);
	}
	for (i = 0; i < n; i++) {
		int blankCnt=0;
		for (j = 0; j < strlen(strs[i].str); j++) {
			if (strs[i].str[j] == ' ') {
				blankCnt++;
			}
		}
		strs[i].words = blankCnt+1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strs[j].words < strs[j+1].words) {
				String tmpString = strs[j];
				strs[j] = strs[j+1];
				strs[j+1] = tmpString;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s %d\n",strs[i].str, strs[i].words);
	}

	for (i = 0; i < n; i++) {
		free(strs[i].str);
	}
	free(strs);
}