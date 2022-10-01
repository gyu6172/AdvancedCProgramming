#include <stdio.h>
#include <string.h>
const char *numToStr(int n);
int main() {
	//problem 3
	//char str[100];
	//scanf("%s",&str);
	//int i,j;
	//int len=0;
	//for (i = 0; str[i] != NULL; i++) {
	//	len++;
	//}
	//for (i = 0; i < len; i++) {
	//	printf("%s\n", str);
	//	char a=str[0];
	//	for (j = 0; j < len-1; j++) {
	//		str[j] = str[j+1];
	//	}
	//	str[j] = a;
	//	
	//}



	//problem 4
	//char str1[100],str2[100];
	//scanf("%s",&str1);
	//scanf("%s", &str2);

	//int i;
	//int n=0;
	//for (i = 0; str1[i] != NULL; i++) {
	//	n++;
	//}
	//int chk=1;
	//for (i = 0; i < n; i++) {
	//	if (str1[i] != str2[i] || str2[i]==NULL) {
	//		chk=0;
	//		break;
	//	}
	//}
	//printf("%d %d",n,chk);



	//problem 5
	//char str1[41], str2[21];
	//int index;
	//scanf("%s", &str1);
	//scanf("%s", &str2);
	//scanf("%d", &index);
	//int i,j,k;
	//int str1Len=0,str2Len=0;
	//for (i = 0; str1[i] != NULL; i++) {
	//	str1Len++;
	//}
	//for (i = 0; str2[i] != NULL; i++) {
	//	str2Len++;
	//}
	//for (i = 0; i < str2Len; i++) {
	//	for (j = str1Len+i;j>index;j--) {
	//		str1[j] = str1[j-1];
	//	}
	//}
	//for (i = 0; i < str2Len; i++) {
	//	str1[i+index] = str2[i];
	//}
	//str1Len += str2Len;
	//str1[str1Len] = NULL;
	//printf("%s",str1);



	//problem 6
	//char str1[41], str2[21];
	//int index;
	//int reverse;
	//scanf("%s", &str1);
	//scanf("%s", &str2);
	//scanf("%d", &index);
	//scanf("%d", &reverse);
	//int i, j, k;
	//int str1Len = 0, str2Len = 0;
	//for (i = 0; str1[i] != NULL; i++) {
	//	str1Len++;
	//}
	//for (i = 0; str2[i] != NULL; i++) {
	//	str2Len++;
	//}
	//if (reverse) {
	//	for (i = 0,j=str2Len-1; i<j; i++,j--) {
	//		char a = str2[i];
	//		str2[i] = str2[j];
	//		str2[j] = a;
	//	}
	//}
	//for (i = 0; i < str2Len; i++) {
	//	for (j = str1Len + i; j > index; j--) {
	//		str1[j] = str1[j - 1];
	//	}
	//}
	//for (i = 0; i < str2Len; i++) {
	//	str1[i + index] = str2[i];
	//}
	//str1Len += str2Len;
	//str1[str1Len] = NULL;
	//printf("%s", str1);




	//problem 7
	//int n;
	//scanf("%d",&n);
	//char tho[4]="THO";
	//char hun[4]="HUN";
	//char ten[4]="TEN";
	//while (n!=0) {
	//	if (n / 1000 > 0) {
	//		printf("%s %s ", numToStr(n / 1000),tho);
	//		n = n%1000;
	//	}
	//	else if (n / 100 > 0) {
	//		printf("%s %s ", numToStr(n / 100),hun);
	//		n = n%100;
	//	}
	//	else if (n / 10 > 0) {
	//		printf("%s %s ", numToStr(n / 10),ten);
	//		n = n%10;
	//	}
	//	else {
	//		printf("%s ", numToStr(n));
	//		break;
	//	}
	//}



	//problem 8
	//char str1[50], str2[50], str3[100];
	//int str3Iter=0;
	//int i=0,j;
	//scanf("%s", &str1);
	//scanf("%s", &str2);

	//while (1) {
	//	if (str1[i] > str2[i]) {
	//		for (j=0;str1[j] != NULL;j++){
	//			str3[str3Iter] = str1[j];
	//			str3Iter++;
	//		}
	//		for (j = 0; str2[j] != NULL; j++) {
	//			str3[str3Iter] = str2[j];
	//			str3Iter++;
	//		}
	//		break;
	//	}
	//	else if (str1[i] < str2[i]) {
	//		for (j = 0; str2[j] != NULL; j++) {
	//			str3[str3Iter] = str2[j];
	//			str3Iter++;
	//		}
	//		for (j = 0; str1[j] != NULL; j++) {
	//			str3[str3Iter] = str1[j];
	//			str3Iter++;
	//		}
	//		break;
	//	}
	//	else {
	//		i++;
	//	}
	//}
	//str3[str3Iter] = NULL;
	//printf("%s",str3);


	

	//실습 문제 1
	//char A[51];
	//scanf("%s",&A);
	//int i,j;
	//int num = 0;
	//int chk=0;
	//for (i = 0; A[i] != NULL; i++) {
	//	if ('0' <= A[i] && A[i] <= '9') {
	//		chk=1;
	//		num = num*10+(A[i]-'0');
	//	}
	//	else {
	//		if (chk==1) {
	//			printf("%d\n",num);
	//			num=0;
	//			chk=0;
	//		}
	//	}
	//}
	//if (chk == 1) {
	//	printf("%d\n", num);
	//}



	//실습 문제 2
	//char A[90];
	//char ch='A';
	//int n;
	//scanf("%s",&A);
	//scanf("%d",&n);
	//int i,j;
	//int cnt=0;
	//int ALen = strlen(A);
	//int chk=0;
	//for (i = 0; i < ALen; i++) {
	//	if ('0' <= A[i] && A[i] <= '9') {
	//		if ('0' <= A[i + 1] && A[i + 1] <= '9') {
	//			chk=2;
	//			cnt=(A[i]-'0')*10 + (A[i+1]-'0');
	//			i++;
	//		}
	//		else {
	//			chk=1;
	//			cnt=A[i]-'0';
	//		}
	//		ch = (ch + cnt - 1);
	//		for (j = 0; j < n; j++) {
	//			printf("%c", ch);
	//		}
	//		
	//	}
	//	else {
	//		printf("%c",A[i]);
	//	}
	//}

		char A[90];
	char ch='A';
	int n;
	scanf("%s",A);
	scanf("%d",&n);
	int i,j;
	int cnt=0;
	int ALen = strlen(A);
	int chk=0;
	for (i = 0; i < ALen; i++) {
		if ('1' <= A[i] && A[i] <= '9') {
			if ('0' <= A[i + 1] && A[i + 1] <= '9') {
				chk=2;
				cnt=(A[i]-'0')*10 + (A[i+1]-'0');
				ch = (ch + cnt - 1);

				for (i = 0; i < ALen; i++) {
					if ('1' <= A[i] && A[i] <= '9') {
						for (j = ALen; j > i; j--) {
							A[j + n - chk] = A[j];
						}

						for (j = i; j < i + n; j++) {
							A[j] = ch;
						}
					}
				}
				break;
			}
			else {
				chk=1;
				cnt=A[i]-'0';
				ch = (ch + cnt - 1);

				for (i = 0; i < ALen; i++) {
					if ('1' <= A[i] && A[i] <= '9') {
						for (j = ALen; j > i; j--) {
							A[j + n - chk] = A[j];
						}

						for (j = i; j < i + n; j++) {
							A[j] = ch;
						}
					}
				}
				break;
			}
		}
	}

	//ch = (ch+cnt-1);

	//for (i = 0; i < ALen; i++) {
	//	if ('1' <= A[i] && A[i] <= '9') {
	//		for (j = ALen; j > i; j--) {
	//			A[j+n-chk] = A[j];
	//		}

	//		for (j = i; j < i + n; j++) {
	//			A[j]=ch;
	//		}
	//	}
	//}
	printf("%s\n", A);


}

const char* numToStr(int n)
{
	switch (n) {
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
	}
	
}
