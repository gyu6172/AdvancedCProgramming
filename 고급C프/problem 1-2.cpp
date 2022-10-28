#include <stdio.h>
#include <string.h>
typedef struct belong {
	char name[46];
	int min,max,stuCnt;
	double avgSum;
	double topGrade;
	char topStuName[31];
}Belong;
typedef struct student {
	char name[31];
	int id;
	double grade;
}Student;
int main() {
	Belong belongs[10];
	Student stus[100];
	int n,m,i,j;
	scanf("%d",&n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s %d %d", &belongs[i].name, &belongs[i].min, &belongs[i].max);
		belongs[i].stuCnt=0;
		belongs[i].avgSum=0;
		belongs[i].topGrade=0;
		getchar();
	}
	scanf("%d", &m);
	getchar();
	for (i = 0; i < m; i++) {
		scanf("%s %d %lf", &stus[i].name, &stus[i].id, &stus[i].grade);

		getchar();
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (belongs[i].min <= (stus[j].id) % 10000 && (stus[j].id) % 10000 <= belongs[i].max) {
				belongs[i].stuCnt++;
				belongs[i].avgSum += stus[j].grade;
				if (belongs[i].topGrade < stus[j].grade) {
					belongs[i].topGrade = stus[j].grade;
					strcpy(belongs[i].topStuName, stus[j].name);
				}
				else if (belongs[i].topGrade == stus[j].grade) {
					if (strcmp(belongs[i].topStuName, stus[j].name) > 0) {
						belongs[i].topGrade = stus[j].grade;
						strcpy(belongs[i].topStuName, stus[j].name);
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (belongs[i].avgSum / belongs[i].stuCnt < belongs[j].avgSum / belongs[j].stuCnt) {
				Belong tmp = belongs[i];
				belongs[i] = belongs[j];
				belongs[j] = tmp;
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		printf("%s %.2f %d %s\n",belongs[i].name, (belongs[i].avgSum)/belongs[i].stuCnt, belongs[i].stuCnt, belongs[i].topStuName);
	}





}