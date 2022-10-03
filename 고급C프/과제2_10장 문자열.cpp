#include <stdio.h>
#include <string.h>
int s_check(char *p, char *q);
//char *changeArr(char str[], int n);
int main() {


	//problem 1-1
	//char str[21];
	//int n;
	//gets_s(str);
	//scanf("%d",&n);
	//char newstr[201];
	//int newiter = 0;
	//int i, j;
	//int len = strlen(str);
	//for (i = 0; i < len; i++) {
	//	if ('a' <= str[i] && str[i] <= 'z') {
	//		newstr[newiter] = str[i] - n;
	//		newiter++;
	//	}
	//	else if ('a' <= str[i] && str[i] <= 'z') {
	//		newstr[newiter] = str[i] + n;
	//		newiter++;
	//	}
	//	else if ('0' <= str[i] && str[i] <= '9') {
	//		int num = str[i] - '0';
	//		if ('0' <= str[i + 1] && str[i + 1] <= '9') {
	//			num = num * 10 + str[i + 1] - '0';
	//			i++;
	//		}
	//		for (j = 0; j < n; j++) {
	//			newstr[newiter] = 'a' + num - 1;
	//			newiter++;
	//		}
	//	}
	//	else {
	//		newstr[newiter] = ' ';
	//		newiter++;
	//	}
	//}
	//newstr[newiter] = NULL;
	//printf("%s",newstr);





	//problem 1-2
	//char A[21], B[21], C[201];
	//int Citer=0;
	//gets_s(A);
	//gets_s(B);
	//int Alen = strlen(A);
	//int Blen = strlen(B);
	//int i,j,k;
	//if ('a' <= A[0] && A[0] <= 'z') {
	//	if (A[0] < B[0]) {
	//		int n = B[0] - A[0];
	//		int chk;
	//		for (i = 0; i < Blen; i++) {
	//			if ('a' <= B[i] && B[i] <= 'z') {
	//				C[Citer] = B[i] - n;
	//				Citer++;
	//			}
	//			else if ('A' <= B[i] && B[i] <= 'Z') {
	//				C[Citer] = B[i] + n;
	//				Citer++;
	//			}
	//			else if ('0' <= B[i] && B[i] <= '9') {
	//				int num = B[i] - '0';
	//				if ('0' <= B[i + 1] && B[i + 1] <= '9') {
	//					num = num * 10 + B[i + 1] - '0';
	//					i++;
	//				}
	//				for (j = 0; j < n; j++) {
	//					C[Citer] = 'A' + num - 1;
	//					Citer++;
	//				}
	//			}
	//			else {
	//				C[Citer] = ' ';
	//				Citer++;
	//			}
	//		}
	//	}
	//	else if (A[0] > B[0]) {
	//		int n = A[0] - B[0];
	//		int chk;
	//		for (i = 0; i < Alen; i++) {
	//			if ('a' <= A[i] && A[i] <= 'z') {
	//				C[Citer] = A[i] - n;
	//				Citer++;
	//			}
	//			else if ('A' <= A[i] && A[i] <= 'Z') {
	//				C[Citer] = A[i] + n;
	//				Citer++;
	//			}
	//			else if ('0' <= A[i] && A[i] <= '9') {
	//				int num = A[i] - '0';
	//				if ('0' <= A[i + 1] && A[i + 1] <= '9') {
	//					num = num * 10 + A[i + 1] - '0';
	//					i++;
	//				}
	//				for (j = 0; j < n; j++) {
	//					C[Citer] = 'A' + num - 1;
	//					Citer++;
	//				}
	//			}
	//			else {
	//				C[Citer] = ' ';
	//				Citer++;
	//			}
	//		}
	//	}
	//}
	//else if ('A' <= A[0] && A[0] <= 'Z') {
	//	if (A[0] < B[0]) {
	//		int n = B[0] - A[0];
	//		int chk;
	//		for (i = 0; i < Alen; i++) {
	//			if ('a' <= A[i] && A[i] <= 'z') {
	//				C[Citer] = A[i] - n;
	//				Citer++;
	//			}
	//			else if ('A' <= A[i] && A[i] <= 'Z') {
	//				C[Citer] = A[i] + n;
	//				Citer++;
	//			}
	//			else if ('0' <= A[i] && A[i] <= '9') {
	//				int num = A[i] - '0';
	//				if ('0' <= A[i + 1] && A[i + 1] <= '9') {
	//					num = num * 10 + A[i + 1] - '0';
	//					i++;
	//				}
	//				for (j = 0; j < n; j++) {
	//					C[Citer] = 'A' + num - 1;
	//					Citer++;
	//				}
	//			}
	//			else {
	//				C[Citer] = ' ';
	//				Citer++;
	//			}
	//		}
	//	}
	//	else if (A[0] > B[0]) {
	//		int n = A[0] - B[0];
	//		int chk;
	//		for (i = 0; i < Blen; i++) {
	//			if ('a' <= B[i] && B[i] <= 'z') {
	//				C[Citer] = B[i] - n;
	//				Citer++;
	//			}
	//			else if ('A' <= B[i] && B[i] <= 'Z') {
	//				C[Citer] = B[i] + n;
	//				Citer++;
	//			}
	//			else if ('0' <= B[i] && B[i] <= '9') {
	//				int num = B[i] - '0';
	//				if ('0' <= B[i + 1] && B[i + 1] <= '9') {
	//					num = num * 10 + B[i + 1] - '0';
	//					i++;
	//				}
	//				for (j = 0; j < n; j++) {
	//					C[Citer] = 'A' + num - 1;
	//					Citer++;
	//				}
	//			}
	//			else {
	//				C[Citer] = ' ';
	//				Citer++;
	//			}
	//		}
	//	}
	//}
	//else {
	//	
	//}
	//
	//C[Citer]=NULL;
	//Citer++;
	////printf("A:%s\nB:%s\nC:%s\n",A,B,C);
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
	//strCat½á¾ßÇÔ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//char str[4001], addWord[201], resultArr[4001]="";
	//gets_s(str);
	//gets_s(addWord);
	//char strArr[20][201];
	//int len = strlen(str);
	//int i,j;
	//int x=0,y=0;
	//for (i = 0; i < len; i++) {
	//	if (str[i] == ' ') {
	//		strArr[y][x] = NULL;
	//		x=0;
	//		y++;
	//		continue;
	//	}
	//	strArr[y][x] = str[i];
	//	x++;
	//}
	//strArr[y][x] = NULL;
	//y++;
	//int chk=0;
	//for (i = 0; i < y; i++) {
	//	if (strcmp(addWord, strArr[i]) == 0) {
	//		chk=1;
	//	}
	//}
	//if (!chk) {
	//	strcpy(strArr[y],addWord);
	//	y++;
	//}
	//for (i = 0; i < y; i++) {
	//	printf("%s\n", strArr[i]);
	//}
	//for (i = 0; i < y; i++) {
	//	for (j = i; j < y; j++) {
	//		if (strcmp(strArr[i], strArr[j]) > 0) {
	//			char tmp[21];
	//			strcpy(tmp, strArr[i]);
	//			strcpy(strArr[i], strArr[j]);
	//			strcpy(strArr[j], tmp);
	//		}
	//	}
	//}
	//for (i = 0; i < y; i++) {
	//	strcat(resultArr, strArr[i]);
	//	strcat(resultArr, " ");
	//}
	//printf("%s",resultArr);









	//problem 3-2
	//char str1[101], str2[101];
	//gets_s(str1);
	//gets_s(str2);
	//
	//char strArr[20][201];
	//int len = strlen(str1);
	//int i, j;
	//int x = 0, y = 0;
	//for (i = 0; i < len; i++) {
	//	if (str1[i] == ' ' || str1[i]=='.') {
	//		strArr[y][x] = NULL;
	//		x = 0;
	//		y++;
	//		continue;
	//	}
	//	strArr[y][x] = str1[i];
	//	x++;
	//}
	//strArr[y][x] = NULL;
	//y++;
	//int cnt=0;
	//for (i = 0; i < y; i++) {
	//	if(strcmp(strArr[i], str2)==0)
	//		cnt++;
	//}
	//printf("%d",cnt);








	//problem 4
	int m, k1, k2, i, j, k;
	scanf("%d",&m);
	scanf("%d %d",&k1,&k2);
	getchar();
	for (i = 0; i < m; i++) {
		char str[201];
		char *p, *q;
		gets_s(str);
		p=str+k1;
		q = str+k2;
		if(k2>strlen(str))
			q = str+strlen(str);
		if (s_check(p, q) != 0) {
			printf("%d\n", s_check(p,q));
		}
	}

}

int s_check(char* p, char* q)
{
	int cnt=0;
	char *iter;
	for (iter = p; iter <= q; iter++) {
		if('a'<=*iter && *iter<='z')
			cnt++;
	}
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
