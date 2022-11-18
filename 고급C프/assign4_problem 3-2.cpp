#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct subject {
	char *name;
	double score;
}Subject;
typedef struct student {
	char *name;
	char id[5];
	int numSubject;
	Subject *pSub;
	double avg;
}Student;
int main() {


	int n;
	scanf("%d", &n);

	Student* stus = (Student*)malloc(sizeof(Student) * n);

	int i, j;
	for (i = 0; i < n; i++) {
		char name[101], id[5];
		char subjectStr[101];
		scanf("%s %s ",name,id);
		gets_s(subjectStr);
		int subjectCnt = 0;
		for (j = 0; j <= strlen(subjectStr); j++) {
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				subjectCnt++;
			}
		}
		subjectCnt /= 2;
		stus[i].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
		strcpy(stus[i].name, name);
		strcpy(stus[i].id, id);
		stus[i].numSubject = subjectCnt;
		stus[i].pSub = (Subject*)malloc(sizeof(Subject) * subjectCnt);
		char tmp[101];
		int tmpIter = 0;
		int wordsCnt = 0;
		int pSubIter=0;
		double avg = 0.0;
		for (j = 0; j <= strlen(subjectStr); j++) {
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				tmp[tmpIter++] = NULL;
				if (wordsCnt%2 == 0) {
					(stus[i].pSub)[pSubIter].name = (char*)malloc(sizeof(tmpIter));
					strcpy((stus[i].pSub)[pSubIter].name, tmp);
				}
				else if (wordsCnt%2 == 1) {
					(stus[i].pSub)[pSubIter++].score = atof(tmp);
					avg += atof(tmp);
				}
				wordsCnt++;
				tmpIter = 0;
			}
			else {
				tmp[tmpIter++] = subjectStr[j];
			}
		}
		stus[i].avg = avg/stus[i].numSubject;
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].avg < stus[j].avg) {
				Student tmp = stus[i];
				stus[i] = stus[j];
				stus[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (stus[i].avg == stus[j].avg) {
				if (strcmp(stus[i].id, stus[j].id) > 0) {
					Student tmp = stus[i];
					stus[i] = stus[j];
					stus[j] = tmp;
				}
			}
		}
	}

	int k;
	scanf("%d",&k);

	Student kStudent = stus[k-1];
	char highSubName[101];
	double highSubScore=0.0;

	for (i = 0; i < kStudent.numSubject; i++) {
		if (kStudent.pSub[i].score > highSubScore) {
			strcpy(highSubName, kStudent.pSub[i].name);
			highSubScore = kStudent.pSub[i].score;
		}
	}
	printf("%s %s %.2lf %s %.2lf",kStudent.name, kStudent.id, kStudent.avg, highSubName, highSubScore);

	for (i = 0; i < n; i++) {
		free(stus[i].pSub);
		free(stus[i].name);
	}
	free(stus);

}