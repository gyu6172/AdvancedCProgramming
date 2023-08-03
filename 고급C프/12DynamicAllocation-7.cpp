#include <stdio.h>
#include <stdlib.h>
int main() {
	int x, y, i, j;
	scanf("%d %d", &x, &y);
	int** p = (int**)malloc(sizeof(int*) * y);
	for (i = 0; i < y; i++) {
		p[i] = (int*)malloc(sizeof(int*) * x);
	}
	char a = 'a';
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			p[i][j] = a;
			if (a == 'z') {
				a = 'A' - 1;
			}
			else if (a == 'Z') {
				a = 'a' - 1;
			}
			a++;
		}
	}
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < y; i++) {
		free(p[i]);
	}
	free(p);
}