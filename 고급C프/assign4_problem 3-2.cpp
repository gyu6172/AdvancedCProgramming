#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//과목 구조체 선언
typedef struct subject {
	char *name;		//과목의 이름
	double score;	//그 과목의 점수
}Subject;
//학생 구조체 선언
typedef struct student {
	char *name;		//학생의 이름
	char id[5];		//학생의 학번
	int numSubject;	//과목의 개수
	Subject *pSub;	//과목들
	double avg;		//과목 점수의 평균
}Student;
int main() {
	//n입력받음
	int n;
	scanf("%d", &n);

	//학생 구조체 배열 동적할당
	Student* stus = (Student*)malloc(sizeof(Student) * n);

	//반복문 순회용 변수
	int i, j;
	//n명의 학생의 정보를 입력받음
	for (i = 0; i < n; i++) {
		//이름과 학번 저장용 변수 선언
		char name[101], id[5];
		//과목 이름 저장용 변수 선언
		char subjectStr[101];
		//이름과 학번 입력받음
		scanf("%s %s ",name,id);
		//과목 이름을 입력받음
		gets_s(subjectStr);
		//과목의 개수 저장할 변수
		int subjectCnt = 0;
		for (j = 0; j <= strlen(subjectStr); j++) {
			//과목문자열을 쭉 순회하면서 공백이나 널문자를 만나면 변수의 값을 1 증가시킴
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				subjectCnt++;
			}
		}
		//과목 문자열 중 절반은 과목이름, 절반은 그 과목의 점수이다.
		subjectCnt /= 2;
		//학생의 이름을 동적할당 받음
		stus[i].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
		//메모리 공간에 저장.
		strcpy(stus[i].name, name);
		//학번 저장
		strcpy(stus[i].id, id);
		//과목의 개수 저장
		stus[i].numSubject = subjectCnt;
		//학생이 수강한 과목 저장
		stus[i].pSub = (Subject*)malloc(sizeof(Subject) * subjectCnt);
		//과목 문자열을 단어별로 나눌 때 한 단어가 저장될 변수 tmp
		char tmp[101];
		//tmp의 크기
		int tmpIter = 0;
		//현재 단어가 과목명인지 점수인지 알려줄 변수
		int wordsCnt = 0;
		//과목 구조체 배열의 크기
		int pSubIter=0;
		//과목의 평균
		double avg = 0.0;
		//과목 문자열의 처음부터 끝까지 순회를 돔
		for (j = 0; j <= strlen(subjectStr); j++) {
			//만약 공백이나 널문자를 만난다면
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				//현재 단어에 마지막에 널문자 추가
				tmp[tmpIter++] = NULL;
				//만약 현재 단어가 과목 명이라면
				if (wordsCnt%2 == 0) {
					//과목 구조체 배열에 이름을 저장할 공간을 동적할당 받음.
					(stus[i].pSub)[pSubIter].name = (char*)malloc(sizeof(tmpIter));
					//그 공간에 과목이름 저장.
					strcpy((stus[i].pSub)[pSubIter].name, tmp);
				}
				//만약 현재 단어가 과목 점수라면
				else if (wordsCnt%2 == 1) {
					//과목의 점수를 실수형으로 변환해서 저장.
					(stus[i].pSub)[pSubIter++].score = atof(tmp);
					//평균값을 저장하는 변수에도 같은 값을 더해준다.(나중에 과목개수로 나눔)
					avg += atof(tmp);
				}
				//wordsCnt 1 증가
				wordsCnt++;
				//현재 단어의 개수 초기화
				tmpIter = 0;
			}
			//만약 공백이나 널문자가 아니라면
			else {
				//현재 단어에 문자 저장.
				tmp[tmpIter++] = subjectStr[j];
			}
		}
		//반복문 종료 후, 학생의 평균에 avg를 과목의 개수로 나눈 값을 저장.
		stus[i].avg = avg/stus[i].numSubject;
	}

	//학생을 평균이 높은 순서대로 정렬하는 코드
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//만약 i보다 j의 평균이 높다면
			if (stus[i].avg < stus[j].avg) {
				//두 구조체 멤버를 바꿔준다.(선택정렬)
				Student tmp = stus[i];
				stus[i] = stus[j];
				stus[j] = tmp;
			}
		}
	}
	//평균이 같은 학생은 학번순대로 정렬해야한다.
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//만약 평균이 같고,
			if (stus[i].avg == stus[j].avg) {
				//i의 학번보다 j의 학번이 빠르다면
				if (strcmp(stus[i].id, stus[j].id) > 0) {
					//둘이 스왑
					Student tmp = stus[i];
					stus[i] = stus[j];
					stus[j] = tmp;
				}
			}
		}
	}

	//k 입력받음
	int k;
	scanf("%d",&k);

	//k번째 학생을 저장함.
	Student kStudent = stus[k-1];

	//k번째 학생이 가장 잘 본 과목 이름을 저장할 변수와 그 과목의 점수를 저장할 변수
	char highSubName[101];
	double highSubScore=0.0;

	//그 학생의 본 과목을 쭉 체크함.
	for (i = 0; i < kStudent.numSubject; i++) {
		//만약 최댓값보다 높은 점수가 있다면
		if (kStudent.pSub[i].score > highSubScore) {
			//과목이름을 바꿔주고
			strcpy(highSubName, kStudent.pSub[i].name);
			//최대 점수도 바꿔준다.
			highSubScore = kStudent.pSub[i].score;
		}
	}
	//최종적으로 이름과 학번, 평균, 가장 잘 본 과목, 그 과목의 점수를 출력해준다.
	printf("%s %s %.2lf %s %.2lf",kStudent.name, kStudent.id, kStudent.avg, highSubName, highSubScore);

	//할당받은 메모리를 해제한다.
	for (i = 0; i < n; i++) {
		free(stus[i].pSub);
		free(stus[i].name);
	}
	//학생 구조체 배열 해제
	free(stus);

}