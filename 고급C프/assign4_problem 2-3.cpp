#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	//A, B 문자열 선언
	char A[101], B[101];
	//A와 B 입력
	gets_s(A);
	gets_s(B);

	//A의 공백 개수, B의 공백 개수를 저장할 변수
	int AblankCnt = 0, BblankCnt = 0;
	int i, j, k;		//반복문 순회용 변수
	for (i = 0; i < strlen(A); i++) {
		//A를 돌면서 공백이 있으면
		if (A[i] == ' ') {
			//공백 개수 1증가
			AblankCnt++;
		}
	}
	//B를 돌면서 공백이 있으면
	for (i = 0; i < strlen(B); i++) {
		//공백개수 1 증가
		if (B[i] == ' ') {
			BblankCnt++;
		}
	}

	//A의 단어들과 B의 단어들을 저장할 문자열 배열 선언하고 동적할당 받기
	char** Awords = (char**)malloc(sizeof(char*) * (AblankCnt + 1));
	char** Bwords = (char**)malloc(sizeof(char*) * (BblankCnt + 1));

	//만약 동적할당이 제대로 되지 않았다면
	if (Awords == NULL || Bwords == NULL) {
		printf("Not Enough Memory!");
		//프로그램 종료
		return -1;
	}

	//A를 돌며 현재 단어를 저장할 배열 선언
	char tmpStr[101];
	//tmpStr의 길이
	int tmpIter = 0;
	//A의 단어의 개수
	int AwordsIter = 0;
	for (i = 0; i < strlen(A); i++) {
		//A를 돌면서 공백이 나온다면
		if (A[i] == ' ') {
			//tmpStr 마지막에 널문자 추가함.
			tmpStr[tmpIter++] = NULL;
			//tmpStr의 길이만큼 동적할당 받음
			Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			//동적할당이 제대로 되지 않았다면
			if (Awords[AwordsIter] == NULL) {
				printf("Not Enough Memory!");
				//프로그램 종료
				return -1;
			}
			//동적할당 받은 공간에 단어 저장
			strcpy(Awords[AwordsIter++], tmpStr);
			//tmpStr의 길이 초기화
			tmpIter = 0;
		}
		else {
			//그 외의 경우에는 단어에 A의 문자를 추가함
			tmpStr[tmpIter++] = A[i];
		}
	}
	//A 순회가 끝나면 똑같은 과정을 한 번 더 진행함.
	tmpStr[tmpIter++] = NULL;
	Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Awords[AwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Awords[AwordsIter++], tmpStr);
	tmpIter = 0;

	//A와 같은 방법으로 B도 진행함
	int BwordsIter = 0;
	//B 문자열 순회함
	for (i = 0; i < strlen(B); i++) {
		//만약 공백이 나온다면
		if (B[i] == ' ') {
			//단어 끝에 널문자 추가
			tmpStr[tmpIter++] = NULL;
			//단어의 길이만큼 동적할당 받는다.
			Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			//동적할당이 제대로 되지 않았다면
			if (Bwords[BwordsIter] == NULL) {
				printf("Not Enough Memory!");
				return -1;
			}
			//동적할당 받은 공간에 문자열 복사하여 저장
			strcpy(Bwords[BwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			//그 외의 경우에는 문자 추가
			tmpStr[tmpIter++] = B[i];
		}
	}
	//B 순회가 끝나면 단어를 한 번 더 추가해 준다.
	tmpStr[tmpIter++] = NULL;
	Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Bwords[BwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Bwords[BwordsIter++], tmpStr);
	tmpIter = 0;

	//최종적으로 출력할 단어들이 저장된 문자열의 배열
	//배열의 길이가 저장된 변수
	int resultIter = 0;
	//문자열 배열 동적 할당
	char** resultStr = (char**)malloc(sizeof(char*));
	for (i = 0; i < AwordsIter; i++) {
		for (j = i + 1; j < AwordsIter; j++) {
			//AcombStr1은 Awords[i] 뒤에 Awords[j]를 붙인 것이고,
			//AcombStr2는 Awords[j] 뒤에 Awords[i]를 붙인 것이다.
			char AcombStr1[201], AcombStr2[201];
			//먼저 AcombStr1에 Awords[[i]를 복사하고,
			strcpy(AcombStr1, Awords[i]);
			//그 뒤에 Awords[j]를 붙임.
			strcat(AcombStr1, Awords[j]);

			//같은 방법으로 AcombStr2에는 Awords[j]를 복사하고, 그 뒤에 Awords[i]를 붙임.
			strcpy(AcombStr2, Awords[j]);
			strcat(AcombStr2, Awords[i]);

			//B의 단어들이 저장된 배열을 쭉 순회함.
			for (k = 0; k < BwordsIter; k++) {
				//만약 AcombStr1이나 AcombStr2와 똑같은 단어가 있다면
				if (strcmp(AcombStr1, Bwords[k]) == 0 || strcmp(AcombStr2, Bwords[k]) == 0) {
					//그 단어를 resultStr에 넣어야함.
					//문자열 배열의 크기를 모르기 때문에 realloc으로 다시 할당해준다.
					//resultIter+1의 크기만큼 다시 할당해준다.
					resultStr = (char**)realloc(resultStr, sizeof(char*)*(resultIter+1));
					//동적할당이 제대로 되지 않았을 경우
					if (resultStr == NULL) {
						printf("Not Enough Memory");
						//프로그램 종료
						return -1;
					}
					//문자배열 메모리 동적할당(Bwords[k]의 길이+1 만큼)
					resultStr[resultIter] = (char*)malloc(sizeof(char)*(strlen(Bwords[k])+1));
					//동적할당이 제대로 되지 않았을 경우
					if (resultStr[resultIter] == NULL) {
						printf("Not Enough Memory");
						//프로그램 종료
						return -1;
					}
					//동적할당 한 공간에 문자열을 넣어준다.
					strcpy(resultStr[resultIter++], Bwords[k]);
				}
			}

		}
	}


	//문자열의 길이가 긴 순서대로 정렬하는 코드
	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			//j보다 j+1이 길면 서로 스왑(버블 정렬)
			if (strlen(resultStr[i]) < strlen(resultStr[j])) {
				char tmpStr1[101];
				strcpy(tmpStr1, resultStr[i]);
				strcpy(resultStr[i], resultStr[j]);
				strcpy(resultStr[j], tmpStr1);
			}
		}
	}

	//문자열의 길이가 같을 때는 사전 순서대로 정렬해야함.
	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			//문자열의 길이가 같고
			if (strlen(resultStr[i]) == strlen(resultStr[j])) {
				//j보다 j+1이 사전 순으로 빠르다면
				if (strcmp(resultStr[i], resultStr[j]) > 0) {
					//서로 스왑(버블정렬)
					char tmpStr1[101];
					strcpy(tmpStr1, resultStr[i]);
					strcpy(resultStr[i], resultStr[j]);
					strcpy(resultStr[j], tmpStr1);
				}
			}
		}
	}

	//만약 똑같은 값이 있어도 한 번만 출력해야 함.
	for (i = 0; i < resultIter; i++) {
		//i가 0일 때는 그냥 출력하고
		if (i == 0) {
			printf("%s\n", resultStr[i]);
		}
		//그 외의 경우에는 이전 인덱스의 문자열하고 다를 때만 출력
		else if (strcmp(resultStr[i], resultStr[i - 1])!=0) {
			printf("%s\n", resultStr[i]);
		}
	}

	//메모리 할당 해제
	//resultStr 메모리 할당 해제
	for (i = 0; i < resultIter; i++) {
		free(resultStr[i]);
	}
	free(resultStr);
	//Awords 메모리 할당 해제
	for (i = 0; i < AwordsIter; i++) {
		free(Awords[i]);
	}
	free(Awords);
	//Bwords 메모리 할당 해제
	for (i = 0; i < BwordsIter; i++) {
		free(Bwords[i]);
	}
	free(Bwords);


}