#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct reserve {
	int id;
	char grade[4];
	int price;
}Reserve;
void input(Reserve *p, int n);
int cal_sum(Reserve* p, int n, int id);
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	Reserve *customers = (Reserve*)malloc(sizeof(Reserve)*n);
	input(customers, n);

	int i,j;

	int id;
	scanf("%d",&id);
	int total=cal_sum(customers, n, id);

	for (i = 0; i < n; i++) {
		if (customers[i].id == id) {
			printf("%s %d\n", customers[i].grade, customers[i].price);
		}
	}
	printf("%d",total);

}

void input(Reserve* p, int n)
{
	Reserve *iter;
	for (iter = p; iter < p + n; iter++) {
		scanf("%d %s",&(iter->id), &(iter->grade));
		getchar();
		if (strcmp(iter->grade, "VIP") == 0) {
			iter->price = 140000;
		}
		else if (strcmp(iter->grade, "R") == 0) {
			iter->price = 110000;
		}
		else if (strcmp(iter->grade, "S") == 0) {
			iter->price = 85000;
		}
		else if (strcmp(iter->grade, "A") == 0) {
			iter->price = 55000;
		}
	}
}

int cal_sum(Reserve* p, int n, int id)
{
	Reserve* iter;
	int total=0;
	for (iter = p; iter < p + n; iter++) {
		if (iter->id == id) {
			total += iter->price;
		}
	}
	return total;
}
