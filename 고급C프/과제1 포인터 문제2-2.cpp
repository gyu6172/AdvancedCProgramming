#include <stdio.h>
int passengerN(int n);
int changeseat(int* ar);
int* rebooking(int* ar);

int main() {
	//승객 수가 저장될 변수 n
	int n;
	//n 입력받음
	scanf("%d", &n);
	//배열 순회용 포인터 변수 p 선언
	int* p;
	//배열 선언. 0으로 다 초기화시킴.
	int bus[25] = { 0, };
	for (p = bus; p < bus + n; p++) {
		//배열에 값 입력받음
		scanf("%d", p);
	}
	//passengerN이 -1이라면. 즉, 승객수가 충분하지 않다면
	if (passengerN(n) == -1) {
		//-1을 출력하고
		printf("-1");
		//프로그램 종료
		return 0;
	}
	//그 외의 경우
	else {
		//0출력
		printf("0\n");
		//최종 결과가 저장될 배열 arr
		int* arr = rebooking(bus);
		for (p = arr; p < arr + n; p++) {
			//arr의 값을 출력함.
			printf("%d ", *p);
		}
	}
}

//승객 수에 따라 정수를 반환하는 함수
int passengerN(int n)
{
	//승객 수가 5보다 작으면 -1 반환
	if (n < 5)
		return -1;
	else
		//그 외의 경우는 0반환
		return 0;
}

//배열에 없는 숫자중에서 가장 작은 숫자를 리턴하는 함수
int changeseat(int* ar)
{
	//체크용 배열. chk[n] = 1이라면 n번 좌석이 예약되었다는 뜻. 
	//chk[m] = 0 이라면 m번 좌석이 예약되지 않았다는 뜻.
	int chk[22] = { 0, };
	int* p;
	for (p = ar; *p != 0; p++) {
		//인자로 건네받은 배열을 순회하며 chk배열을 업데이트함.
		chk[*p] = 1;
	}
	for (int i = 1; i <= 21; i++) {
		//i를 1부터 21까지 돌리면서 만약 chk[i]가 0이라면
		//예약되지 않은 좌석 중에서 가장 작은 숫자가 i라는 뜻이므로 i를 리턴.
		if (chk[i] == 0) {
			return i;
		}
	}
}

//인자로 배열을 건네받아 중복예약된 좌석을 처리한 배열을 반환하는 함수
int* rebooking(int* ar)
{
	int* p, * q;
	for (p = ar; *p != 0; p++) {
		//ar을 순회하며 각 좌석이 예약된 횟수를 센다.
		//횟수 저장용 변수 cnt
		int cnt = 0;
		//만약 *p==*q라면 cnt를 1증가시킴.
		for (q = ar; *q != 0; q++) {
			if (*p == *q) {
				cnt++;
			}
		}
		//cnt가 1보다 크다면 *p번 좌석은 중복예약되었다는뜻.
		if (cnt > 1) {
			//p 다음 주소부터 배열의 끝까지 순회를 돔.
			for (q = p + 1; *q != 0; q++) {
				//만약 *p == *q 라면, *q번 좌석이 중복예약된 좌석이므로
				//*q번 좌석번호를 가장 빠른 빈 좌석번호로 바꿈.
				if (*q == *p) {
					*q = changeseat(ar);
				}
			}
		}
	}
	//업데이트된 배열을 반환한다.
	return ar;
}