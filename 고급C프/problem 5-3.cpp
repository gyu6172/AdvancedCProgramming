#include <stdio.h>
typedef struct person {
	char name[11];
	char birthday[11];
	int year,month,day;
	int write;
	int interview;
	double total;
}Person;
void swap(struct person *p, struct person *q);

int main() {
	int n,m,i,j;
	struct person applicants[100];
	scanf("%d %d",&n,&m);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s %d-%d-%d %d %d",&applicants[i].name, &applicants[i].year, &applicants[i].month, &applicants[i].day
		,&applicants[i].write, &applicants[i].interview);
		applicants[i].total = (0.8*applicants[i].write)+(0.2*applicants[i].interview);
		getchar();
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (applicants[i].total < applicants[j].total) {
				swap(&applicants[i], &applicants[j]);
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %.1f\n",applicants[i].name, applicants->total);
	}
}

void swap(person* p, person* q)
{
	struct person tmp=*p;
	*p = *q;
	*q = tmp;
}
