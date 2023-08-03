#include <stdio.h>
struct student {
	char name[10];
	int score;
};
int main() {
	struct student stu[5];
	int i;
	int sum = 0;
	for (i = 0; i < 5; i++) {
		scanf("%s %d", &stu[i].name, &stu[i].score);
		sum += stu[i].score;
	}
	double avg = sum / 5.0;
	for (i = 0; i < 5; i++) {
		if (stu[i].score <= avg) {
			printf("%s\n", stu[i].name);
		}
	}
}