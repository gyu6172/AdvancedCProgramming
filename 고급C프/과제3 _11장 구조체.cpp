#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 1-2
////학생 구조체 선언
//typedef struct student {
//	//이름
//	char name[10];
//	//학번
//	char id[11];
//	//성적
//	char grade;
//}Student;
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 2-2
//학생 구조체 선언
//typedef struct student {
//	//이름
//	char name[21];
//	//국어 점수
//	int kor;
//	//영어 점수
//	int eng;
//	//수학 점수
//	int math;
//	//평균
//	double avg;
//}Student;
////함수 선언
//void read_data(Student* pSt, int n);
//void sort_score(Student* pSt, int n);
//Student* select_out(Student* p, Student* q, int n);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 3-2
////호텔 구조체 선언
//typedef struct hotel {
//	//이름, 등급, 평판, 거리, 조식포함여부
//	char name[31];
//	int level;
//	double reputation;
//	double distance;
//	char includeBreakfast;
//}HOTEL;
////함수 선언
//int in_hotel_info(HOTEL *p);
//void out_hotel_info(HOTEL *p, int N, int G, double D);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 4
//주차 정보 구조체 선언
//typedef struct parking_info {
//	//차 번호, 폰 번호, 상품 코드, 정기권 보유 여부(Y/N), 정기권 종류, 주차 시간, 최종 비용
//	int carNum;
//	int phoneNum;
//	char product;
//	char isRegular;
//	int regularDay;
//	int parkingTime;
//	double cost = 0;
//}PARKING_INFO;
////함수 선언
//void input(PARKING_INFO *p, int n);
//void compute(PARKING_INFO *p);
//void display(PARKING_INFO *p, int n);
//void parking_info_sort(PARKING_INFO *p, int n);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 5
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
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 1-2
	////구조체 배열 선언
	//Student stus[5];
	////반복문 순회용 변수
	//int i,j;
	////5명의 학생에 대한 정보를 입력받아야하므로 5번 반복
	//for (i = 0; i < 5; i++) {
	//	//이름, 학번, 성적 입력
	//	scanf("%s %s %c",&stus[i].name, &stus[i].id, &stus[i].grade);
	//	//버퍼에 남아있는 개행문자 제거
	//	getchar();
	//}
	////찾고자 하는 학생의 이름, 그 학생의 성적, 그 학생의 입학년도
	//char findName[10], findGrade, findYear[5];
	////이름 입력
	//scanf("%s",&findName);
	//for (i = 0; i < 5; i++) {
	//	//만약 입력받은 이름과 같은 이름인 학생이 구조체 배열에 존재한다면
	//	if (strcmp(findName, stus[i].name)==0) {
	//		//그 학생의 성적과 입학년도에 값을 저장함.
	//		findGrade = stus[i].grade;
	//		strncpy(findYear,stus[i].id,4);
	//	}
	//}
	//findYear[4] = NULL;

	////조건에 맞는 학생이 있는지 없는지 나타낼 변수
	//int chk=0;
	//for (i = 0; i < 5; i++) {
	//	char strYear[5];
	//	strncpy(strYear, stus[i].id, 4);
	//	strYear[4]=NULL;
	//	//만약 입력받은 학생의 성적과 같은 성적을 가진 학생을 찾는다면
	//	if (findGrade == stus[i].grade) {
	//		//입력받은 학생이 아니고, 입학년도가 같다면
	//		if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear)==0)) {
	//			//chk값을 바꿔주고 이름을 출력해준다.
	//			chk=1;
	//			printf("%s ",stus[i].name);
	//		}
	//	}
	//}
	////만약 chk값이 바뀌지 않았다면 0을 출력
	//if(!chk)
	//	printf("0\n");
	//printf("\n");
	////찾고자 하는 학생의 입학년도와 입학년도를 131로 나눈 나머지 출력
	//int num = atoi(findYear)%131;
	//printf("%s %d",findYear,num);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 2-2
	////학생 수 입력
	//int n;
	//scanf("%d",&n);
	////구조체 배열 두 개와 각각의 구조체 포인터 변수 두개, 최종 출력할 포인터 변수 선언
	//Student st1[49], st2[49], *pSt, *qSt, *finalSt;
	////pSt는 st1를, qSt는 st2를 가리키게 함
	//pSt = st1;
	//qSt = st2;
	////두 개의 구조체 입력받음
	//read_data(pSt, n);
	//read_data(qSt, n);
	////두 구조체 정렬
	//sort_score(pSt, n);
	//sort_score(qSt, n);
	////두 구조체 중에서 조건에 맞는 구조체포인터를 반환하여 finalSt에 저장
	//finalSt = select_out(pSt, qSt, n);
	////finalSt를 순회하며 출력한다.
	//for (Student* iter = finalSt; iter < finalSt + n; iter++) {
	//	printf("%s %d %d %d %.1f\n",iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	//}
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 3-2
	////구조체 배열과 그 배열을 가리키는 포인터 변수 선언
	//HOTEL hotels[100], *pHotel;
	//pHotel = hotels;
	////호텔들의 정보를 입력받고 입력받은 개수를 반환하여 hotelCnt에 저장.
	//int hotelCnt = in_hotel_info(pHotel);
	//int G;
	//double D;
	////G, D 입력받음
	//scanf("%d %lf",&G,&D);
	////함수불러와서 최종값 출력
	//out_hotel_info(pHotel, hotelCnt, G, D);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 4
	////구조체 배열 선언
	//PARKING_INFO parkingLot[100];
	////구조체 배열을 가리키는 포인터 선언
	//PARKING_INFO *p=parkingLot;
	////차 개수 입력받음
	//int n;
	//scanf("%d",&n);
	//getchar();
	////함수 불러와서 구조체 배열에 값 저장
	//input(p, n);
	////배열을 순회하며 각 구조체의 주차비용을 계산함
	//for (p = parkingLot; p < parkingLot + n; p++) {
	//	compute(p);
	//}
	////포인터 초기화
	//p=parkingLot;
	////구조체 배열 정렬함수 불러옴
	//parking_info_sort(p,n);
	////최종 값 출력
	//display(p,n);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 5

	while (1) {
		//명령어 입력받음
		char code;
		scanf("%c",&code);
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
		else if(code=='Q'){
			break;
		}
	}
	
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

////입력 함수
//void read_data(Student* pSt, int n)
//{
//	//반복문 순회용	구조체 포인터 변수
//	Student* iter;
//	for (iter = pSt; iter < pSt + n; iter++) {
//		//n번 반복하며 입력받음
//		scanf("%s %d %d %d",&iter->name, &iter->kor, &iter->eng, &iter->math);
//		getchar();
//		//평균값 초기화해줌.
//		iter->avg = ((iter->kor) + (iter->eng) + (iter->math))/3.0;
//	}
//}
//
////정렬 함수
//void sort_score(Student* pSt, int n)
//{
//	//순회용 구조체 포인터 변수 두개 선언
//	Student* iter1, *iter2;
//	//iter1은 pSt~끝까지 돌고, iter2는 iter1~끝까지 돈다.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//만약 iter1의 평균값보다 iter2의 평균값이 더 크다면
//			if (iter1->avg < iter2->avg) {
//				//서로 바꿔준다.
//				Student p = *iter1;
//				*iter1 = *iter2;
//				*iter2 = p;
//			}
//		}
//	}
//	//평균값이 같은 경우에는 국어점수가 큰 순으로 정렬해야함.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//만약 평균값이 같고,
//			if (iter1->avg == iter2->avg) {
//				//국어점수가 더 크다면
//				if (iter1->kor < iter2->kor) {
//					//두 구조체를 서로 바꿔줌.
//					Student p = *iter1;
//					*iter1 = *iter2;
//					*iter2 = p;
//				}
//			}
//		}
//	}
//	//평균값도 같고, 국어점수까지 같은 경우에는 영어점수가 큰 순으로 정렬해야함.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//평균값이 같고,
//			if (iter1->avg == iter2->avg) {
//				//국어점수도 같은 경우에
//				if (iter1->kor == iter2->kor) {
//					//영어점수를 비교하여 두 구조체를 바꿔줌.
//					if (iter1->eng < iter2->eng) {
//						Student p = *iter1;
//						*iter1 = *iter2;
//						*iter2 = p;
//					}
//				}
//			}
//		}
//	}
//}
//
////인자로 받은 두 구조체 배열 포인터 변수 중에서 중간 등수 학생의 평균이 더 높은 포인터를 반환함.
//Student* select_out(Student* p, Student* q, int n)
//{
//;	//p의 중간 등수 학생의 평균이 q의 중간 등수 학생의 평균보다 높으면
//	if ((p+n/2)->avg > (q+n/2)->avg) {
//		//p를 반환
//		return p;
//	}
//	//그렇지 않은 경우에는 q 반환.
//	else if ((p+n/2)->avg < (q+n/2)->avg) {
//		return q;
//	}
//}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

////호텔 정보 입력 함수
//int in_hotel_info(HOTEL* p)
//{	
//	//입력받은 호텔의 개수
//	int hotelCnt=0;
//	while (1) {
//		//이름을 입력받음
//		scanf("%s" ,&p->name);
//		//만약 0이 입력되었다면 반복문 탈출
//		if (strcmp(p->name, "0") == 0) {
//			break;
//		}
//		//등급, 평판, 거리, 조식포함여부(Y/N) 입력받음
//		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
//		//개행문자제거
//		getchar();
//		//입력 개수와 포인터 변수 1 증가시킴.
//		hotelCnt++;
//		p++;
//	}
//	//최종적으로 입력 받은 개수 반환.
//	return hotelCnt;
//}
//
////출력용 함수
//void out_hotel_info(HOTEL* p, int N, int G, double D)
//{
//	//반복문 순회용 구조체포인터 변수 선언
//	HOTEL *iter1, *iter2;
//	//먼저 평판도가 높은 순으로 정렬해야함
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//반복문을 순회하다가 iter2의 평판이 더 높다면 서로 바꿔줌.
//			if (iter1->reputation < iter2->reputation) {
//				HOTEL tmp = *iter1;
//				*iter1 = *iter2;
//				*iter2 = tmp;
//			}
//		}
//	}
//	//평판도 순으로 정렬된 배열에서 사전에서 빠른 순으로 정렬
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//만약 평판도가 같고
//			if (iter1->reputation == iter2->reputation) {
//				//사전순으로 빠르다면 서로 바꿔줌.
//				if (strcmp(iter1->name, iter2->name)>0) {
//					HOTEL tmp = *iter1;
//					*iter1 = *iter2;
//					*iter2 = tmp;
//				}
//			}
//		}
//	}
//	//등급이 G보다 크거나 같고, 거리가 D보다 작거나 같은 호텔들의 정보를 출력함.
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		if (iter1->level >= G) {
//			if (iter1->distance <= D) {
//				printf("%s %d %.1f %.1f %c\n",iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
//			}
//		}
//	}
//}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

////입력용 함수
//void input(PARKING_INFO* p, int n)
//{
//	//반복문 순회용 포인터변수 선언
//	PARKING_INFO *iter;
//	for (iter = p; iter < p + n; iter++) {
//		//차 번호, 폰 번호, 상품 종류 입력받음.
//		scanf("%d %d %c ",&iter->carNum, &iter->phoneNum, &iter->product);
//		//만약 상품종류가 S라면, 정기권 보유여부와 정기권 종류를 입력받음
//		if (iter->product == 'S') {
//			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
//		}
//		//주차 시간 입력받음.
//		scanf("%d",&iter->parkingTime);
//		getchar();
//	}
//}
//
////주차 비용 계산 함수
//void compute(PARKING_INFO* p)
//{
//	//먼저 정기권 유무에 대한 비용을 먼저 계산해준다.
//	//만약 상품이 S인 경우
//	if (p->product == 'S') {
//		//정기권을 가지고 있다면
//		if (p->isRegular == 'Y') {
//			//초과 시간에 대한 계산만 하면 되므로 여기서는 아무작업도 하지 않는다.
//		}
//		//정기권을 가지고 있지 않다면
//		else if (p->isRegular == 'N') {
//			//7일 정기권 비용을 cost에 추가해줌.
//			if (p->regularDay == 7) {
//				p->cost += 30000;
//			}
//			//30일 정기권 비용을 cost에 추가해줌.
//			else if (p->regularDay == 30) {
//				p->cost += 100000;
//			}
//			//180일 정기권 비용을 cost에 추가해줌.
//			else if (p->regularDay == 180) {
//				p->cost += 500000;
//			}
//		}
//	}
//	//만약 상품이 D인 경우
//	else if (p->product == 'D') {
//		//일일권 비용 5000원만 cost에 추가해준다.
//		p->cost += 5000;
//	}
//	//만약 주차시간이 4시간, 즉 240분을 넘어 간다면
//	if (p->parkingTime > 240) {
//		//240분이 넘어가면 10분마다 200원이므로 먼저 주차시간에서 240을 빼주고,
//		int time = (p->parkingTime) - 240;
//		//그 값을 10으로 나눈 다음 200을 곱해서 cost에 더해준다.
//		int tmp = time / 10;
//		p->cost += (tmp * 200);
//	}
//}
//
////출력용 함수
//void display(PARKING_INFO* p, int n)
//{
//	//반복문 순회용 포인터변수
//	PARKING_INFO *iter;
//	//일일권 비용 합계, 정기권 비용 합계를 저장할 변수
//	double Dsum=0, Ssum=0;
//	for (iter = p; iter < p + n; iter++) {
//		//반복문 순회하면서 차 번호, 폰 번호, 상품 종류, 주차 비용 출력해준다.
//		printf("%d %d %c %.0f\n",iter->carNum, iter->phoneNum, iter->product, iter->cost);
//		//상품 종류가 D라면 일일권 비용합계에 주차 비용을 더해주고
//		if(iter->product == 'D')
//			Dsum += iter->cost;
//		//상품 종류가 S라면 정기권 비용합계에 주차 비용을 더해준다.
//		else if(iter->product == 'S')
//			Ssum += iter->cost;
//	}
//	//D합계, S합계, 주차 비용 총합(D+S)를 출력해준다.
//	printf("%.1f %.1f %.1f",Dsum,Ssum, Dsum+Ssum);
//}
//
////주차 정보 정렬 함수
//void parking_info_sort(PARKING_INFO* p, int n)
//{
//	//반복문 순회용 변수 선언
//	PARKING_INFO *x, *y;
//	//먼저 상품 종류대로 정렬해준다.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//D가 먼저 나오고, 그 다음 S가 나와야함.
//			if (x->product > y->product) {
//				PARKING_INFO tmp = *x;
//				*x = *y;
//				*y = tmp;
//			}
//		}
//	}
//	//상품 종류대로 정렬하고 나면 차 번호대로 정렬해준다.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//상품의 종류가 같은 경우에
//			if (x->product == y->product) {
//				//차 번호대로 정렬해준다.
//				if (x->carNum > y->carNum) {
//					PARKING_INFO tmp = *x;
//					*x = *y;
//					*y = tmp;
//				}
//			}
//		}
//	}
//	
//}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

//입력 함수
void inputStudent()
{	
	//학생 구조체변수 선언
	Student tmp;
	//취득 학점 0으로 초기화
	tmp.point=0;
	//이름, 학번, 과목 수 입력받음
	scanf("%s %d %d",&tmp.name, &tmp.id, &tmp.gradeCnt);
	//과목 수 만큼 반복해서 과목이름과 그 과목의 학점 입력받음
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf",&tmp.grade[i], &p);
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
	int i,j;
	//새로운 배열에 구조체 복사
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	//새로운 배열을 이름 순으로 정렬해준다.
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			//만약 이름이 사전 순으로 앞이라면
			if (strcmp(newArr[i].name, newArr[j].name)>0) {
				//구조체 멤버를 바꿔준다.
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	//출력함수 불러와서 새로운 배열 출력
	printStudent(newArr,cnt);
}

//학생 삭제 함수
void deleteStudent()
{
	//삭제하고자 하는 이름을 입력받을 변수
	char findName[31];
	//이름 입력받고 개행문자 제거
	scanf("%s",&findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		//배열 순회 하면서 입력 받은 이름을 찾은 경우
		if (strcmp(students[i].name, findName) == 0) {
			//찾은 위치부터 배열의 끝까지 한 칸씩 앞으로 당김.
			for (int j = i; j < studentCnt-1; j++) {
				students[j] = students[j+1];
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
		printf("%s %d %d %.2f\n",arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point/arr[i].gradeCnt);
	}
}
