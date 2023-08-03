#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//주차 정보 구조체 선언
typedef struct parking_info {
	//차 번호, 폰 번호, 상품 코드, 정기권 보유 여부(Y/N), 정기권 종류, 주차 시간, 최종 비용
	int carNum;
	int phoneNum;
	char product;
	char isRegular;
	int regularDay;
	int parkingTime;
	double cost = 0;
}PARKING_INFO;
//함수 선언
void input(PARKING_INFO* p, int n);
void compute(PARKING_INFO* p);
void display(PARKING_INFO* p, int n);
void parking_info_sort(PARKING_INFO* p, int n);
int main() {
	//구조체 배열 선언
	PARKING_INFO parkingLot[100];
	//구조체 배열을 가리키는 포인터 선언
	PARKING_INFO* p = parkingLot;
	//차 개수 입력받음
	int n;
	scanf("%d", &n);
	getchar();
	//함수 불러와서 구조체 배열에 값 저장
	input(p, n);
	//배열을 순회하며 각 구조체의 주차비용을 계산함
	for (p = parkingLot; p < parkingLot + n; p++) {
		compute(p);
	}
	//포인터 초기화
	p = parkingLot;
	//구조체 배열 정렬함수 불러옴
	parking_info_sort(p, n);
	//최종 값 출력
	display(p, n);
}

//입력용 함수
void input(PARKING_INFO* p, int n)
{
	//반복문 순회용 포인터변수 선언
	PARKING_INFO* iter;
	for (iter = p; iter < p + n; iter++) {
		//차 번호, 폰 번호, 상품 종류 입력받음.
		scanf("%d %d %c ", &iter->carNum, &iter->phoneNum, &iter->product);
		//만약 상품종류가 S라면, 정기권 보유여부와 정기권 종류를 입력받음
		if (iter->product == 'S') {
			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
		}
		//주차 시간 입력받음.
		scanf("%d", &iter->parkingTime);
		getchar();
	}
}

//주차 비용 계산 함수
void compute(PARKING_INFO* p)
{
	//먼저 정기권 유무에 대한 비용을 먼저 계산해준다.
	//만약 상품이 S인 경우
	if (p->product == 'S') {
		//정기권을 가지고 있다면
		if (p->isRegular == 'Y') {
			//초과 시간에 대한 계산만 하면 되므로 여기서는 아무작업도 하지 않는다.
		}
		//정기권을 가지고 있지 않다면
		else if (p->isRegular == 'N') {
			//7일 정기권 비용을 cost에 추가해줌.
			if (p->regularDay == 7) {
				p->cost += 30000;
			}
			//30일 정기권 비용을 cost에 추가해줌.
			else if (p->regularDay == 30) {
				p->cost += 100000;
			}
			//180일 정기권 비용을 cost에 추가해줌.
			else if (p->regularDay == 180) {
				p->cost += 500000;
			}
		}
	}
	//만약 상품이 D인 경우
	else if (p->product == 'D') {
		//일일권 비용 5000원만 cost에 추가해준다.
		p->cost += 5000;
	}
	//만약 주차시간이 4시간, 즉 240분을 넘어 간다면
	if (p->parkingTime > 240) {
		//240분이 넘어가면 10분마다 200원이므로 먼저 주차시간에서 240을 빼주고,
		int time = (p->parkingTime) - 240;
		//그 값을 10으로 나눈 다음 200을 곱해서 cost에 더해준다.
		int tmp = time / 10;
		p->cost += (tmp * 200);
	}
}

//출력용 함수
void display(PARKING_INFO* p, int n)
{
	//반복문 순회용 포인터변수
	PARKING_INFO* iter;
	//일일권 비용 합계, 정기권 비용 합계를 저장할 변수
	double Dsum = 0, Ssum = 0;
	for (iter = p; iter < p + n; iter++) {
		//반복문 순회하면서 차 번호, 폰 번호, 상품 종류, 주차 비용 출력해준다.
		printf("%d %d %c %.0f\n", iter->carNum, iter->phoneNum, iter->product, iter->cost);
		//상품 종류가 D라면 일일권 비용합계에 주차 비용을 더해주고
		if (iter->product == 'D')
			Dsum += iter->cost;
		//상품 종류가 S라면 정기권 비용합계에 주차 비용을 더해준다.
		else if (iter->product == 'S')
			Ssum += iter->cost;
	}
	//D합계, S합계, 주차 비용 총합(D+S)를 출력해준다.
	printf("%.1f %.1f %.1f", Dsum, Ssum, Dsum + Ssum);
}

//주차 정보 정렬 함수
void parking_info_sort(PARKING_INFO* p, int n)
{
	//반복문 순회용 변수 선언
	PARKING_INFO* x, * y;
	//먼저 상품 종류대로 정렬해준다.
	for (x = p; x < p + n; x++) {
		for (y = x; y < p + n; y++) {
			//D가 먼저 나오고, 그 다음 S가 나와야함.
			if (x->product > y->product) {
				PARKING_INFO tmp = *x;
				*x = *y;
				*y = tmp;
			}
		}
	}
	//상품 종류대로 정렬하고 나면 차 번호대로 정렬해준다.
	for (x = p; x < p + n; x++) {
		for (y = x; y < p + n; y++) {
			//상품의 종류가 같은 경우에
			if (x->product == y->product) {
				//차 번호대로 정렬해준다.
				if (x->carNum > y->carNum) {
					PARKING_INFO tmp = *x;
					*x = *y;
					*y = tmp;
				}
			}
		}
	}

}