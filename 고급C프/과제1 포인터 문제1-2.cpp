#include <stdio.h>
int* MAX(int ar[]);
int* MIN(int ar[]);
int main() {
	//줄 수를 입력받을 변수 n 선언
	int n;
	//줄 수 입력받음
	scanf("%d", &n);
	int i, j;

	//n번 반복하며 입력받음.
	for (i = 0; i < n; i++) {
		//입력용 변수 a
		int a;
		//입력받을 변수가 저장될 배열 arr
		int arr[100];
		//배열 arr의 크기를 알려주는 변수 arrIter
		int arrIter = 0;
		while (1) {
			//a 입력받음
			scanf("%d", &a);
			//arr에 a를 넣음
			arr[arrIter] = a;
			//배열 크기 1증가시킴.
			arrIter++;
			//만약 0을 입력했다면 break로 반복문 탈출하여 입력을 그만받음
			if (a == 0)
				break;
		}
		//maxPos와 minPos에는 각각 배열의 최댓값의 주소, 최솟값의 주소가 저장됨.
		int* maxPos = MAX(arr);
		int* minPos = MIN(arr);
		//만약 최솟값이 최댓값보다 뒤에 있다면
		if (minPos > maxPos + 1) {
			int* p;
			//최댓값 다음 수부터 최솟값 바로 전 수까지 출력.
			for (p = maxPos + 1; p < minPos; p++) {
				printf("%d ", *p);
			}
		}
		//만약 최댓값이 최솟값보다 뒤에 있다면
		else if (minPos + 1 < maxPos) {
			int* p;
			//최솟값 다음 수부터 최댓값 바로 전 수까지 출력.
			for (p = minPos + 1; p < maxPos; p++) {
				printf("%d ", *p);
			}
		}
		//그 외의 경우(최댓값과 최솟값이 같거나, 최댓값과 최솟값이 붙어있는 경우)에는
		else {
			//none 출력
			printf("none");
		}
		printf("\n");
	}
}
//배열을 인자로 건내받아 그 배열의 최댓값의 주소를 반환하는 함수
int* MAX(int ar[])
{
	//배열 순회용 포인터 변수 p
	int* p;
	//최댓값의 주소가 저장될 변수. 배열의 첫번째 값으로 초기화 시킴.
	int* max = ar;
	for (p = ar; *p != 0; p++) {
		//배열을 순회하며 최댓값보다 큰 수가 나올 경우
		if (*max < *p) {
			//max를 그 수의 주소로 바꾼다.
			max = p;
		}
	}
	//최댓값의 주소 리턴
	return max;
}

//배열의 최솟값의 주소를 반환하는 함수
int* MIN(int ar[])
{
	//배열 순회용 포인터 변수 p
	int* p;
	//최솟값의 주소가 저장될 포인터변수 min. 배열의 주소로 초기화시킴.
	int* min = ar;
	for (p = ar; *p != 0; p++) {
		//반복문을 순회하다가 만약 최솟값보다 작은 값이 나오면
		if (*min > *p) {
			//최솟값의 주소를 바꿔준다.
			min = p;
		}
	}
	return min;
}