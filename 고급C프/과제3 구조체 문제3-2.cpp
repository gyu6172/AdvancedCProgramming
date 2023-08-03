#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//호텔 구조체 선언
typedef struct hotel {
	//이름, 등급, 평판, 거리, 조식포함여부
	char name[31];
	int level;
	double reputation;
	double distance;
	char includeBreakfast;
}HOTEL;
//함수 선언
int in_hotel_info(HOTEL* p);
void out_hotel_info(HOTEL* p, int N, int G, double D);
int main() {
	//구조체 배열과 그 배열을 가리키는 포인터 변수 선언
	HOTEL hotels[100], * pHotel;
	pHotel = hotels;
	//호텔들의 정보를 입력받고 입력받은 개수를 반환하여 hotelCnt에 저장.
	int hotelCnt = in_hotel_info(pHotel);
	int G;
	double D;
	//G, D 입력받음
	scanf("%d %lf", &G, &D);
	//함수불러와서 최종값 출력
	out_hotel_info(pHotel, hotelCnt, G, D);
}
//호텔 정보 입력 함수
int in_hotel_info(HOTEL* p)
{
	//입력받은 호텔의 개수
	int hotelCnt = 0;
	while (1) {
		//이름을 입력받음
		scanf("%s", &p->name);
		//만약 0이 입력되었다면 반복문 탈출
		if (strcmp(p->name, "0") == 0) {
			break;
		}
		//등급, 평판, 거리, 조식포함여부(Y/N) 입력받음
		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
		//개행문자제거
		getchar();
		//입력 개수와 포인터 변수 1 증가시킴.
		hotelCnt++;
		p++;
	}
	//최종적으로 입력 받은 개수 반환.
	return hotelCnt;
}

//출력용 함수
void out_hotel_info(HOTEL* p, int N, int G, double D)
{
	//반복문 순회용 구조체포인터 변수 선언
	HOTEL* iter1, * iter2;
	//먼저 평판도가 높은 순으로 정렬해야함
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			//반복문을 순회하다가 iter2의 평판이 더 높다면 서로 바꿔줌.
			if (iter1->reputation < iter2->reputation) {
				HOTEL tmp = *iter1;
				*iter1 = *iter2;
				*iter2 = tmp;
			}
		}
	}
	//평판도 순으로 정렬된 배열에서 사전에서 빠른 순으로 정렬
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			//만약 평판도가 같고
			if (iter1->reputation == iter2->reputation) {
				//사전순으로 빠르다면 서로 바꿔줌.
				if (strcmp(iter1->name, iter2->name) > 0) {
					HOTEL tmp = *iter1;
					*iter1 = *iter2;
					*iter2 = tmp;
				}
			}
		}
	}
	//등급이 G보다 크거나 같고, 거리가 D보다 작거나 같은 호텔들의 정보를 출력함.
	for (iter1 = p; iter1 < p + N; iter1++) {
		if (iter1->level >= G) {
			if (iter1->distance <= D) {
				printf("%s %d %.1f %.1f %c\n", iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
			}
		}
	}
}