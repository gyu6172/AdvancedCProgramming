#include <stdio.h>
#include <string.h>
typedef struct Movie{
	char name[101];
	int year;
}Movie;
int main() {
	int n;
	scanf("%d",&n);
	int i,j;
	getchar();
	
	Movie movies[100];
	for (i = 0; i < n; i++) {
		scanf("%d", &(movies[i].year));
		getchar();
		gets_s(movies[i].name);
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (movies[i].year > movies[j].year) {
				Movie tmp = movies[i];
				movies[i] = movies[j];
				movies[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (movies[i].year == movies[j].year && (strcmp(movies[i].name, movies[j].name)>0)) {
				Movie tmp = movies[i];
				movies[i] = movies[j];
				movies[j] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d, %s\n",movies[i].year, movies[i].name);
	}
}