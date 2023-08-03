#include <stdio.h>
int input(int *arr);
int* sel_next(int *pos);
int number(int *p1, int *p2);
int main() {
	int x[100], n;
	n = input(x);
	int *s=x, *e;
	while (1) {
		e = sel_next(s);
		printf("%d\n",number(s,e));
		s = e;
		if(s==x+n-2)
			break;
	}
}

int input(int* arr)
{
	int cnt=0;
	while (1) {
		scanf("%d",arr);
		cnt++;
		if(*arr==-1)
			break;
		arr++;
	}
	return cnt;
}

int* sel_next(int* pos)
{
	int *p,*q,chk;
	p = pos + 1;
	q = pos;
	if (*q < *p) {
		for (p = pos + 1, q = pos;; p++, q++) {
			if (*q > *p || *p==-1)
				return q;	
		}
	}
	else if (*q > *p) {
		for (p = pos + 1, q = pos;; p++, q++) {
			if (*q < *p || *p==-1)
				return q;
		}
	}
}

int number(int* p1, int* p2)
{
	int num=0;
	for (int* iter = p1; iter <= p2; iter++) {
		num = num*10 + *iter;	
	}

	return num;
}
