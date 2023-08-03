#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//구조체 선언
typedef struct st {
	char *str;		//문자열 저장
	int cnt1;		//자음 수 저장
	int cnt2;		//총 문자 수 저장
	int num;		//숫자 저장
	int pos;		//위치 저장
	int result;		//곱셈결과 저장
}St;
int main() {
	int n,i,j;		//반복문 순회용 변수 선언
	scanf("%d",&n);	//n 입력받음
	St* stArr=(St*)malloc(sizeof(St)*n);	//n만큼의 크기를 가진 구조체 배열 동적할당
	if (stArr == NULL) {	//만약 할당이 정상적으로 되지 않았다면
		printf("Not Enough Memory");	
		return -1;			//프로그램 종료
	}
	//n번 반복하며 문자열 입력받음
	for (i = 0; i < n; i++) {
		char str[101];	//입력받을 문자를 저장해놓을 배열 선언
		getchar();		//개행문자 제거
		scanf("%s",str);	
		int len=strlen(str);	//문자열 길이 저장
		stArr[i].str = (char*)malloc(sizeof(char)*(len+1));		//문자열의 길이+1 만큼의 메모리 공간 동적할당
		if (stArr[i].str == NULL) {		//할당이 정상적으로 되지 않았다면
			printf("Not Enough Memory");
			return -1;					//프로그램 종료
		}
		strcpy(stArr[i].str, str);		//할당 받은 공간에 입력받은 문자열 복사
	}
	//n번 돌면서 구조체의 나머지 값들을 초기화한다.
	for (i = 0; i < n; i++) {
		int moumCnt=0;		//모음의 개수를 저장할 변수 선언
		for (j = 0; j < strlen(stArr[i].str); j++) {	//문자열의 처음부터 끝까지 확인하면서
			//만약 모음이 나온다면
			if (stArr[i].str[j] == 'a' || stArr[i].str[j] == 'e' || stArr[i].str[j] == 'i' || stArr[i].str[j] == 'o' || stArr[i].str[j] == 'u'
				|| stArr[i].str[j] == 'A' || stArr[i].str[j] == 'E' || stArr[i].str[j] == 'I' || stArr[i].str[j] == 'O' || stArr[i].str[j] == 'U') {
				moumCnt++;	//모음의 개수 1 증가
			}
			//숫자가 나온다면
			else if ('0' <= stArr[i].str[j] && stArr[i].str[j] <= '9') {
				stArr[i].num = stArr[i].str[j] - '0';	//구조체의 num값에 숫자 저장
				stArr[i].pos = j+1;						//그 숫자의 위치 저장
			}
		}
		//자음 개수 = 문자열 길이 - 모음 개수 - 1(숫자)
		stArr[i].cnt1 = strlen(stArr[i].str) - moumCnt - 1;
		stArr[i].cnt2 = strlen(stArr[i].str);	//cnt2에 문자열의 길이 저장
		stArr[i].result = (stArr[i].cnt1)*(stArr[i].cnt2)*(stArr[i].num)*(stArr[i].pos);	//모두 곱해서 result에 결과값 저장
	}

	//result가 큰 순서대로 내림차순 정렬
	for (i = 0; i < n; i++) {	//i는 0~n까지
		for (j = 0; j < n - i - 1; j++) {	//j는 0부터 n-i-1 까지 돌면서
			if (stArr[j].result < stArr[j + 1].result) {	//만약 j의 result < j+1의 result 라면
				//서로 스왑(버블정렬)
				St tmp = stArr[j];
				stArr[j] = stArr[j+1];
				stArr[j+1] = tmp;
			}
		}
	}

	//정렬된 순서대로 문자열 출력
	for (i = 0; i < n; i++) {
		printf("%s\n",stArr[i].str);
	}

	//문자열 메모리 할당 해제
	for (i = 0; i < n; i++) {
		free(stArr[i].str);
	}
	//구조체 배열 할당 해젠
	free(stArr);
}