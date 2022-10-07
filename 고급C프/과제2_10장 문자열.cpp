#include <stdio.h>
#include <string.h>
int s_check(char *p, char *q);
//char *changeArr(char str[], int n);
int main() {


	//problem 1-1
	char str[21];
	int n;
	gets_s(str);
	scanf("%d",&n);
	char newstr[201];
	int newiter = 0;
	int i, j;
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			newstr[newiter] = str[i] - n;
			newiter++;
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			newstr[newiter] = str[i] + n;
			newiter++;
		}
		else if ('0' <= str[i] && str[i] <= '9') {
			int num = str[i] - '0';
			if ('0' <= str[i + 1] && str[i + 1] <= '9') {
				num = num * 10 + str[i + 1] - '0';
				i++;
			}
			for (j = 0; j < n; j++) {
				newstr[newiter] = 'A' + num - 1;
				newiter++;
			}
		}
		else {
			newstr[newiter] = ' ';
			newiter++;
		}
	}
	newstr[newiter] = NULL;
	printf("%s",newstr);





	//problem 1-2
	//입력받을 A배열과 B배열, 1-1의 규칙대로 바꾼 문자열이 저장될 C 배열 선언
	char A[21], B[21], C[201];
	//C배열의 크기
	int Citer=0;
	//A와 B 입력받음
	gets_s(A);
	gets_s(B);
	//A와 B의 크기 저장.
	int Alen = strlen(A);
	int Blen = strlen(B);
	//반복문 순회용 변수 미리 선언함
	int i,j,k;

	//1-1의 규칙은, 대문자의 경우 n만큼 뒤로, 소문자는 n만큼 앞으로 간다.
	//즉, A와 B의 첫 글자 중 누가 더 큰지, 또 소문자인지 대문자인지에 따라서
	//A->B인지 B->A인지 나뉜다.

	//A의 첫글자가 소문자일 경우
	if ('a' <= A[0] && A[0] <= 'z') {
		//만약 A의 첫글자보다 B의 첫글자가 뒤에 있다면, B->A인 경우이다.
		if (A[0] < B[0]) {
			//B의 첫 글자가 A의 첫 글자보다 뒤에 있으므로 B에서 A를 빼서 n을 추출해준다.
			int n = B[0] - A[0];
			//B문자열의 첫 글자부터 마지막 글자까지 반복문 순회한다.
			for (i = 0; i < Blen; i++) {
				//만약 소문자라면
				if ('a' <= B[i] && B[i] <= 'z') {
					//C배열에 n만큼 앞에 있는 문자 저장.
					C[Citer] = B[i] - n;
					//배열 크기 1 증가시킴.
					Citer++;
				}
				//만약 대문자라면
				else if ('A' <= B[i] && B[i] <= 'Z') {
					//C배열에 n만큼 뒤에 있는 문자 저장.
					C[Citer] = B[i] + n;
					//배열 크기 1 증가시킴.
					Citer++;
				}
				//만약 숫자라면
				else if ('0' <= B[i] && B[i] <= '9') {
					//num에 정수로 변환해서 저장
					int num = B[i] - '0';
					//만약 그 다음 문자도 숫자라면
					if ('0' <= B[i + 1] && B[i + 1] <= '9') {
						//num에 10을 곱해주고 다음 문자 정수로 변환해서 더해준다.
						num = num * 10 + B[i + 1] - '0';
						//i는 B문자열을 순회하는 변수인데 다음 문자를 미리 체크해주었으므로 i값을 1 증가시킴.
						i++;
					}
					//num번째에 있는 영어 대문자를 C배열에 n개 넣어준다.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//그 외의 경우에는 공백을 바꿈.
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
		//A의 첫 글자가 B의 첫 글자보다 뒤에 있는 경우, A->B인 경우이다.
		else if (A[0] > B[0]) {
			//같은 방법으로 n을 추출해준다.
			int n = A[0] - B[0];
			//같은 방법으로 C배열에 A배열을 순회하며 문자들을 추가해준다.
			for (i = 0; i < Alen; i++) {
				//만약 소문자라면
				if ('a' <= A[i] && A[i] <= 'z') {
					//C배열에 n만큼 앞에 있는 소문자를 추가해준다.
					C[Citer] = A[i] - n;
					Citer++;
				}
				//만약 대문자라면
				else if ('A' <= A[i] && A[i] <= 'Z') {
					//C배열에 n만큼 뒤에 있는 대문자를 추가해준다.
					C[Citer] = A[i] + n;
					Citer++;
				}
				//만약 숫자라면
				else if ('0' <= A[i] && A[i] <= '9') {
					//첫글자를 정수로 변환해준다.
					int num = A[i] - '0';
					//만약 다음글자도 숫자라면
					if ('0' <= A[i + 1] && A[i + 1] <= '9') {
						//정수를 두자리수로 변환해준다.
						num = num * 10 + A[i + 1] - '0';
						//i가 다음 순회때 숫자를 또 검사하지 않도록 i를 1 증가시킴
						i++;
					}
					//C배열에 num번째 대문자를 n개 추가해준다.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//그 이외의 경우에는
				else {
					//공백을 추가해준다.
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
	}
	//만약 A의 첫글자가 대문자라면
	else if ('A' <= A[0] && A[0] <= 'Z') {
		//만약 A의 첫글자보다 B의 첫글자가 뒤에 있다면, A->B인 경우이다.
		if (A[0] < B[0]) {
			//같은 방법으로 n을 뽑아낸다.
			int n = B[0] - A[0];
			//같은 방법으로 C배열에 A배열을 순회하며 문자들을 추가해준다.
			for (i = 0; i < Alen; i++) {
				//만약 소문자라면
				if ('a' <= A[i] && A[i] <= 'z') {
					//C배열에 n만큼 앞에 있는 소문자를 추가해준다.
					C[Citer] = A[i] - n;
					Citer++;
				}
				//만약 대문자라면
				else if ('A' <= A[i] && A[i] <= 'Z') {
					//C배열에 n만큼 뒤에 있는 대문자를 추가해준다.
					C[Citer] = A[i] + n;
					Citer++;
				}
				//만약 숫자라면
				else if ('0' <= A[i] && A[i] <= '9') {
					//숫자를 정수로 변환해줌
					int num = A[i] - '0';
					//다음 글자도 숫자라면
					if ('0' <= A[i + 1] && A[i + 1] <= '9') {
						//두자리수로 바꿔줌
						num = num * 10 + A[i + 1] - '0';
						i++;
					}
					//num번째에 있는 문자를 n번 추가해준다.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//그 이외의경우라면 공백을 추가
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
		//만약 A의 첫글자가 B의 첫글자보다 뒤에 있는 경우라면, B->A인 경우이다.
		else if (A[0] > B[0]) {
			//n값 추출
			int n = A[0] - B[0];
			//같은 방법으로 C배열에 B배열을 순회하며 글자들을 추가해준다.
			for (i = 0; i < Blen; i++) {
				//만약 소문자라면
				if ('a' <= B[i] && B[i] <= 'z') {
					//C배열에 n만큼 앞에 있는 문자 추가
					C[Citer] = B[i] - n;
					Citer++;
				}
				//만약 대문자라면
				else if ('A' <= B[i] && B[i] <= 'Z') {
					//C배열에 n만큼 뒤에 있는 문자 추가
					C[Citer] = B[i] + n;
					Citer++;
				}
				//만약 숫자라면
				else if ('0' <= B[i] && B[i] <= '9') {
					//숫자를 정수로 바꿔줌
					int num = B[i] - '0';
					//두자리수면 두자리수로 바꿔줌
					if ('0' <= B[i + 1] && B[i + 1] <= '9') {
						num = num * 10 + B[i + 1] - '0';
						i++;
					}
					//num번째에 있는 문자를 n개 넣어줌
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//그 이외의 경우는 공백으로 바꿔줌
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
	}
	//C의 마지막에 널문자 추가해준다.
	C[Citer]=NULL;
	Citer++;
	//만약 A와 C가 같다면, 즉 B->A라면
	if (strcmp(A, C) == 0) {
		//2 출력
		printf("2");
	}
	//만약 B와 C가 같다면, 즉 A->B라면
	else if (strcmp(B, C) == 0) {
		//1 출력
		printf("1");
	}
	//그 외의 경우에는 0 출력
	else {
		printf("0");
	}








	//problem 2-2
	////공백을 포함한 문자열이 저장될 배열 str, 새롭게 입력받을 단어가 저장될 배열 addWord, 최종으로 출력할 배열 resultArr
	//char str[4001], addWord[201], resultArr[4001]="";
	////str과 addWord 입력받음.
	//gets_s(str);
	//gets_s(addWord);
	////str을 단어 단위로 분리하여 2차원 배열인 strArr에 저장함.
	//char strArr[20][201];
	////str의 길이 저장
	//int len = strlen(str);
	////반복문 순회용 변수 미리 선언
	//int i,j;
	////strArr에 문자열을 저장할 때 사용할 변수 x와 y
	//int x=0,y=0;
	////str의 첫 글자부터 마지막 글자까지 순회 돎.
	//for (i = 0; i < len; i++) {
	//	//만약 공백이 나왔다면,
	//	if (str[i] == ' ') {
	//		//그 단어의 마지막에 널문자 추가하고,
	//		strArr[y][x] = NULL;
	//		//x를 0으로 초기화 시키고 y 1증가시킴.
	//		x=0;
	//		y++;
	//		continue;
	//	}
	//	//공백이 나오지 않았다면 2차원 배열에 글자 저장.
	//	strArr[y][x] = str[i];
	//	x++;
	//}
	////마지막에 널문자 추가해줌.
	//strArr[y][x] = NULL;
	//y++;
	////새로 입력받은 단어가 2차원 배열에 있는지 없는지 알려줄 변수
	//int chk=0;
	////strArr를 순회하며
	//for (i = 0; i < y; i++) {
	//	//만약 addWord와 동일한 단어가 strArr에 있다면, chk를 1로 바꿈
	//	if (strcmp(addWord, strArr[i]) == 0) {
	//		chk=1;
	//	}
	//}
	////만약 chk가 0이라면, 즉 strArr에 addWord가 없다면,
	//if (!chk) {
	//	//strArr 마지막에 addWord를 추가해준다.
	//	strcpy(strArr[y],addWord);
	//	y++;
	//}
	////strArr출력
	//for (i = 0; i < y; i++) {
	//	printf("%s\n", strArr[i]);
	//}
	////사전순대로 정렬하는 코드
	////strcmp(s1,s2)는 s1>s2이면 1, s1==s2이면 0, s1<s2이면 -1을 반환함.
	//for (i = 0; i < y; i++) {
	//	for (j = i; j < y; j++) {
	//		//strArr[i] > strArr[j] 라면, 두 단어의 위치를 바꿔준다.
	//		if (strcmp(strArr[i], strArr[j]) > 0) {
	//			char tmp[21];
	//			strcpy(tmp, strArr[i]);
	//			strcpy(strArr[i], strArr[j]);
	//			strcpy(strArr[j], tmp);
	//		}
	//	}
	//}
	////최종으로 출력할 문자열 맨 뒤에 strArr의 각 단어들을 이어붙이고, 공백도 같이 붙임
	//for (i = 0; i < y; i++) {
	//	strcat(resultArr, strArr[i]);
	//	strcat(resultArr, " ");
	//}
	////최종 결과값 출력
	//printf("%s",resultArr);









	//problem 3-2
	////문자열 1이 저장될 str1과 문자열 2가 저장될 str2 선언
	//char str1[101], str2[101];
	////str1과 str2 입력받음
	//gets_s(str1);
	//gets_s(str2);
	//
	////str1의 각 단어가 저장될 2차원 배열 strArr
	//char strArr[20][201];
	////str1의 길이 저장
	//int len = strlen(str1);
	////반복문 순회용 변수 저장
	//int i, j;
	////strArr에 글자 저장할때 사용할 변수 x와 y
	//int x = 0, y = 0;
	////str1의 처음부터 끝까지 반복문 순회
	//for (i = 0; i < len; i++) {
	//	//단어는 공백이나 .으로 나뉘어지므로 만약 str1을 순회하다가 공백이나 .을 만나는 경우
	//	if (str1[i] == ' ' || str1[i]=='.') {
	//		//strArr의 마지막에 널문자 추가
	//		strArr[y][x] = NULL;
	//		//x값 초기화하고 y값 1증가시킴
	//		x = 0;
	//		y++;
	//		continue;
	//	}
	//	//공백이나 .을 만나지 않는다면 그냥 strArr에 문자 추가
	//	strArr[y][x] = str1[i];
	//	x++;
	//}
	////마지막에 널문자 추가해준다.
	//strArr[y][x] = NULL;
	//y++;
	////일치하는 단어의 개수가 저장될 변수 cnt
	//int cnt=0;
	//for (i = 0; i < y; i++) {
	//	//strArr에 저장된 단어들을 str2와 비교하면서 만약 같다면 cnt 1증가
	//	if(strcmp(strArr[i], str2)==0)
	//		cnt++;
	//}
	////최종 cnt출력
	//printf("%d",cnt);








	//problem 4
	//m과 k1,k2, 반복문 순회용 변수 선언
	//int m, k1, k2, i, j;
	////m입력받음
	//scanf("%d",&m);
	////k1과 k2입력받음
	//scanf("%d %d",&k1,&k2);
	////버퍼에 남아있는 개행문자 제거
	//getchar();
	////m번 문자열을 반복해서 입력받음.
	//for (i = 0; i < m; i++) {
	//	//입력받을 문자가 저장될 변수 str
	//	char str[201];
	//	//함수에 넘길 포인터변수 선언
	//	char *p, *q;
	//	//str입력받음
	//	gets_s(str);
	//	//p와 q초기화
	//	p=str+k1;
	//	q = str+k2;
	//	//만약 k2가 str의 길이보다 길다면
	//	if(k2>strlen(str))
	//		//q를 str의 마지막 글자를 가리키도록함.
	//		q = str+strlen(str);
	//	//s_chkeck의 반환값이 0이면 출력에서 제외해야함
	//	if (s_check(p, q) != 0) {
	//		//0이 아닌 경우 출력한다.
	//		printf("%d\n", s_check(p,q));
	//	}
	//}

}

int s_check(char* p, char* q)
{
	//소문자의 개수가 저장될 변수 cnt
	int cnt=0;
	//반복문 순회용 포인터변수 iter
	char *iter;
	//p부터 q까지(q포함) 반복문 순회함.
	for (iter = p; iter <= q; iter++) {
		//만약 iter가 가리키는 문자가 소문자라면 cnt 1증가시킴
		if('a'<=*iter && *iter<='z')
			cnt++;
	}
	//cnt값 반환
	return cnt;
}

//char* changeArr(char str[], int n)
//{
//	int i,j;
//	int len=strlen(str);
//	char newStr[201];
//	int newIter=0;
//	for (i = 0; i < len; i++) {
//		if ('a' <= str[i] && str[i] <= 'z') {
//			newStr[newIter] = str[i] - n;
//			newIter++;
//		}
//		else if ('A' <= str[i] && str[i] <= 'Z') {
//			newStr[newIter] = str[i] + n;
//			newIter++;
//		}
//		else if ('0' <= str[i] && str[i] <= '9') {
//			int num = str[i] - '0';
//			if ('0' <= str[i + 1] && str[i + 1] <= '9') {
//				num = num * 10 + str[i + 1] - '0';
//				i++;
//			}
//			for (j = 0; j < n; j++) {
//				newStr[newIter] = 'A' + num - 1;
//				newIter++;
//			}
//		}
//		else {
//			newStr[newIter] = ' ';
//			newIter++;
//		}
//	}
//	newStr[newIter]=NULL;
//	return newStr;
//}
