#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 1-2
//typedef struct student {
//	char name[10];
//	char id[11];
//	char grade;
//}Student;
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 2-2
//typedef struct student {
//	char name[21];
//	int kor;
//	int eng;
//	int math;
//	double avg;
//}Student;
//void read_data(Student* pSt, int n);
//void sort_score(Student* pSt, int n);
//Student* select_out(Student* p, Student* q, int n);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 3-2
//typedef struct hotel {
//	char name[31];
//	int level;
//	double reputation;
//	double distance;
//	char includeBreakfast;
//}HOTEL;
//int in_hotel_info(HOTEL *p);
//void out_hotel_info(HOTEL *p, int N, int G, double D);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 4
//typedef struct parking_info {
//	int carNum;
//	int phoneNum;
//	char product;
//	char isRegular;
//	int regularDay;
//	int parkingTime;
//	double cost = 0;
//}PARKING_INFO;
//void input(PARKING_INFO *p, int n);
//void compute(PARKING_INFO *p);
//void display(PARKING_INFO *p, int n);
//void parking_info_sort(PARKING_INFO *p, int n);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 5
typedef struct stu {
	char name[31];
	int id;
	int gradeCnt;
	char grade[10][31];
	double point;
}Student;
Student students[100];
int studentCnt = 0;
void inputStudent();
void sortStudent(Student arr[], int cnt);
void deleteStudent();
void printStudent(Student arr[], int cnt);
int main() {
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 1-2
	//Student stus[5];
	//int i,j;
	//for (i = 0; i < 5; i++) {
	//	scanf("%s %s %c",&stus[i].name, &stus[i].id, &stus[i].grade);
	//	getchar();
	//}
	//char findName[10], findGrade, findYear[5];
	//scanf("%s",&findName);
	//for (i = 0; i < 5; i++) {
	//	if (strcmp(findName, stus[i].name)==0) {
	//		findGrade = stus[i].grade;
	//		strncpy(findYear,stus[i].id,4);
	//	}
	//}
	//findYear[4] = NULL;
	//int chk=0;
	//for (i = 0; i < 5; i++) {
	//	char strYear[5];
	//	strncpy(strYear, stus[i].id, 4);
	//	strYear[4]=NULL;
	//	if (findGrade == stus[i].grade) {
	//		if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear)==0)) {
	//			chk=1;
	//			printf("%s ",stus[i].name);
	//		}
	//	}
	//}
	//if(!chk)
	//	printf("0\n");
	//printf("\n");
	//int num = atoi(findYear)%131;
	//printf("%s %d",findYear,num);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 2-2
	//구조체 배열에 대한 포인터 표기 사용
	//int n;
	//scanf("%d",&n);
	//Student st1[49], st2[49], *pSt, *qSt, *finalSt;
	//pSt = st1;
	//qSt = st2;
	//read_data(pSt, n);
	//read_data(qSt, n);
	//sort_score(pSt, n);
	//sort_score(qSt, n);
	//finalSt = select_out(pSt, qSt, n);
	//for (Student* iter = finalSt; iter < finalSt + n; iter++) {
	//	printf("%s %d %d %d %.1f\n",iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	//}
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 3-2
	//문제 조건 주의
	//OJ에서 80점
	//HOTEL hotels[100], *pHotel;
	//pHotel = hotels;
	//int hotelCnt = in_hotel_info(pHotel);
	//int G;
	//double D;
	//scanf("%d %lf",&G,&D);
	//out_hotel_info(pHotel, hotelCnt, G, D);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 4
	//PARKING_INFO parkingLot[100];
	//PARKING_INFO *p=parkingLot;
	//int n;
	//scanf("%d",&n);
	//getchar();
	//input(p, n);
	//for (p = parkingLot; p < parkingLot + n; p++) {
	//	compute(p);
	//}
	//p=parkingLot;
	//parking_info_sort(p,n);
	//display(p,n);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 5

	while (1) {
		char code;
		scanf("%c",&code);
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

//void read_data(Student* pSt, int n)
//{
//	Student* iter;
//	for (iter = pSt; iter < pSt + n; iter++) {
//		scanf("%s %d %d %d",&iter->name, &iter->kor, &iter->eng, &iter->math);
//		getchar();
//		iter->avg = ((iter->kor) + (iter->eng) + (iter->math))/3.0;
//	}
//}
//
//void sort_score(Student* pSt, int n)
//{
//	Student* iter1, *iter2;
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			if (iter1->avg < iter2->avg) {
//				Student p = *iter1;
//				*iter1 = *iter2;
//				*iter2 = p;
//			}
//		}
//	}
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			if (iter1->avg == iter2->avg) {
//				if (iter1->kor < iter2->kor) {
//					Student p = *iter1;
//					*iter1 = *iter2;
//					*iter2 = p;
//				}
//			}
//		}
//	}
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			if (iter1->avg == iter2->avg) {
//				if (iter1->kor == iter2->kor) {
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

//Student* select_out(Student* p, Student* q, int n)
//{
//;
//	if ((p+n/2)->avg > (q+n/2)->avg) {
//		return p;
//	}
//	else if ((p+n/2)->avg < (q+n/2)->avg) {
//		return q;
//	}
//}

//int in_hotel_info(HOTEL* p)
//{	
//	int hotelCnt=0;
//	while (1) {
//		scanf("%s" ,&p->name);
//		if (strcmp(p->name, "0") == 0) {
//			break;
//		}
//		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
//		getchar();
//		hotelCnt++;
//		p++;
//	}
//	return hotelCnt;
//}
//
//void out_hotel_info(HOTEL* p, int N, int G, double D)
//{
//	HOTEL *iter1, *iter2;
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			if (iter1->reputation < iter2->reputation) {
//				HOTEL tmp = *iter1;
//				*iter1 = *iter2;
//				*iter2 = tmp;
//			}
//		}
//	}
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			if (iter1->reputation == iter2->reputation) {
//				if (strcmp(iter1->name, iter2->name)==1) {
//					HOTEL tmp = *iter1;
//					*iter1 = *iter2;
//					*iter2 = tmp;
//				}
//			}
//		}
//	}
//	for (iter1=p; iter1 < p + N; iter1++) {
//		printf("%s %d %.1f %.1f %c\n", iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
//	}
//	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		if (iter1->level >= G) {
//			if (iter1->distance <= D) {
//				printf("%s %d %.1f %.1f %c\n",iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
//			}
//		}
//	}
//}

//void input(PARKING_INFO* p, int n)
//{
//	PARKING_INFO *iter;
//	for (iter = p; iter < p + n; iter++) {
//		scanf("%d %d %c ",&iter->carNum, &iter->phoneNum, &iter->product);
//		if (iter->product == 'S') {
//			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
//		}
//		scanf("%d",&iter->parkingTime);
//		getchar();
//		//printf("%d %d %c %c %d %d\n",iter->carNum, iter->phoneNum, iter->product, iter->isRegular, iter->regularDay, iter->parkingTime);
//	}
//}
//
//void compute(PARKING_INFO* p)
//{
//	if (p->product == 'S') {
//		if (p->isRegular == 'Y') {
//			//아무것도 하지 않는다.
//		}
//		else if (p->isRegular == 'N') {
//			if (p->regularDay == 7) {
//				p->cost += 30000;
//			}
//			else if (p->regularDay == 30) {
//				p->cost += 100000;
//			}
//			else if (p->regularDay == 180) {
//				p->cost += 500000;
//			}
//		}
//	}
//	else if (p->product == 'D') {
//		p->cost += 5000;
//	}
//	if (p->parkingTime > 240) {
//		int time = (p->parkingTime) - 240;
//		int tmp = time / 10;
//		p->cost += (tmp * 200);
//	}
//}
//
//void display(PARKING_INFO* p, int n)
//{
//	PARKING_INFO *iter;
//	int Dsum=0, Ssum=0;
//	for (iter = p; iter < p + n; iter++) {
//		printf("%d %d %c %.0f\n",iter->carNum, iter->phoneNum, iter->product, iter->cost);
//		if(iter->product == 'D')
//			Dsum += iter->cost;
//		else if(iter->product == 'S')
//			Ssum += iter->cost;
//	}
//	printf("%d %d %d",Dsum,Ssum, Dsum+Ssum);
//}
//void parking_info_sort(PARKING_INFO* p, int n)
//{
//	PARKING_INFO *x, *y;
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			if (x->product > y->product) {
//				PARKING_INFO tmp = *x;
//				*x = *y;
//				*y = tmp;
//			}
//		}
//	}
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			if (x->product == y->product) {
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



void inputStudent()
{
	Student tmp;
	tmp.point=0;
	scanf("%s %d %d",&tmp.name, &tmp.id, &tmp.gradeCnt);
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf",&tmp.grade[i], &p);
		tmp.point += p;
	}
	getchar();
	students[studentCnt] = tmp;
	studentCnt++;
}

void sortStudent(Student arr[], int cnt)
{
	Student newArr[100];
	int i,j;
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			if (strcmp(newArr[i].name, newArr[j].name)==1) {
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	printStudent(newArr,cnt);
}

void deleteStudent()
{
	char findName[31];
	scanf("%s",&findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		if (strcmp(students[i].name, findName) == 0) {
			for (int j = i; j < studentCnt-1; j++) {
				students[j] = students[j+1];
			}
			studentCnt--;
		}
	}
}

void printStudent(Student arr[], int cnt)
{
	for (int i = 0; i < cnt; i++) {
		printf("%s %d %d %.2f\n",arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point/arr[i].gradeCnt);
	}
}
