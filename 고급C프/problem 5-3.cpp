#include <stdio.h>
#include <string.h>
struct person {
	char name[11];
	int birthday;
	int year,month,day;
	int write;
	int interview;
	double total;
};
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
		applicants[i].birthday = (applicants[i].year*10000)+(applicants[i].month*100)+(applicants[i].day);
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
		for (j = i; j < n; j++) {
			if (applicants[i].total == applicants[j].total) {
				if (applicants[i].write < applicants[j].write) {
					swap(&applicants[i], &applicants[j]);
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (applicants[i].total == applicants[j].total) {
				if (applicants[i].write == applicants[j].write) {
					if (applicants[i].birthday < applicants[j].birthday) {
						swap(&applicants[i], &applicants[j]);
					}
				}
			}
		}
	}
	for (i = 0; i < m; i++) {
		printf("%s %.1f\n",applicants[i].name, applicants[i].total);
	}
}

void swap(struct person* p, struct person* q)
{
	struct person tmp=*p;
	*p = *q;
	*q = tmp;
}
