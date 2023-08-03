#include <stdio.h>
#include <string.h>
struct student {
	char belong[51];
	char id[10];
};
int main() {
	struct student stu[100];
	int n;
	scanf("%d", &n);
	int i, j;
	getchar();
	for (i = 0; i < n; i++) {
		gets_s(stu[i].belong);
		gets_s(stu[i].id);
	}
	//for (i = 0; i < n; i++) {
	//	printf("%s %d\n", stu[i].belong, stu[i].id);
	//}
	//printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (strcmp(stu[i].belong, stu[j].belong) == 1) {
				struct student tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
	i = 0;
	j = 0;
	for (i = 0; i < n; i++) {
		for (j = i; strcmp(stu[i].belong, stu[j].belong) == 0; j++) {
			if (strcmp(stu[j].belong, stu[j + 1].belong) == 0 && strcmp(stu[j].id, stu[j + 1].id) > 0) {
				struct student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}

		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %s\n", stu[i].belong, stu[i].id);
	}
}