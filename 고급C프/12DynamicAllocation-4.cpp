#include <stdio.h>
#include <stdlib.h>
typedef struct student {
	char name[8];
	int kor, eng, math;
	double avg;
}Student;
int main() {
	int n, i;
	scanf("%d", &n);
	getchar();
	Student* stus = (Student*)malloc(sizeof(Student) * n);
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", &(stus + i)->name, &(stus + i)->kor, &(stus + i)->eng, &(stus + i)->math);
		(stus + i)->avg = ((stus[i].kor) + (stus[i].eng) + (stus[i].math)) / 3.0;
		getchar();
	}
	for (i = 0; i < n; i++) {
		printf("%s %.1f ", stus[i].name, stus[i].avg);
		if ((stus[i].kor >= 90) || (stus[i].eng >= 90) || (stus[i].math >= 90)) {
			printf("GREAT ");
		}
		if ((stus[i].kor < 70) || (stus[i].eng < 70) || (stus[i].math < 70)) {
			printf("BAD");
		}
		printf("\n");
	}
	free(stus);
}