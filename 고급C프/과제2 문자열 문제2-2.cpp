#include <stdio.h>
#include <string.h>
int main() {
	//공백을 포함한 문자열이 저장될 배열 str, 새롭게 입력받을 단어가 저장될 배열 addWord, 최종으로 출력할 배열 resultArr
	char str[4001], addWord[201], resultArr[4001] = "";
	//str과 addWord 입력받음.
	gets_s(str);
	gets_s(addWord);
	//str을 단어 단위로 분리하여 2차원 배열인 strArr에 저장함.
	char strArr[20][201];
	//str의 길이 저장
	int len = strlen(str);
	//반복문 순회용 변수 미리 선언
	int i, j;
	//strArr에 문자열을 저장할 때 사용할 변수 x와 y
	int x = 0, y = 0;
	//str의 첫 글자부터 마지막 글자까지 순회 돎.
	for (i = 0; i < len; i++) {
		//만약 공백이 나왔다면,
		if (str[i] == ' ') {
			//그 단어의 마지막에 널문자 추가하고,
			strArr[y][x] = NULL;
			//x를 0으로 초기화 시키고 y 1증가시킴.
			x = 0;
			y++;
			continue;
		}
		//공백이 나오지 않았다면 2차원 배열에 글자 저장.
		strArr[y][x] = str[i];
		x++;
	}
	//마지막에 널문자 추가해줌.
	strArr[y][x] = NULL;
	y++;
	//새로 입력받은 단어가 2차원 배열에 있는지 없는지 알려줄 변수
	int chk = 0;
	//strArr를 순회하며
	for (i = 0; i < y; i++) {
		//만약 addWord와 동일한 단어가 strArr에 있다면, chk를 1로 바꿈
		if (strcmp(addWord, strArr[i]) == 0) {
			chk = 1;
		}
	}
	//만약 chk가 0이라면, 즉 strArr에 addWord가 없다면,
	if (!chk) {
		//strArr 마지막에 addWord를 추가해준다.
		strcpy(strArr[y], addWord);
		y++;
	}
	//strArr출력
	for (i = 0; i < y; i++) {
		printf("%s\n", strArr[i]);
	}
	//사전순대로 정렬하는 코드
	//strcmp(s1,s2)는 s1>s2이면 1, s1==s2이면 0, s1<s2이면 -1을 반환함.
	for (i = 0; i < y; i++) {
		for (j = i; j < y; j++) {
			//strArr[i] > strArr[j] 라면, 두 단어의 위치를 바꿔준다.
			if (strcmp(strArr[i], strArr[j]) > 0) {
				char tmp[21];
				strcpy(tmp, strArr[i]);
				strcpy(strArr[i], strArr[j]);
				strcpy(strArr[j], tmp);
			}
		}
	}
	//최종으로 출력할 문자열 맨 뒤에 strArr의 각 단어들을 이어붙이고, 공백도 같이 붙임
	for (i = 0; i < y; i++) {
		strcat(resultArr, strArr[i]);
		strcat(resultArr, " ");
	}
	//최종 결과값 출력
	printf("%s", resultArr);
}