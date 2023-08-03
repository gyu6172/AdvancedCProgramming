#include <stdio.h>
struct student {
	char name[20];
	int t1, t2, t3;
	double avg;
	char grade;
};
int main() {
	int n;
	scanf("%d", &n);
	int i;
	struct student stu[20];
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", &stu[i].name, &stu[i].t1, &stu[i].t2, &stu[i].t3);
		int sum = 0;
		sum += stu[i].t1 + stu[i].t2 + stu[i].t3;
		stu[i].avg = sum / 3.0;
		if (stu[i].avg >= 90)
			stu[i].grade = 'A';

		else if (stu[i].avg >= 80)
			stu[i].grade = 'B';
		else if (stu[i].avg >= 70)
			stu[i].grade = 'C';
		else
			stu[i].grade = 'F';
	}
	for (i = 0; i < n; i++) {
		printf("%s %.1f %c\n", stu[i].name, stu[i].avg, stu[i].grade);
}