#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
	int id;
	int t1;
	int t2;
	double total;
}St;
int main() {
	int n;
	scanf("%d",&n);
	int i,j;


	Student *stus = (St*)malloc(sizeof(St)*n);

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%d %d %d",&(stus[i].id), &(stus[i].t1), &(stus[i].t2));
		stus[i].total = (stus[i].t1 * 4) + (stus[i].t2 * 6);
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].total < stus[j].total) {
				St tmp = stus[i];
				stus[i] = stus[j];
				stus[j] = tmp;
			}
		}
	}
	int m = n*0.7;
	for (i = m; i < n; i++) {
		if (stus[i].total == stus[i + 1].total) {
			m++;
		}
		else {
			break;
		}
	}

	for (i = 0; i < m; i++) {
		printf("%d %.1f\n",stus[i].id, stus[i].total/10);
	}

}