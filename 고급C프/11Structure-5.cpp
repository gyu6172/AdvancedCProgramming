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
	struct student students[50], * stu = students;
	for (; stu < students + n; stu++) {
		scanf("%s %d %d %d", &stu->name, &stu->t1, &stu->t2, &stu->t3);
		int sum = 0;
		sum += stu->t1 + stu->t2 + stu->t3;
		stu->avg = sum / 3.0;
		if (stu->avg >= 90)
			stu->grade = 'A';
		else if (stu->avg >= 80)
			stu->grade = 'B';
		else if (stu->avg >= 70)
			stu->grade = 'C';
		else
			stu->grade = 'D';
	}
	for (stu = students; stu < students + n; stu++) {
		printf("%s %.1f %c\n", stu->name, stu->avg, stu->grade);
	}
}