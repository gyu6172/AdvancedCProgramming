#include <stdio.h>
#include <string.h>
struct time {
	int h,m,s;
};
int main() {
	struct time t1, t2, t3;
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	t3.h = t2.h - t1.h;
	if (t1.m > t2.m) {
		t3.h--;
		t3.m = t2.m - t1.m + 60;
	}
	else {
		t3.m = t2.m - t1.m;
	}
	if (t1.s > t2.s) {
		t3.m--;
		t3.s = t2.s - t1.s + 60;
	}
	else {
		t3.s = t2.s - t1.s;
	}
	printf("%d %d %d", t3.h, t3.m, t3.s);
}