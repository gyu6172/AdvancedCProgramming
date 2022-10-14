#include <stdio.h>
void input(int *p, int m);
int* sel_max(int *p, int m);
void output(int* p, int n);

int main(void) {
	int in[100], out[100], * max, i, N, M;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}

void input(int* p, int m)
{
	for (int* iter = p; iter < p + m; iter++) {
		scanf("%d",iter);
	}
}

int* sel_max(int* p, int m)
{
	int *iter, *tmp;
	int *maxPos, maxCnt=0;
	for (iter = p; iter < p + m; iter++) {
		int cnt=0;
		for (tmp = p; tmp < p + m; tmp++) {
			if (*iter == *tmp) {
				cnt++;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
			maxPos = iter;
		}
	}
	return maxPos;
}

void output(int* p, int n)
{
	int *iter;
	for (iter = p; iter < p + n; iter++) {
		printf(" %d",*iter);
	}
}
