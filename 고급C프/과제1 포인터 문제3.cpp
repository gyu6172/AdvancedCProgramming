#include <stdio.h>
void PRT(int n, char* p);

int main() {
	//문자열이 저장될 변수
	char str[100];
	char* p;
	//반복문을 돌며 입력받음
	for (p = str;; p++) {
		scanf("%c", p);
		//만약 입력받은 문자가 '#'이라면 반복문 탈출하여 입력 그만받음
		if (*p == '#')
			break;
	}
	//단어의 길이가 저장될 변수 cnt
	int cnt = 0;
	//현재 글자가 단어의 첫글자인지 아닌지 확인해주는 변수 chk
	//chk==0이라면 현재 글자가 첫글자이고, 1이라면 첫글자가 아님
	int chk = 0;
	//가장 긴 단어의 길이가 저장될 변수 maxCnt
	int maxCnt = 0;
	//문자열을 순회하며 각 단어의 첫번째 글자 주소가 저장될 포인터 변수 pos
	char* pos;
	//가장 긴단어의 첫글자의 주소가 저장될 포인터 변수 maxPos
	char* maxPos;
	for (p = str;; p++) {
		//문자열의 첫 글자부터 마지막 글자까지 반복문을 돔
		//만약 현재 글자가 소문자라면
		if ('a' <= *p && *p <= 'z') {
			//단어의 길이를 1 증가시킴
			cnt++;
			//현재 글자 출력
			printf("%c", *p);
			//만약 chk가 0이라면
			if (!chk) {
				//chk를 1로 바꿔주고
				chk = 1;
				//pos에 현재 글자의 주소값 저장
				pos = p;
			}
		}
		//현재 글자가 소문자가 아니라면
		else {
			//만약 다음 글자가 소문자라면
			if ('a' <= *(p + 1) && *(p + 1) <= 'z') {
				//줄바꿈
				printf("\n");
			}
			//만약 그 단어의 길이가 최대 길이보다 길다면
			if (cnt > maxCnt) {
				//최대 길이를 그 길이로 바꿔줌.
				maxCnt = cnt;
				//가장 긴 단어의 첫글자 주소를 저장하는 변수에 그 단어의 첫글자 주소를 저장함.
				maxPos = pos;
			}
			//chk와 cnt값을 초기화 시킨다.
			chk = 0;
			cnt = 0;
		}
		//만약 현재 글자가 '#'이라면 반복문 탈출
		if (*p == '#')
			break;
	}
	//가장 긴 단어의 길이와 그 단어의 첫글자를 출력함.
	printf("\n%d %c\n", maxCnt, *maxPos);
	//가장 긴 단어 출력
	PRT(maxCnt, maxPos);
}

//단어의 길이와 첫 글자의 주소를 인자로 건네받아 단어를 출력하는 함수
void PRT(int n, char* p)
{
	//출력용 포인터 변수 q
	char* q;
	//q를 p로 초기화 시키고 n번 반복하며 q가 가리키는 값 출력
	for (q = p; q < p + n; q++) {
		printf("%c", *q);
	}
}