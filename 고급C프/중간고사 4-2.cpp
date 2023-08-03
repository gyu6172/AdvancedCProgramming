#include <stdio.h>
//1 3 5 2 4 6 7 -1 -3 9 8 10 11 13 15 -7 17 19 21 -9 0
int input(int* p);
int sel_max(int* p, int n);
void out_max(int* p, int* q);
int main() {
	int arr[100];
	int n = input(arr);
	int i, j;
	int maxLen = sel_max(arr, n);
	printf("\n");
	printf("%d", maxLen);
}

int input(int* p)
{
	int cnt = 0;
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else if (n > 0) {
			*p = n;
			p++;
			cnt++;
		}
	}
	return cnt;
}

int sel_max(int* p, int n)
{
	int* iter;
	int* s, * e;
	int lenCnt = 0;
	int maxLen = 0;
	for (iter = p; iter < p + n; iter++) {
		if ((*iter) % 2 == 0) {
			if (*(iter - 1) % 2 == 1) {
				printf("%d ", lenCnt);
			}
			if (maxLen < lenCnt) {
				maxLen = lenCnt;
				e = iter - 1;
				s = e - lenCnt + 1;
			}
			lenCnt = 0;
		}
		else {
			lenCnt++;
		}
	}
	if (*(iter - 1) % 2 == 1) {
		printf("%d ", lenCnt);
	}
	if (maxLen < lenCnt) {
		maxLen = lenCnt;
		e = iter - 1;
		s = e - lenCnt + 1;
	}
	lenCnt = 0;
	printf("\n");
	out_max(s, e);
	return maxLen;
}

void out_max(int* p, int* q)
{
	int* it;
	for (it = p; it <= q; it++) {
		printf("%d ", *it);
	}
}
