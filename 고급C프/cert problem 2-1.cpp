#include <stdio.h>
#include <string.h>
typedef struct {
	char name[10];
	char id[11];
	char grade;
}Student;
int main() {
	Student stus[5];
	int i,j;
	for (i = 0; i < 5; i++) {
		scanf("%s %s %c",stus[i].name, stus[i].id, &(stus[i].grade));
		getchar();
	}

	char name[10];
	scanf("%s",name);

	for (i = 0; i < 5; i++) {
		if (strcmp(name, stus[i].name) == 0) {
			printf(" %s %c", stus[i].id, stus[i].grade);
			break;
		}
	}

}