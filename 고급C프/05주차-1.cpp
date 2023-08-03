#include <stdio.h>
#include <string.h>
typedef struct student {
	char name[10];
	char id[11];
	char grade;
}Student;
int main() {
	Student stu[5];
	int i, j;
	for (i = 0; i < 5; i++) {
		scanf("%s %s %c", &stu[i].name, &stu[i].id, &stu[i].grade);
		getchar();
	}

	char name[10];
	scanf("%s", name);

	for (i = 0; i < 5; i++) {
		if (!strcmp(name, stu[i].name)) {
			printf(" %s %c\n", stu[i].id, stu[i].grade);
		}
	}
}