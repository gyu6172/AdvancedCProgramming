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
	//�Է¹��� A�迭�� B�迭, 1-1�� ��Ģ��� �ٲ� ���ڿ��� ����� C �迭 ����
	char A[21], B[21], C[201];
	//C�迭�� ũ��
	int Citer=0;
	//A�� B �Է¹���
	gets_s(A);
	gets_s(B);
	//A�� B�� ũ�� ����.
	int Alen = strlen(A);
	int Blen = strlen(B);
	//�ݺ��� ��ȸ�� ���� �̸� ������
	int i,j,k;

	//1-1�� ��Ģ��, �빮���� ��� n��ŭ �ڷ�, �ҹ��ڴ� n��ŭ ������ ����.
	//��, A�� B�� ù ���� �� ���� �� ū��, �� �ҹ������� �빮�������� ����
	//A->B���� B->A���� ������.

	//A�� ù���ڰ� �ҹ����� ���
	if ('a' <= A[0] && A[0] <= 'z') {
		//���� A�� ù���ں��� B�� ù���ڰ� �ڿ� �ִٸ�, B->A�� ����̴�.
		if (A[0] < B[0]) {
			//B�� ù ���ڰ� A�� ù ���ں��� �ڿ� �����Ƿ� B���� A�� ���� n�� �������ش�.
			int n = B[0] - A[0];
			//B���ڿ��� ù ���ں��� ������ ���ڱ��� �ݺ��� ��ȸ�Ѵ�.
			for (i = 0; i < Blen; i++) {
				//���� �ҹ��ڶ��
				if ('a' <= B[i] && B[i] <= 'z') {
					//C�迭�� n��ŭ �տ� �ִ� ���� ����.
					C[Citer] = B[i] - n;
					//�迭 ũ�� 1 ������Ŵ.
					Citer++;
				}
				//���� �빮�ڶ��
				else if ('A' <= B[i] && B[i] <= 'Z') {
					//C�迭�� n��ŭ �ڿ� �ִ� ���� ����.
					C[Citer] = B[i] + n;
					//�迭 ũ�� 1 ������Ŵ.
					Citer++;
				}
				//���� ���ڶ��
				else if ('0' <= B[i] && B[i] <= '9') {
					//num�� ������ ��ȯ�ؼ� ����
					int num = B[i] - '0';
					//���� �� ���� ���ڵ� ���ڶ��
					if ('0' <= B[i + 1] && B[i + 1] <= '9') {
						//num�� 10�� �����ְ� ���� ���� ������ ��ȯ�ؼ� �����ش�.
						num = num * 10 + B[i + 1] - '0';
						//i�� B���ڿ��� ��ȸ�ϴ� �����ε� ���� ���ڸ� �̸� üũ���־����Ƿ� i���� 1 ������Ŵ.
						i++;
					}
					//num��°�� �ִ� ���� �빮�ڸ� C�迭�� n�� �־��ش�.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//�� ���� ��쿡�� ������ �ٲ�.
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
		//A�� ù ���ڰ� B�� ù ���ں��� �ڿ� �ִ� ���, A->B�� ����̴�.
		else if (A[0] > B[0]) {
			//���� ������� n�� �������ش�.
			int n = A[0] - B[0];
			//���� ������� C�迭�� A�迭�� ��ȸ�ϸ� ���ڵ��� �߰����ش�.
			for (i = 0; i < Alen; i++) {
				//���� �ҹ��ڶ��
				if ('a' <= A[i] && A[i] <= 'z') {
					//C�迭�� n��ŭ �տ� �ִ� �ҹ��ڸ� �߰����ش�.
					C[Citer] = A[i] - n;
					Citer++;
				}
				//���� �빮�ڶ��
				else if ('A' <= A[i] && A[i] <= 'Z') {
					//C�迭�� n��ŭ �ڿ� �ִ� �빮�ڸ� �߰����ش�.
					C[Citer] = A[i] + n;
					Citer++;
				}
				//���� ���ڶ��
				else if ('0' <= A[i] && A[i] <= '9') {
					//ù���ڸ� ������ ��ȯ���ش�.
					int num = A[i] - '0';
					//���� �������ڵ� ���ڶ��
					if ('0' <= A[i + 1] && A[i + 1] <= '9') {
						//������ ���ڸ����� ��ȯ���ش�.
						num = num * 10 + A[i + 1] - '0';
						//i�� ���� ��ȸ�� ���ڸ� �� �˻����� �ʵ��� i�� 1 ������Ŵ
						i++;
					}
					//C�迭�� num��° �빮�ڸ� n�� �߰����ش�.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//�� �̿��� ��쿡��
				else {
					//������ �߰����ش�.
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
	}
	//���� A�� ù���ڰ� �빮�ڶ��
	else if ('A' <= A[0] && A[0] <= 'Z') {
		//���� A�� ù���ں��� B�� ù���ڰ� �ڿ� �ִٸ�, A->B�� ����̴�.
		if (A[0] < B[0]) {
			//���� ������� n�� �̾Ƴ���.
			int n = B[0] - A[0];
			//���� ������� C�迭�� A�迭�� ��ȸ�ϸ� ���ڵ��� �߰����ش�.
			for (i = 0; i < Alen; i++) {
				//���� �ҹ��ڶ��
				if ('a' <= A[i] && A[i] <= 'z') {
					//C�迭�� n��ŭ �տ� �ִ� �ҹ��ڸ� �߰����ش�.
					C[Citer] = A[i] - n;
					Citer++;
				}
				//���� �빮�ڶ��
				else if ('A' <= A[i] && A[i] <= 'Z') {
					//C�迭�� n��ŭ �ڿ� �ִ� �빮�ڸ� �߰����ش�.
					C[Citer] = A[i] + n;
					Citer++;
				}
				//���� ���ڶ��
				else if ('0' <= A[i] && A[i] <= '9') {
					//���ڸ� ������ ��ȯ����
					int num = A[i] - '0';
					//���� ���ڵ� ���ڶ��
					if ('0' <= A[i + 1] && A[i + 1] <= '9') {
						//���ڸ����� �ٲ���
						num = num * 10 + A[i + 1] - '0';
						i++;
					}
					//num��°�� �ִ� ���ڸ� n�� �߰����ش�.
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//�� �̿��ǰ���� ������ �߰�
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
		//���� A�� ù���ڰ� B�� ù���ں��� �ڿ� �ִ� �����, B->A�� ����̴�.
		else if (A[0] > B[0]) {
			//n�� ����
			int n = A[0] - B[0];
			//���� ������� C�迭�� B�迭�� ��ȸ�ϸ� ���ڵ��� �߰����ش�.
			for (i = 0; i < Blen; i++) {
				//���� �ҹ��ڶ��
				if ('a' <= B[i] && B[i] <= 'z') {
					//C�迭�� n��ŭ �տ� �ִ� ���� �߰�
					C[Citer] = B[i] - n;
					Citer++;
				}
				//���� �빮�ڶ��
				else if ('A' <= B[i] && B[i] <= 'Z') {
					//C�迭�� n��ŭ �ڿ� �ִ� ���� �߰�
					C[Citer] = B[i] + n;
					Citer++;
				}
				//���� ���ڶ��
				else if ('0' <= B[i] && B[i] <= '9') {
					//���ڸ� ������ �ٲ���
					int num = B[i] - '0';
					//���ڸ����� ���ڸ����� �ٲ���
					if ('0' <= B[i + 1] && B[i + 1] <= '9') {
						num = num * 10 + B[i + 1] - '0';
						i++;
					}
					//num��°�� �ִ� ���ڸ� n�� �־���
					for (j = 0; j < n; j++) {
						C[Citer] = 'A' + num - 1;
						Citer++;
					}
				}
				//�� �̿��� ���� �������� �ٲ���
				else {
					C[Citer] = ' ';
					Citer++;
				}
			}
		}
	}
	//C�� �������� �ι��� �߰����ش�.
	C[Citer]=NULL;
	Citer++;
	//���� A�� C�� ���ٸ�, �� B->A���
	if (strcmp(A, C) == 0) {
		//2 ���
		printf("2");
	}
	//���� B�� C�� ���ٸ�, �� A->B���
	else if (strcmp(B, C) == 0) {
		//1 ���
		printf("1");
	}
	//�� ���� ��쿡�� 0 ���
	else {
		printf("0");
	}








	//problem 2-2
	////������ ������ ���ڿ��� ����� �迭 str, ���Ӱ� �Է¹��� �ܾ ����� �迭 addWord, �������� ����� �迭 resultArr
	//char str[4001], addWord[201], resultArr[4001]="";
	////str�� addWord �Է¹���.
	//gets_s(str);
	//gets_s(addWord);
	////str�� �ܾ� ������ �и��Ͽ� 2���� �迭�� strArr�� ������.
	//char strArr[20][201];
	////str�� ���� ����
	//int len = strlen(str);
	////�ݺ��� ��ȸ�� ���� �̸� ����
	//int i,j;
	////strArr�� ���ڿ��� ������ �� ����� ���� x�� y
	//int x=0,y=0;
	////str�� ù ���ں��� ������ ���ڱ��� ��ȸ ��.
	//for (i = 0; i < len; i++) {
	//	//���� ������ ���Դٸ�,
	//	if (str[i] == ' ') {
	//		//�� �ܾ��� �������� �ι��� �߰��ϰ�,
	//		strArr[y][x] = NULL;
	//		//x�� 0���� �ʱ�ȭ ��Ű�� y 1������Ŵ.
	//		x=0;
	//		y++;
	//		continue;
	//	}
	//	//������ ������ �ʾҴٸ� 2���� �迭�� ���� ����.
	//	strArr[y][x] = str[i];
	//	x++;
	//}
	////�������� �ι��� �߰�����.
	//strArr[y][x] = NULL;
	//y++;
	////���� �Է¹��� �ܾ 2���� �迭�� �ִ��� ������ �˷��� ����
	//int chk=0;
	////strArr�� ��ȸ�ϸ�
	//for (i = 0; i < y; i++) {
	//	//���� addWord�� ������ �ܾ strArr�� �ִٸ�, chk�� 1�� �ٲ�
	//	if (strcmp(addWord, strArr[i]) == 0) {
	//		chk=1;
	//	}
	//}
	////���� chk�� 0�̶��, �� strArr�� addWord�� ���ٸ�,
	//if (!chk) {
	//	//strArr �������� addWord�� �߰����ش�.
	//	strcpy(strArr[y],addWord);
	//	y++;
	//}
	////strArr���
	//for (i = 0; i < y; i++) {
	//	printf("%s\n", strArr[i]);
	//}
	////��������� �����ϴ� �ڵ�
	////strcmp(s1,s2)�� s1>s2�̸� 1, s1==s2�̸� 0, s1<s2�̸� -1�� ��ȯ��.
	//for (i = 0; i < y; i++) {
	//	for (j = i; j < y; j++) {
	//		//strArr[i] > strArr[j] ���, �� �ܾ��� ��ġ�� �ٲ��ش�.
	//		if (strcmp(strArr[i], strArr[j]) > 0) {
	//			char tmp[21];
	//			strcpy(tmp, strArr[i]);
	//			strcpy(strArr[i], strArr[j]);
	//			strcpy(strArr[j], tmp);
	//		}
	//	}
	//}
	////�������� ����� ���ڿ� �� �ڿ� strArr�� �� �ܾ���� �̾���̰�, ���鵵 ���� ����
	//for (i = 0; i < y; i++) {
	//	strcat(resultArr, strArr[i]);
	//	strcat(resultArr, " ");
	//}
	////���� ����� ���
	//printf("%s",resultArr);









	//problem 3-2
	////���ڿ� 1�� ����� str1�� ���ڿ� 2�� ����� str2 ����
	//char str1[101], str2[101];
	////str1�� str2 �Է¹���
	//gets_s(str1);
	//gets_s(str2);
	//
	////str1�� �� �ܾ ����� 2���� �迭 strArr
	//char strArr[20][201];
	////str1�� ���� ����
	//int len = strlen(str1);
	////�ݺ��� ��ȸ�� ���� ����
	//int i, j;
	////strArr�� ���� �����Ҷ� ����� ���� x�� y
	//int x = 0, y = 0;
	////str1�� ó������ ������ �ݺ��� ��ȸ
	//for (i = 0; i < len; i++) {
	//	//�ܾ�� �����̳� .���� ���������Ƿ� ���� str1�� ��ȸ�ϴٰ� �����̳� .�� ������ ���
	//	if (str1[i] == ' ' || str1[i]=='.') {
	//		//strArr�� �������� �ι��� �߰�
	//		strArr[y][x] = NULL;
	//		//x�� �ʱ�ȭ�ϰ� y�� 1������Ŵ
	//		x = 0;
	//		y++;
	//		continue;
	//	}
	//	//�����̳� .�� ������ �ʴ´ٸ� �׳� strArr�� ���� �߰�
	//	strArr[y][x] = str1[i];
	//	x++;
	//}
	////�������� �ι��� �߰����ش�.
	//strArr[y][x] = NULL;
	//y++;
	////��ġ�ϴ� �ܾ��� ������ ����� ���� cnt
	//int cnt=0;
	//for (i = 0; i < y; i++) {
	//	//strArr�� ����� �ܾ���� str2�� ���ϸ鼭 ���� ���ٸ� cnt 1����
	//	if(strcmp(strArr[i], str2)==0)
	//		cnt++;
	//}
	////���� cnt���
	//printf("%d",cnt);








	//problem 4
	//m�� k1,k2, �ݺ��� ��ȸ�� ���� ����
	//int m, k1, k2, i, j;
	////m�Է¹���
	//scanf("%d",&m);
	////k1�� k2�Է¹���
	//scanf("%d %d",&k1,&k2);
	////���ۿ� �����ִ� ���๮�� ����
	//getchar();
	////m�� ���ڿ��� �ݺ��ؼ� �Է¹���.
	//for (i = 0; i < m; i++) {
	//	//�Է¹��� ���ڰ� ����� ���� str
	//	char str[201];
	//	//�Լ��� �ѱ� �����ͺ��� ����
	//	char *p, *q;
	//	//str�Է¹���
	//	gets_s(str);
	//	//p�� q�ʱ�ȭ
	//	p=str+k1;
	//	q = str+k2;
	//	//���� k2�� str�� ���̺��� ��ٸ�
	//	if(k2>strlen(str))
	//		//q�� str�� ������ ���ڸ� ����Ű������.
	//		q = str+strlen(str);
	//	//s_chkeck�� ��ȯ���� 0�̸� ��¿��� �����ؾ���
	//	if (s_check(p, q) != 0) {
	//		//0�� �ƴ� ��� ����Ѵ�.
	//		printf("%d\n", s_check(p,q));
	//	}
	//}

}

int s_check(char* p, char* q)
{
	//�ҹ����� ������ ����� ���� cnt
	int cnt=0;
	//�ݺ��� ��ȸ�� �����ͺ��� iter
	char *iter;
	//p���� q����(q����) �ݺ��� ��ȸ��.
	for (iter = p; iter <= q; iter++) {
		//���� iter�� ����Ű�� ���ڰ� �ҹ��ڶ�� cnt 1������Ŵ
		if('a'<=*iter && *iter<='z')
			cnt++;
	}
	//cnt�� ��ȯ
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
