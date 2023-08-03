#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//학생 구조체 선언
typedef struct student {
	//이름
	char name[21];
	//국어 점수
	int kor;
	//영어 점수
	int eng;
	//수학 점수
	int math;
	//평균
	double avg;
}Student;
//함수 선언
void read_data(Student* pSt, int n);
void sort_score(Student* pSt, int n);
Student* select_out(Student* p, Student* q, int n);
int main() {
	//학생 수 입력
	int n;
	scanf("%d", &n);
	//구조체 배열 두 개와 각각의 구조체 포인터 변수 두개, 최종 출력할 포인터 변수 선언
	Student st1[49], st2[49], * pSt, * qSt, * finalSt;
	//pSt는 st1를, qSt는 st2를 가리키게 함
	pSt = st1;
	qSt = st2;
	//두 개의 구조체 입력받음
	read_data(pSt, n);
	read_data(qSt, n);
	//두 구조체 정렬
	sort_score(pSt, n);
	sort_score(qSt, n);
	//두 구조체 중에서 조건에 맞는 구조체포인터를 반환하여 finalSt에 저장
	finalSt = select_out(pSt, qSt, n);
	//finalSt를 순회하며 출력한다.
	for (Student* iter = finalSt; iter < finalSt + n; iter++) {
		printf("%s %d %d %d %.1f\n", iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	}
}
//입력 함수
void read_data(Student* pSt, int n)
{
	//반복문 순회용	구조체 포인터 변수
	Student* iter;
	for (iter = pSt; iter < pSt + n; iter++) {
		//n번 반복하며 입력받음
		scanf("%s %d %d %d", &iter->name, &iter->kor, &iter->eng, &iter->math);
		getchar();
		//평균값 초기화해줌.
		iter->avg = ((iter->kor) + (iter->eng) + (iter->math)) / 3.0;
	}
}

//정렬 함수
void sort_score(Student* pSt, int n)
{
	//순회용 구조체 포인터 변수 두개 선언
	Student* iter1, * iter2;
	//iter1은 pSt~끝까지 돌고, iter2는 iter1~끝까지 돈다.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//만약 iter1의 평균값보다 iter2의 평균값이 더 크다면
			if (iter1->avg < iter2->avg) {
				//서로 바꿔준다.
				Student p = *iter1;
				*iter1 = *iter2;
				*iter2 = p;
			}
		}
	}
	//평균값이 같은 경우에는 국어점수가 큰 순으로 정렬해야함.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//만약 평균값이 같고,
			if (iter1->avg == iter2->avg) {
				//국어점수가 더 크다면
				if (iter1->kor < iter2->kor) {
					//두 구조체를 서로 바꿔줌.
					Student p = *iter1;
					*iter1 = *iter2;
					*iter2 = p;
				}
			}
		}
	}
	//평균값도 같고, 국어점수까지 같은 경우에는 영어점수가 큰 순으로 정렬해야함.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//평균값이 같고,
			if (iter1->avg == iter2->avg) {
				//국어점수도 같은 경우에
				if (iter1->kor == iter2->kor) {
					//영어점수를 비교하여 두 구조체를 바꿔줌.
					if (iter1->eng < iter2->eng) {
						Student p = *iter1;
						*iter1 = *iter2;
						*iter2 = p;
					}
				}
			}
		}
	}
}

//인자로 받은 두 구조체 배열 포인터 변수 중에서 중간 등수 학생의 평균이 더 높은 포인터를 반환함.
Student* select_out(Student* p, Student* q, int n)
{
	;	//p의 중간 등수 학생의 평균이 q의 중간 등수 학생의 평균보다 높으면
	if ((p + n / 2)->avg > (q + n / 2)->avg) {
		//p를 반환
		return p;
	}
	//그렇지 않은 경우에는 q 반환.
	else if ((p + n / 2)->avg < (q + n / 2)->avg) {
		return q;
	}
}