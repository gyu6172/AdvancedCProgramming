#include <stdio.h>
int input(int *arr);
int *sel_next(int *arr, int m, int n);
int number(int *p, int *q);
int main() {
	int arr[100];

	int len = input(arr);
	int m;
	scanf("%d",&m);
	int *end = sel_next(arr, len, m);

	int rst = number(arr+m, end);

	printf("%d",rst);
}

int input(int* arr) {
	int cnt=0;
	int *p=arr;
	while (1) {
		int n;
		scanf("%d",&n);
		*p = n;
		p++;
		cnt++;
		if (n == -1) {
			break;
		}
	}
	return cnt;
}

int* sel_next(int* arr, int n, int m)
{
	int *p;
	for (p = arr + m; p < arr + n; p++) {
		if (*p > *(p + 1) || *(p+1)==-1) {
			break;
		}
	}
	return p;
}

int number(int* s, int* e) {
	int* p;
	int num=0;
	for (p = s; p <= e; p++) {
		num = num*10;
		num += *p;
	}
	return num;
}
