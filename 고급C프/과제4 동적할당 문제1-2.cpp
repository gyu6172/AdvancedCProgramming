#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ü ����
typedef struct st {
	char *str;		//���ڿ� ����
	int cnt1;		//���� �� ����
	int cnt2;		//�� ���� �� ����
	int num;		//���� ����
	int pos;		//��ġ ����
	int result;		//������� ����
}St;
int main() {
	int n,i,j;		//�ݺ��� ��ȸ�� ���� ����
	scanf("%d",&n);	//n �Է¹���
	St* stArr=(St*)malloc(sizeof(St)*n);	//n��ŭ�� ũ�⸦ ���� ����ü �迭 �����Ҵ�
	if (stArr == NULL) {	//���� �Ҵ��� ���������� ���� �ʾҴٸ�
		printf("Not Enough Memory");	
		return -1;			//���α׷� ����
	}
	//n�� �ݺ��ϸ� ���ڿ� �Է¹���
	for (i = 0; i < n; i++) {
		char str[101];	//�Է¹��� ���ڸ� �����س��� �迭 ����
		getchar();		//���๮�� ����
		scanf("%s",str);	
		int len=strlen(str);	//���ڿ� ���� ����
		stArr[i].str = (char*)malloc(sizeof(char)*(len+1));		//���ڿ��� ����+1 ��ŭ�� �޸� ���� �����Ҵ�
		if (stArr[i].str == NULL) {		//�Ҵ��� ���������� ���� �ʾҴٸ�
			printf("Not Enough Memory");
			return -1;					//���α׷� ����
		}
		strcpy(stArr[i].str, str);		//�Ҵ� ���� ������ �Է¹��� ���ڿ� ����
	}
	//n�� ���鼭 ����ü�� ������ ������ �ʱ�ȭ�Ѵ�.
	for (i = 0; i < n; i++) {
		int moumCnt=0;		//������ ������ ������ ���� ����
		for (j = 0; j < strlen(stArr[i].str); j++) {	//���ڿ��� ó������ ������ Ȯ���ϸ鼭
			//���� ������ ���´ٸ�
			if (stArr[i].str[j] == 'a' || stArr[i].str[j] == 'e' || stArr[i].str[j] == 'i' || stArr[i].str[j] == 'o' || stArr[i].str[j] == 'u'
				|| stArr[i].str[j] == 'A' || stArr[i].str[j] == 'E' || stArr[i].str[j] == 'I' || stArr[i].str[j] == 'O' || stArr[i].str[j] == 'U') {
				moumCnt++;	//������ ���� 1 ����
			}
			//���ڰ� ���´ٸ�
			else if ('0' <= stArr[i].str[j] && stArr[i].str[j] <= '9') {
				stArr[i].num = stArr[i].str[j] - '0';	//����ü�� num���� ���� ����
				stArr[i].pos = j+1;						//�� ������ ��ġ ����
			}
		}
		//���� ���� = ���ڿ� ���� - ���� ���� - 1(����)
		stArr[i].cnt1 = strlen(stArr[i].str) - moumCnt - 1;
		stArr[i].cnt2 = strlen(stArr[i].str);	//cnt2�� ���ڿ��� ���� ����
		stArr[i].result = (stArr[i].cnt1)*(stArr[i].cnt2)*(stArr[i].num)*(stArr[i].pos);	//��� ���ؼ� result�� ����� ����
	}

	//result�� ū ������� �������� ����
	for (i = 0; i < n; i++) {	//i�� 0~n����
		for (j = 0; j < n - i - 1; j++) {	//j�� 0���� n-i-1 ���� ���鼭
			if (stArr[j].result < stArr[j + 1].result) {	//���� j�� result < j+1�� result ���
				//���� ����(��������)
				St tmp = stArr[j];
				stArr[j] = stArr[j+1];
				stArr[j+1] = tmp;
			}
		}
	}

	//���ĵ� ������� ���ڿ� ���
	for (i = 0; i < n; i++) {
		printf("%s\n",stArr[i].str);
	}

	//���ڿ� �޸� �Ҵ� ����
	for (i = 0; i < n; i++) {
		free(stArr[i].str);
	}
	//����ü �迭 �Ҵ� ����
	free(stArr);
}