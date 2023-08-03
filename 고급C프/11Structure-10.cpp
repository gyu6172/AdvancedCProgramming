#include <stdio.h>
typedef struct date {
	int year;
	int month;
	int day;
}Date;
Date* select_min(Date* p1, Date* p2);
int main() {
	Date d1, d2, *rst;
	scanf("%d/%d/%d",&d1.year, &d1.month, &d1.day);
	getchar();
	scanf("%d/%d/%d", &d2.year, &d2.month, &d2.day);
	rst = select_min(&d1, &d2);
	printf("%d/%d/%d",rst->year, rst->month, rst->day);
}

Date* select_min(Date* p1, Date* p2)
{
	if (p1->year > p2->year) {
		return p2;
	}
	else if (p1->year < p2->year) {
		return p1;
	}
	else {
		if (p1->month > p2->month) {
			return p2;
		}
		else if (p1->month < p2->month) {
			return p1;
		}
		else {
			if (p1->day > p2->day) {
				return p2;
			}
			else if (p1->day < p2->day) {
				return p1;
			}
		}
	}
}
