#include <stdio.h>
#include <string.h>
int s_check(char* p, char* q);

int main() {
	//m과 k1, k2, 반복문 순회용 변수 선언
	int m, k1, k2, i, j;
	//m입력받음
	scanf("%d", &m);
	//k1과 k2입력받음
	scanf("%d %d", &k1, &k2);
	//버퍼에 남아있는 개행문자 제거
	getchar();
	//m번 문자열을 반복해서 입력받음.
	for (i = 0; i < m; i++) {
		//입력받을 문자가 저장될 변수 str
		char str[201];
		//함수에 넘길 포인터변수 선언
		char* p, * q;
		//str입력받음
		gets_s(str);
		//p와 q초기화
		p = str + k1;
		q = str + k2;
		//만약 k2가 str의 길이보다 길다면
		if (k2 > strlen(str))
			//q를 str의 마지막 글자를 가리키도록함.
			q = str + strlen(str);
		//s_chkeck의 반환값이 0이면 출력에서 제외해야함
		if (s_check(p, q) != 0) {
			//0이 아닌 경우 출력한다.
			printf("%d\n", s_check(p, q));
		}
	}
}

int s_check(char* p, char* q)
{
	//소문자의 개수가 저장될 변수 cnt
	int cnt = 0;
	//반복문 순회용 포인터변수 iter
	char* iter;
	//p부터 q까지(q포함) 반복문 순회함.
	for (iter = p; iter <= q; iter++) {
		//만약 iter가 가리키는 문자가 소문자라면 cnt 1증가시킴
		if ('a' <= *iter && *iter <= 'z')
			cnt++;
	}
	//cnt값 반환
	return cnt;
}