#include <stdio.h>
#include <string.h>
int main() {
	int n;
	scanf("%d", &n);

	char str[80];
		
	int i,j;
	for (i = 0; i < n; i++) {
		scanf("%s",str);
		int score=0;
		int cnt=0;
		for (j = 0; j <= strlen(str); j++) {
			if (str[j] == 'O') {
				cnt++;
			}
			else if (str[j] == 'X' || str[j]==NULL) {
				score+=(cnt*(cnt+1))/2;
				cnt=0;
			}
		}
		printf("%d\n",score);

	}
}