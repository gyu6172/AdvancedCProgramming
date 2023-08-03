#include <stdio.h>
//	7
//	2022010 97 82
//	2022011 30 35
//	2022012 92 90
//	2022013 74 85
//	2022014 71 87
//	2022015 73 98
//	2022016 12 90
typedef struct student {
	char id[8];
	int t1, t2;
	double avg;
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
		scanf("%s %d %d", &stus[i].id, &stus[i].t1, &stus[i].t2);
		stus[i].avg = (stus[i].t1 * 0.4) + (stus[i].t2 * 0.6);
		getchar();
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].avg < stus[j].avg) {
				swap(&stus[i], &stus[j]);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].avg == stus[j].avg) {
				if (stus[i].t2 < stus[j].t2) {
					swap(&stus[i], &stus[j]);
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		stus[i].soonwee = (i + 1);
		if (stus[i].avg == stus[i + 1].avg) {
			stus[i + 1].soonwee = i + 1;
		}
	}
	for (i = 1; i < n; i++) {
		if (stus[i].avg == stus[i - 1].avg) {
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
		else if (stus[i].t2 >= 60) {
			stus[i].grade = 'B';
		}
		else {
			stus[i].grade = 'F';
		}
	}
	for (i = 1; i < n; i++) {
		if (stus[i].soonwee == stus[i - 1].soonwee) {
			stus[i].soonwee = stus[i - 1].soonwee;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s %d %d %.1f %d %c\n", stus[i].id, stus[i].t1, stus[i].t2, stus[i].avg, stus[i].soonwee, stus[i].grade);
	}

}

void swap(struct student* p, struct student* q)
{
	Student tmp = *p;
	*p = *q;
	*q = tmp;
}
