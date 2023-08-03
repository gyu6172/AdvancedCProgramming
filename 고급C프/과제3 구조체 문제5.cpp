#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//학생 구조체 선언
typedef struct stu {
	//이름, 학번, 과목의 개수, 과목이름, 취득학점
	char name[31];
	int id;
	int gradeCnt;
	char grade[10][31];
	double point;
}Student;
//구조체 배열 선언
Student students[100];
//학생 수를 담은 전역변수 선언
int studentCnt = 0;
//입력 함수
void inputStudent();
//정렬 함수
void sortStudent(Student arr[], int cnt);
//삭제 함수
void deleteStudent();
//출력 함수
void printStudent(Student arr[], int cnt);
int main() {
	while (1) {
		//명령어 입력받음
		char code;
		scanf("%c", &code);
		//개행문자 제거
		getchar();
		//학생정보 입력
		if (code == 'I') {
			inputStudent();
		}
		//학생 이름순으로 정렬 후 출력
		else if (code == 'S') {
			sortStudent(students, studentCnt);
		}
		//학생정보 삭제
		else if (code == 'D') {
			deleteStudent();
		}
		//남아있는 모든 학생 정보 출력
		else if (code == 'P') {
			printStudent(students, studentCnt);
		}
		//프로그램 종료
		else if (code == 'Q') {
			break;
		}
	}
}

//입력 함수
void inputStudent()
{
	//학생 구조체변수 선언
	Student tmp;
	//취득 학점 0으로 초기화
	tmp.point = 0;
	//이름, 학번, 과목 수 입력받음
	scanf("%s %d %d", &tmp.name, &tmp.id, &tmp.gradeCnt);
	//과목 수 만큼 반복해서 과목이름과 그 과목의 학점 입력받음
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf", &tmp.grade[i], &p);
		//과목의 학점을 총 학점에 더해준다.
		tmp.point += p;
	}
	//개행문자 제거
	getchar();
	//구조체 배열에 구조체변수 추가
	students[studentCnt] = tmp;
	//학생 수 1증가시킴.
	studentCnt++;
}

//정렬 함수
void sortStudent(Student arr[], int cnt)
{
	//원래 함수는 그대로 두어야 하므로 새로운 구조체 배열을 하나 선언해서 이 배열에 값들을 복사한 다음 정렬하여 출력함.
	Student newArr[100];
	int i, j;
	//새로운 배열에 구조체 복사
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	//새로운 배열을 이름 순으로 정렬해준다.
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			//만약 이름이 사전 순으로 앞이라면
			if (strcmp(newArr[i].name, newArr[j].name) > 0) {
				//구조체 멤버를 바꿔준다.
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	//출력함수 불러와서 새로운 배열 출력
	printStudent(newArr, cnt);
}

//학생 삭제 함수
void deleteStudent()
{
	//삭제하고자 하는 이름을 입력받을 변수
	char findName[31];
	//이름 입력받고 개행문자 제거
	scanf("%s", &findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		//배열 순회 하면서 입력 받은 이름을 찾은 경우
		if (strcmp(students[i].name, findName) == 0) {
			//찾은 위치부터 배열의 끝까지 한 칸씩 앞으로 당김.
			for (int j = i; j < studentCnt - 1; j++) {
				students[j] = students[j + 1];
			}
			//학생 수 1 감소시킴.
			studentCnt--;
		}
	}
}

//출력 함수
void printStudent(Student arr[], int cnt)
{
	//구조체 배열을 순회하며 이름, 학번, 과목수, 전체 평점 출력해줌.
	for (int i = 0; i < cnt; i++) {
		printf("%s %d %d %.2f\n", arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point / arr[i].gradeCnt);
	}
}