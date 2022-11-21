#include <stdio.h>
int input(int* arr);
int* sel_next(int* p);
int number(int* p, int* q);
int main() {
	int arr[100];

	int len = input(arr);

	int *s , *e=arr;
	int chk=0;
	while (1) {
		s = e;
		e = sel_next(s);
		printf("%d\n", number(s,e));
		if (*(e+1)==-1) {
			break;
		}
	}
}

int input(int* arr) {
	int cnt = 0;
	int* p = arr;
	while (1) {
		int n;
		scanf("%d", &n);
		*p = n;
		p++;
		cnt++;
		if (n == -1) {
			break;
		}
	}
	return cnt;
}

int* sel_next(int* p)
{
	int increase = (*p < *(p+1))? 1 : 0;
	int *iter = p;
	if (increase) {
		while (1) {
			if (*iter > *(iter + 1) || *(iter+1)==-1) {
				break;
			}
			iter++;
		}
	}
	else {
		while (1) {
			if (*iter < *(iter + 1) || *(iter + 1) == -1) {
				break;
			}
			iter++;
		}
	}
	return iter;
}

int number(int* s, int* e) {
	int* p;
	int num = 0;
	for (p = s; p <= e; p++) {
		num = num * 10;
		num += *p;
	}
	return num;
}
