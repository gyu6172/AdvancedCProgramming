#include <stdio.h>
#include <string.h>
void StringAdd(char arr[], char ch, int index);
int Convertor(char a);
int main() {
	char str[16];
	gets_s(str);
	int n = strlen(str), i;
	for (i = 0; i < n-1; i++) {
		if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1) {
			StringAdd(str,'+',i+1);
			i++;
			n++;
		}
		else if (str[i] % 2 == 0 && str[i + 1] % 2 == 0) {
			StringAdd(str, '*', i + 1);
			i++;
			n++;
		}
	}
	str[n]=NULL;
	printf("%s",str);
}

void StringAdd(char arr[], char ch, int index)
{
	int n=strlen(arr),i,j;
	for (i = 0; i < n; i++) {
		if (i == index) {
			for (j = n; j >= i; j--) {
				arr[j+1] = arr[j];
			}
			arr[i] = ch;
			n++;
		}
	}
}

int Convertor(char a)
{
	return a-'0';
}
