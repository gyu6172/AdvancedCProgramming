#include <stdio.h>
int* MAX(int ar[]);
int* MIN(int ar[]);
int passengerN(int n);
int changeseat(int* ar);
int* rebooking(int *ar);
void PRT(int n, char* p);
int isEnd(char a);
int main() {

	//problem 1-2
	////줄 수를 입력받을 변수 n 선언
	//int n;
	////줄 수 입력받음
	//scanf("%d",&n);
	//int i,j;
	//
	////n번 반복하며 입력받음.
	//for (i = 0; i < n; i++) {
	//	//입력용 변수 a
	//	int a;
	//	//입력받을 변수가 저장될 배열 arr
	//	int arr[100];
	//	//배열 arr의 크기를 알려주는 변수 arrIter
	//	int arrIter = 0;
	//	while (1) {
	//		//a 입력받음
	//		scanf("%d",&a);
	//		//arr에 a를 넣음
	//		arr[arrIter] = a;
	//		//배열 크기 1증가시킴.
	//		arrIter++;
	//		//만약 0을 입력했다면 break로 반복문 탈출하여 입력을 그만받음
	//		if(a==0)
	//			break;
	//	}
	//	//maxPos와 minPos에는 각각 배열의 최댓값의 주소, 최솟값의 주소가 저장됨.
	//	int *maxPos = MAX(arr);
	//	int *minPos = MIN(arr);
	//	//만약 최솟값이 최댓값보다 뒤에 있다면
	//	if (minPos > maxPos+1) {
	//		int *p;
	//		//최댓값 다음 수부터 최솟값 바로 전 수까지 출력.
	//		for (p = maxPos+1; p < minPos; p++) {
	//			printf("%d ",*p);
	//		}
	//	}
	//	//만약 최댓값이 최솟값보다 뒤에 있다면
	//	else if (minPos+1 < maxPos) {
	//		int* p;
	//		//최솟값 다음 수부터 최댓값 바로 전 수까지 출력.
	//		for (p = minPos + 1; p < maxPos; p++) {
	//			printf("%d ", *p);
	//		}
	//	}
	//	//그 외의 경우(최댓값과 최솟값이 같거나, 최댓값과 최솟값이 붙어있는 경우)에는
	//	else {
	//		//none 출력
	//		printf("none");
	//	}
	//	printf("\n");
	//}




	//problem 2-2
	////승객 수가 저장될 변수 n
	//int n;
	////n 입력받음
	//scanf("%d",&n);
	////배열 순회용 포인터 변수 p 선언
	//int *p;
	////배열 선언. 0으로 다 초기화시킴.
	//int bus[25]={0,};
	//for (p = bus; p < bus+n;p++) {
	//	//배열에 값 입력받음
	//	scanf("%d",p);
	//}
	////passengerN이 -1이라면. 즉, 승객수가 충분하지 않다면
	//if (passengerN(n) == -1) {
	//	//-1을 출력하고
	//	printf("-1");
	//	//프로그램 종료
	//	return 0;
	//}
	////그 외의 경우
	//else {
	//	//0출력
	//	printf("0\n");
	//	//최종 결과가 저장될 배열 arr
	//	int *arr = rebooking(bus);
	//	for (p = arr; p < arr + n; p++) {
	//		//arr의 값을 출력함.
	//		printf("%d ",*p);
	//	}
	//}



	//problem 3
	////문자열이 저장될 변수
	//char str[100];
	//char *p;
	////반복문을 돌며 입력받음
	//for (p = str;; p++) {
	//	scanf("%c",p);
	//	//만약 입력받은 문자가 '#'이라면 반복문 탈출하여 입력 그만받음
	//	if(*p=='#')
	//		break;
	//}
	////단어의 길이가 저장될 변수 cnt
	//int cnt=0;
	////현재 글자가 단어의 첫글자인지 아닌지 확인해주는 변수 chk
	////chk==0이라면 현재 글자가 첫글자이고, 1이라면 첫글자가 아님
	//int chk=0;
	////가장 긴 단어의 길이가 저장될 변수 maxCnt
	//int maxCnt=0;
	////문자열을 순회하며 각 단어의 첫번째 글자 주소가 저장될 포인터 변수 pos
	//char *pos;
	////가장 긴단어의 첫글자의 주소가 저장될 포인터 변수 maxPos
	//char *maxPos;
	//for (p = str;; p++) {
	//	//문자열의 첫 글자부터 마지막 글자까지 반복문을 돔
	//	//만약 현재 글자가 소문자라면
	//	if ('a' <= *p && *p <= 'z') {
	//		//단어의 길이를 1 증가시킴
	//		cnt++;
	//		//현재 글자 출력
	//		printf("%c",*p);
	//		//만약 chk가 0이라면
	//		if (!chk) {
	//			//chk를 1로 바꿔주고
	//			chk=1;
	//			//pos에 현재 글자의 주소값 저장
	//			pos = p;
	//		}
	//	}
	//	//현재 글자가 소문자가 아니라면
	//	else {
	//		//만약 다음 글자가 소문자라면
	//		if ('a' <= *(p+1) && *(p+1) <= 'z') {
	//			//줄바꿈
	//			printf("\n");
	//		}
	//		//만약 그 단어의 길이가 최대 길이보다 길다면
	//		if (cnt > maxCnt) {
	//			//최대 길이를 그 길이로 바꿔줌.
	//			maxCnt = cnt;
	//			//가장 긴 단어의 첫글자 주소를 저장하는 변수에 그 단어의 첫글자 주소를 저장함.
	//			maxPos = pos;
	//		}
	//		//chk와 cnt값을 초기화 시킨다.
	//		chk = 0;
	//		cnt = 0;
	//	}
	//	//만약 현재 글자가 '#'이라면 반복문 탈출
	//	if(*p=='#')
	//		break;
	//}
	////가장 긴 단어의 길이와 그 단어의 첫글자를 출력함.
	//printf("\n%d %c\n",maxCnt,*maxPos);
	////가장 긴 단어 출력
	//PRT(maxCnt, maxPos);




	//problem 4-2
	////배열 선언
	//int a[11], b[11];

	////n과 m선언하고 0으로 초기화
	//int n=0,m=0;

	////포인터 선연
	//int *p=a,*q=b;
	//while (1) {
	//	//입력받을 변수 선언
	//	int a;
	//	scanf("%d", &a);
	//	//그 변수가 -1이면 입력을 그만 받고 반복문 탈출
	//	*p = a;
	//	if (a == -1)
	//		break;
	//	//-1이 아니면 배열에 입력받은 변수 저장
	//	p++;
	//	//n값을 1 증가시킴.
	//	n++;
	//}
	//while (1) {
	//	//이번엔 배열 b에다가 입력받음
	//	int a;
	//	scanf("%d", &a);
	//	*q = a;
	//	if (a == -1)
	//		break;
	//	q++;
	//	//m값 1증가
	//	m++;
	//}
	////n은 배열 a의 길이, m은 배열 b의 길이가 되었다.
	////배열 a를 내림차순으로 정렬해준다.
	//for (p = a; p < a + n; p++) {
	//	for (q = p; q < a + n; q++) {
	//		//내림차순 정렬하는 과정
	//		if (*p < *q) {
	//			int tmp = *p;
	//			*p = *q;
	//			*q = tmp;
	//		}
	//	}
	//}
	////배열 b를 내림차순으로 정렬해준다.
	//for (p = b; p < b + m; p++) {
	//	for (q = p; q < b + m; q++) {
	//		//내림차순 정렬하는 과정
	//		if (*p < *q) {
	//			int tmp = *p;
	//			*p = *q;
	//			*q = tmp;
	//		}
	//	}
	//}
	////포인터 변수 p와 q가 각각 a의 첫번째 원소, b의 두번째 원소를 가리키게함.
	//p = a;
	//q = b;

	////두 포인터 변수가 가리키는 값 중에서 더 큰값을 출력함.
	////이 과정을 n번 반복하면 가장 높은 n개의 값을 출력할 수 있다.
	//for (int i = 0; i < n; i++) {
	//	//만약 p가 가리키는 값이 -1이라면 p는 a의 끝에 도달했다는 뜻이므로
	//	if (*p == -1) {
	//		//q가 가리키고 있는 값을 출력
	//		printf("%d ", *q);
	//		//q를 한칸 뒤로 이동시킨다.
	//		q++;
	//	}
	//	//만약 q가 가리키는 값이 -1이라면 q는 b의 끝에 도달했다는 뜻이므로
	//	else if (*q == -1) {
	//		//p가 가리키고 있는 값을 출력
	//		printf("%d ", *p);
	//		//p를 한칸 뒤로 이동시킴.
	//		p++;
	//	}
	//	//만약 둘 중에 p가 가리키고 있는 값이 더 크다면
	//	else if (*p > *q) {
	//		//p가 가리키고 있는 값 출력
	//		printf("%d ",*p);
	//		//p를 한칸 뒤로 이동시킴.
	//		p++;
	//	}
	//	//그 외의 경우(q가 더 큰 경우)
	//	else {
	//		//q가 가리키고 있는 값 출력
	//		printf("%d ", *q);
	//		//q 한칸 뒤로 이동시킴.
	//		q++;
	//	}
	//}
	//printf("\n");
	////큰 값을 출력했을 때와 같은 방법으로 내림차순 정렬된 배열의 가장 뒤쪽에서부터 출력
	////역시 이 과정을 m번 반복하면 가장 낮은 m개의 값을 출력할 수 있다.
	////p와 q가 각각 배열 a와 배열 b의 가장 마지막 원소를 가리키게함.
	//p = a+n-1;
	//q = b+m-1;
	//for (int i = 0; i < m; i++) {
	//	//p가 맨 처음에 도달했다면 
	//	if (*p == NULL) {
	//		//q를 출력함
	//		printf("%d ", *q);
	//		//q를 한 칸 앞으로 이동시킴.
	//		q--;
	//	}
	//	//q가 맨 처음에 도달했다면
	//	else if (*q == NULL) {
	//		//p를 출력함.
	//		printf("%d ", *p);
	//		//p를 한 칸 앞으로 이동시킴.
	//		p--;
	//	}
	//	//p와 q중 p가 더 작다면
	//	else if (*p < *q) {
	//		//p를 출력하고
	//		printf("%d ", *p);
	//		//p를 한 칸 앞으로 이동시킴.
	//		p--;
	//	}
	//	//그 외의 경우(q가 더 작은 경우)
	//	else {
	//		//q를 출력함
	//		printf("%d ", *q);
	//		//q를 한 칸 앞으로 이동시킴.
	//		q--;
	//	}
	//}



	//problem 5
	//char str[1001];
	//char *p=str;
	//char *q;
	//while (1) {
	//	scanf("%c",p);
	//	if(isEnd(*p)==1)
	//		break;
	//	p++;
	//}
	//char a;
	//for (p = str;; p++) {
	//	if (isEnd(*p)==1) {
	//		a = *p;
	//		break;
	//	}
	//}
	//p--;

	//for (p = p; isEnd(*p)!=1; p--) {
	//	if (isEnd(*p)==2) {
	//		for (q = p + 1;isEnd(*q)==0; q++) {
	//			printf("%c",*q);
	//		}
	//		printf(" ");
	//	}
	//	else if (p == str) {
	//		for (q = p; isEnd(*q) == 0; q++) {
	//			printf("%c", *q);
	//		}
	//		printf("%c",a);
	//	}
	//}
















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

//승객 수에 따라 정수를 반환하는 함수
int passengerN(int n)
{	
	//승객 수가 5보다 작으면 -1 반환
	if (n<5)
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
	int chk[22]={0,};
	int *p;
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
	int *p,*q;
	for (p = ar; *p != 0; p++) {
		//ar을 순회하며 각 좌석이 예약된 횟수를 센다.
		//횟수 저장용 변수 cnt
		int cnt=0;
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

//단어의 길이와 첫 글자의 주소를 인자로 건네받아 단어를 출력하는 함수
void PRT(int n, char* p)
{
	//출력용 포인터 변수 q
	char *q;
	//q를 p로 초기화 시키고 n번 반복하며 q가 가리키는 값 출력
	for (q = p; q < p + n; q++) {
		printf("%c",*q);
	}
}

int isEnd(char a)
{
	if (a == '!' || a == '?' || a == '.') {
		return 1;
	}
	else if(a==' ')
		return 2;
	else {
		return 0;
	}
}
