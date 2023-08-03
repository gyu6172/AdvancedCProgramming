#include <stdio.h>
struct student {
	int gender;
	int weight;
	int height;
};
int main() {
	int n;
	scanf("%d", &n);
	struct student stu[10];
	int i;
	int g1 = 0, g2 = 0, g3 = 0;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &stu[i].gender, &stu[i].weight, &stu[i].height);
	}
	for (i = 0; i < n; i++) {
		if (stu[i].gender == 1) {
			if (stu[i].weight < 60) {
				if (stu[i].height < 165) {
					g1++;
				}
				else if (stu[i].height < 175) {
					g2++;
				}
				else {
					g3++;
				}
			}
			else if (stu[i].weight < 70) {
				if (stu[i].height < 165) {
					g3++;
				}
				else if (stu[i].height < 175) {
					g1++;
				}
				else {
					g2++;
				}
			}
			else {
				if (stu[i].height < 165) {
					g2++;
				}
				else if (stu[i].height < 175) {
					g3++;
				}
				else {
					g1++;
				}
			}
		}
		else if (stu[i].gender == 2) {
			if (stu[i].weight < 50) {
				if (stu[i].height < 165) {
					g1++;
				}
				else if (stu[i].height < 175) {
					g2++;
				}
				else {
					g3++;
				}
			}
			else if (stu[i].weight < 60) {
				if (stu[i].height < 165) {
					g3++;
				}
				else if (stu[i].height < 175) {
					g1++;
				}
				else {
					g2++;
				}
			}
			else {
				if (stu[i].height < 165) {
					g2++;
				}
				else if (stu[i].height < 175) {
					g3++;
				}
				else {
					g1++;
				}
			}
		}
	}
	printf("%d %d %d", g1, g2, g3);
}