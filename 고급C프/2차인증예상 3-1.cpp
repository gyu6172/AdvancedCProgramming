#include <stdio.h>
#include <string.h>
typedef struct {
	char name[11];
	int write;
	int interview;
	double total;
}Person;
void swap(Person *p, Person *q);
int main() {
	int n,m;
	scanf("%d %d", &n, &m);

	Person persons[100];

	int i,j;
	for (i = 0; i < n; i++) {
		scanf("%s %d %d", persons[i].name, &(persons[i].write), &(persons[i].interview));
		persons[i].total = (persons[i].write * 8) + (persons[i].interview * 2);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (persons[j].total < persons[j + 1].total) {
				swap(&persons[j], &persons[j+1]);
			}
		}
	}

	for (i = 0; i < m; i++) {
		printf("%s %.1f\n", persons[i].name, persons[i].total/10);
	}




}

void swap(Person* p, Person* q)
{
	Person r = *p;
	*p = *q;
	*q = r;
}
