#include <stdio.h>
int main() {
	FILE *fp;
	fp = fopen("test1.txt","r");
	if(fp==NULL)return -1;
	char str[10];
	char* s = fgets(str, 10, fp);
	fclose(fp);

	char rst[10];
	int i;
	for (i = 0; i < 9; i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			rst[i] = s[i]-32;
		}
		else if ('A' <= s[i] && s[i] <= 'Z') {
			rst[i] = s[i] + 32;
		}
	}
	rst[i]=NULL;
	fp = fopen("test2.txt", "w");
	if(fp==NULL)return -1;
	fputs(rst, fp);
	fclose(fp);


	
	
}