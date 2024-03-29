#include <stdio.h>
#include <string.h>
int main() {
	//입력받을 A배열과 B배열, 1-1의 규칙대로 바꾼 문자열이 저장될 C 배열 선언
	char A[21], B[21], C[201];
	//C배열의 크기
	int Citer = 0;
	//A와 B 입력받음
	gets_s(A);
	gets_s(B);
	//A와 B의 크기 저장.
	int Alen = strlen(A);
	int Blen = strlen(B);
	//반복문 순회용 변수 미리 선언함
	int i, j, k;

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
	C[Citer] = NULL;
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

}