#include <stdio.h>
typedef struct student {
	char name[10];
	int s1,s2,s3;
	double avg;
}Student;
void read_data(Student* stus);
void cal_avg(Student* stus);
void sort(Student* stus);
void print_score(Student* stus);
int main() {
	Student stus[10];
	read_data(stus);
	cal_avg(stus);
	sort(stus);
	print_score(stus);
	
}

void read_data(Student* stus)
{
	Student* p;
	for (p = stus; p < stus + 10; p++) {
		scanf("%s %d %d %d",&p->name, &p->s1, &p->s2, &p->s3);
		getchar();
	}
}

void cal_avg(Student* stus)
{
	Student* p;
	for (p = stus; p < stus + 10; p++) {
		p->avg = (p->s1 + p->s2 + p->s3)/3.0;
	}
}

void sort(Student* stus)
{
	Student* p, *q;
	for (p = stus; p < stus + 10; p++) {
		for (q = p; q < stus + 10; q++) {
			if (p->avg < q->avg) {
				Student tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
}

void print_score(Student* stus)
{
	Student* p;
	Student *maxP, *minP; 
	double max=0,min=100;
	for (p = stus; p < stus + 10; p++) {
		if (max < p->avg) {
			max = p->avg;
			maxP = p;
		}
		if (min > p->avg) {
			min = p->avg;
			minP = p;
		}
	}
	printf("%s %.2f\n",maxP->name, maxP->avg);
	printf("%s %.2f\n", minP->name, minP->avg);
	for (p = stus + 7; p < stus + 10; p++) {
		printf("%s %.2f\n", p->name, p->avg);
	}
}
