#include <stdio.h>
//	7
//	2022010 60
//	2022011 30
//	2022012 90
//	2022013 70
//	2022014 70
//	2022015 60
//	2022016 20
typedef struct student {
	char id[8];
	int t;
	int soonwee;
	char grade;
}Student;
void swap(struct student* p, struct student* q);
int main() {
	int n;
	scanf("%d", &n);
	Student stus[20];
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%s %d", &stus[i].id, &stus[i].t);
		getchar();
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].t < stus[j].t) {
				swap(&stus[i], &stus[j]);
			}
		}
	}
	for (i = 0; i < n; i++) {
		stus[i].soonwee = (i + 1);
		if (stus[i].t == stus[i + 1].t) {
			stus[i + 1].soonwee = i + 1;
		}
	}
	for (i = 1; i < n; i++) {
		if (stus[i].t == stus[i - 1].t) {
			stus[i].soonwee = stus[i - 1].soonwee;
		}
	}

	for (i = 0; i < n; i++) {
		if (stus[i].soonwee < 0.3 * n) {
			stus[i].grade = 'A';
		}
		else if (stus[i].soonwee < 0.7 * n) {
			stus[i].grade = 'B';
		}
		else {
			stus[i].grade = 'F';
		}
	}
	for (i = 1; i < n; i++) {
		if (stus[i].t == stus[i - 1].t) {
			stus[i].grade = stus[i - 1].grade;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s %d %d %c\n", stus[i].id, stus[i].t, stus[i].soonwee, stus[i].grade);
	}

}

void swap(struct student* p, struct student* q)
{
	Student tmp = *p;
	*p = *q;
	*q = tmp;
}
