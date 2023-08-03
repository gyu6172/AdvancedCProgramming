#include <stdio.h>
struct number {
	int n;
	int order;
};
int main() {
    int i, j;
    struct number nums[10];
    for (i = 0; i < 10; i++) {
        scanf("%d", &nums[i].n);
    }
    for (i = 0; i < 10; i++) {
        int cnt = 1;
        for (j = 0; j < 10; j++) {
            if (nums[i].n < nums[j].n) {
                cnt++;
            }
        }
        nums[i].order = cnt;
    }
    int n1, n2;
    for (i = 0; i < 10; i++) {
        if (nums[i].order == 3)
            n1 = nums[i].n;
        else if (nums[i].order == 7)
            n2 = nums[i].n;
    }
    printf("%d %d", n1, n2);
}