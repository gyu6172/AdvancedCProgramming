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
typedef struct student {
	char name[21];
	int kor;
	int eng;
	int math;
	double avg;
}Student;
void read_data(Student* pSt, int n);
void sort_score(Student* pSt, int n);
Student* select_out(Student* p, Student* q, int n);
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//problem 3-2
typedef struct hotel {
	char name[31];
	int level;
	double reputation;
	double distance;
	char includeBreakfast;
}HOTEL;
int in_hotel_info(HOTEL *p);
void out_hotel_info(HOTEL *p, int N, int G, double D);

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
	//problem 4-2


	

}

void read_data(Student* pSt, int n)
{
	Student* iter;
	for (iter = pSt; iter < pSt + n; iter++) {
		scanf("%s %d %d %d",&iter->name, &iter->kor, &iter->eng, &iter->math);
		getchar();
		iter->avg = ((iter->kor) + (iter->eng) + (iter->math))/3.0;
	}
}

void sort_score(Student* pSt, int n)
{
	//avg에 대한 정렬만 완료되었다. 이거 고쳐야합니다.
	Student* iter1, *iter2;
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			if (iter1->avg < iter2->avg) {
				Student p = *iter1;
				*iter1 = *iter2;
				*iter2 = p;
			}
		}
	}
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			if (iter1->avg == iter2->avg) {
				if (iter1->kor < iter2->kor) {
					Student p = *iter1;
					*iter1 = *iter2;
					*iter2 = p;
				}
			}
		}
	}
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			if (iter1->avg == iter2->avg) {
				if (iter1->kor == iter2->kor) {
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

Student* select_out(Student* p, Student* q, int n)
{
;
	if ((p+n/2)->avg > (q+n/2)->avg) {
		return p;
	}
	else if ((p+n/2)->avg < (q+n/2)->avg) {
		return q;
	}
}

int in_hotel_info(HOTEL* p)
{	
	int hotelCnt=0;
	while (1) {
		scanf("%s" ,&p->name);
		if (strcmp(p->name, "0") == 0) {
			break;
		}
		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
		getchar();
		hotelCnt++;
		p++;
	}
	return hotelCnt;
}

void out_hotel_info(HOTEL* p, int N, int G, double D)
{
	HOTEL *iter1, *iter2;
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			if (iter1->reputation < iter2->reputation) {
				HOTEL tmp = *iter1;
				*iter1 = *iter2;
				*iter2 = tmp;
			}
		}
	}
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			if (iter1->reputation == iter2->reputation) {
				if (strcmp(iter1->name, iter2->name)==1) {
					HOTEL tmp = *iter1;
					*iter1 = *iter2;
					*iter2 = tmp;
				}
			}
		}
	}
	for (iter1=p; iter1 < p + N; iter1++) {
		printf("%s %d %.1f %.1f %c\n", iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
	}
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	for (iter1 = p; iter1 < p + N; iter1++) {
		if (iter1->level >= G) {
			if (iter1->distance <= D) {
				printf("%s %d %.1f %.1f %c\n",iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
			}
		}
	}
}
