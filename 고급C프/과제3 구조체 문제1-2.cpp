#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//학생 구조체 선언
typedef struct student {
	//이름
	char name[10];
	//학번
	char id[11];
	//성적
	char grade;
}Student;
int main() {
	//구조체 배열 선언
	Student stus[5];
	//반복문 순회용 변수
	int i, j;
	//5명의 학생에 대한 정보를 입력받아야하므로 5번 반복
	for (i = 0; i < 5; i++) {
		//이름, 학번, 성적 입력
		scanf("%s %s %c", &stus[i].name, &stus[i].id, &stus[i].grade);
		//버퍼에 남아있는 개행문자 제거
		getchar();
	}
	//찾고자 하는 학생의 이름, 그 학생의 성적, 그 학생의 입학년도
	char findName[10], findGrade, findYear[5];
	//이름 입력
	scanf("%s", &findName);
	for (i = 0; i < 5; i++) {
		//만약 입력받은 이름과 같은 이름인 학생이 구조체 배열에 존재한다면
		if (strcmp(findName, stus[i].name) == 0) {
			//그 학생의 성적과 입학년도에 값을 저장함.
			findGrade = stus[i].grade;
			strncpy(findYear, stus[i].id, 4);
		}
	}
	findYear[4] = NULL;

	//조건에 맞는 학생이 있는지 없는지 나타낼 변수
	int chk = 0;
	for (i = 0; i < 5; i++) {
		char strYear[5];
		strncpy(strYear, stus[i].id, 4);
		strYear[4] = NULL;
		//만약 입력받은 학생의 성적과 같은 성적을 가진 학생을 찾는다면
		if (findGrade == stus[i].grade) {
			//입력받은 학생이 아니고, 입학년도가 같다면
			if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear) == 0)) {
				//chk값을 바꿔주고 이름을 출력해준다.
				chk = 1;
				printf("%s ", stus[i].name);
			}
		}
	}
	//만약 chk값이 바뀌지 않았다면 0을 출력
	if (!chk)
		printf("0\n");
	printf("\n");
	//찾고자 하는 학생의 입학년도와 입학년도를 131로 나눈 나머지 출력
	int num = atoi(findYear) % 131;
	printf("%s %d", findYear, num);
}