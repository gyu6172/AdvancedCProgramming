#include <stdio.h>
#include <string.h>
int main() {
	//문자열 1이 저장될 str1과 문자열 2가 저장될 str2 선언
	char str1[101], str2[101];
	//str1과 str2 입력받음
	gets_s(str1);
	gets_s(str2);

	//str1의 각 단어가 저장될 2차원 배열 strArr
	char strArr[20][201];
	//str1의 길이 저장
	int len = strlen(str1);
	//반복문 순회용 변수 저장
	int i, j;
	//strArr에 글자 저장할때 사용할 변수 x와 y
	int x = 0, y = 0;
	//str1의 처음부터 끝까지 반복문 순회
	for (i = 0; i < len; i++) {
		//단어는 공백이나 .으로 나뉘어지므로 만약 str1을 순회하다가 공백이나 .을 만나는 경우
		if (str1[i] == ' ' || str1[i] == '.') {
			//strArr의 마지막에 널문자 추가
			strArr[y][x] = NULL;
			//x값 초기화하고 y값 1증가시킴
			x = 0;
			y++;
			continue;
		}
		//공백이나 .을 만나지 않는다면 그냥 strArr에 문자 추가
		strArr[y][x] = str1[i];
		x++;
	}
	//마지막에 널문자 추가해준다.
	strArr[y][x] = NULL;
	y++;
	//일치하는 단어의 개수가 저장될 변수 cnt
	int cnt = 0;
	for (i = 0; i < y; i++) {
		//strArr에 저장된 단어들을 str2와 비교하면서 만약 같다면 cnt 1증가
		if (strcmp(strArr[i], str2) == 0)
			cnt++;
	}
	//최종 cnt출력
	printf("%d", cnt);
}