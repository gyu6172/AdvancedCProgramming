#include <stdio.h>
#include <string.h>
int main() {
	//problem 1
	//char A[21], B[21], C[201];
	//int Citer=0;
	//gets_s(A);
	//gets_s(B);
	//int Alen = strlen(A);
	//int Blen = strlen(B);
	//int i,j,k;
	//if (A[0] < B[0]) {
	//	int n = B[0] - A[0];
	//	int chk;
	//	for (i = 0; i < Alen; i++) {
	//		if ('a' <= A[i] && A[i] <= 'z') {
	//			C[Citer] = A[i]-n;
	//			Citer++;
	//		}
	//		else if ('A' <= A[i] && A[i] <= 'Z') {
	//			C[Citer] = A[i] + n;
	//			Citer++;
	//		}
	//		else if ('0' <= A[i] && A[i] <= '9') {
	//			int num = A[i]-'0';
	//			if ('0' <= A[i+1] && A[i+1] <= '9') {
	//				num = num*10 + A[i+1]-'0';
	//				i++;
	//			}
	//			for (j = 0; j < n; j++) {
	//				C[Citer] = 'A'+num-1;
	//				Citer++;
	//			}
	//		}
	//		else {
	//			C[Citer] = ' ';
	//			Citer++;
	//		}
	//	}
	//}
	//else if (A[0] > B[0]) {
	//	int n = A[0] - B[0];
	//	int chk;
	//	for (i = 0; i < Blen; i++) {
	//		if ('a' <= B[i] && B[i] <= 'z') {
	//			C[Citer] = B[i] - n;
	//			Citer++;
	//		}
	//		else if ('A' <= B[i] && B[i] <= 'Z') {
	//			C[Citer] = B[i] + n;
	//			Citer++;
	//		}
	//		else if ('0' <= B[i] && B[i] <= '9') {
	//			int num = B[i] - '0';
	//			if ('0' <= B[i + 1] && B[i + 1] <= '9') {
	//				num = num * 10 + B[i + 1] - '0';
	//			}
	//			for (j = 0; j < n; j++) {
	//				C[Citer] = 'A' + num - 1;
	//				Citer++;
	//			}
	//		}
	//		else {
	//			C[Citer] = ' ';
	//			Citer++;
	//		}
	//	}
	//}
	//C[Citer]=NULL;
	//Citer++;
	//printf("A:%s\nB:%s\nC:%s\n",A,B,C);
	//if (strcmp(A, C) == 0) {
	//	printf("2");
	//}
	//else if (strcmp(B, C) == 0) {
	//	printf("1");
	//}
	//else {
	//	printf("0");
	//}




	//problem 2-2

	char str[4001], addWord[201];
	int sortArr[20][1];
	gets_s(str);
	//gets_s(addWord);
	char strArr[20][201];
	int len = strlen(str);
	int i,j;
	int x=0,y=0;
	for (i = 0; i < len; i++) {
		if (str[i] == ' ') {
			strArr[y][x] = NULL;
			x=0;
			y++;
			continue;
		}
		strArr[y][x] = str[i];
		x++;
	}
	strArr[y][x] = NULL;
	y++;
	for (i = 0; i < y; i++) {
		printf("%s\n",strArr[i]);
	}
	for (i = 0; i < y; i++) {
		for (j = i; j < y; j++) {
			if (strcmp(strArr[i], strArr[j]) < 0) {
				
			}
		}
	}


	



}