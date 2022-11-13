#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	//A, B ���ڿ� ����
	char A[101], B[101];
	//A�� B �Է�
	gets_s(A);
	gets_s(B);

	//A�� ���� ����, B�� ���� ������ ������ ����
	int AblankCnt = 0, BblankCnt = 0;
	int i, j, k;		//�ݺ��� ��ȸ�� ����
	for (i = 0; i < strlen(A); i++) {
		//A�� ���鼭 ������ ������
		if (A[i] == ' ') {
			//���� ���� 1����
			AblankCnt++;
		}
	}
	//B�� ���鼭 ������ ������
	for (i = 0; i < strlen(B); i++) {
		//���鰳�� 1 ����
		if (B[i] == ' ') {
			BblankCnt++;
		}
	}

	//A�� �ܾ��� B�� �ܾ���� ������ ���ڿ� �迭 �����ϰ� �����Ҵ� �ޱ�
	char** Awords = (char**)malloc(sizeof(char*) * (AblankCnt + 1));
	char** Bwords = (char**)malloc(sizeof(char*) * (BblankCnt + 1));

	//���� �����Ҵ��� ����� ���� �ʾҴٸ�
	if (Awords == NULL || Bwords == NULL) {
		printf("Not Enough Memory!");
		//���α׷� ����
		return -1;
	}

	//A�� ���� ���� �ܾ ������ �迭 ����
	char tmpStr[101];
	//tmpStr�� ����
	int tmpIter = 0;
	//A�� �ܾ��� ����
	int AwordsIter = 0;
	for (i = 0; i < strlen(A); i++) {
		//A�� ���鼭 ������ ���´ٸ�
		if (A[i] == ' ') {
			//tmpStr �������� �ι��� �߰���.
			tmpStr[tmpIter++] = NULL;
			//tmpStr�� ���̸�ŭ �����Ҵ� ����
			Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			//�����Ҵ��� ����� ���� �ʾҴٸ�
			if (Awords[AwordsIter] == NULL) {
				printf("Not Enough Memory!");
				//���α׷� ����
				return -1;
			}
			//�����Ҵ� ���� ������ �ܾ� ����
			strcpy(Awords[AwordsIter++], tmpStr);
			//tmpStr�� ���� �ʱ�ȭ
			tmpIter = 0;
		}
		else {
			//�� ���� ��쿡�� �ܾ A�� ���ڸ� �߰���
			tmpStr[tmpIter++] = A[i];
		}
	}
	//A ��ȸ�� ������ �Ȱ��� ������ �� �� �� ������.
	tmpStr[tmpIter++] = NULL;
	Awords[AwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Awords[AwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Awords[AwordsIter++], tmpStr);
	tmpIter = 0;

	//A�� ���� ������� B�� ������
	int BwordsIter = 0;
	//B ���ڿ� ��ȸ��
	for (i = 0; i < strlen(B); i++) {
		//���� ������ ���´ٸ�
		if (B[i] == ' ') {
			//�ܾ� ���� �ι��� �߰�
			tmpStr[tmpIter++] = NULL;
			//�ܾ��� ���̸�ŭ �����Ҵ� �޴´�.
			Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
			//�����Ҵ��� ����� ���� �ʾҴٸ�
			if (Bwords[BwordsIter] == NULL) {
				printf("Not Enough Memory!");
				return -1;
			}
			//�����Ҵ� ���� ������ ���ڿ� �����Ͽ� ����
			strcpy(Bwords[BwordsIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			//�� ���� ��쿡�� ���� �߰�
			tmpStr[tmpIter++] = B[i];
		}
	}
	//B ��ȸ�� ������ �ܾ �� �� �� �߰��� �ش�.
	tmpStr[tmpIter++] = NULL;
	Bwords[BwordsIter] = (char*)malloc(sizeof(char) * tmpIter);
	if (Bwords[BwordsIter] == NULL) {
		printf("Not Enough Memory!");
		return -1;
	}
	strcpy(Bwords[BwordsIter++], tmpStr);
	tmpIter = 0;

	//���������� ����� �ܾ���� ����� ���ڿ��� �迭
	//�迭�� ���̰� ����� ����
	int resultIter = 0;
	//���ڿ� �迭 ���� �Ҵ�
	char** resultStr = (char**)malloc(sizeof(char*));
	for (i = 0; i < AwordsIter; i++) {
		for (j = i + 1; j < AwordsIter; j++) {
			//AcombStr1�� Awords[i] �ڿ� Awords[j]�� ���� ���̰�,
			//AcombStr2�� Awords[j] �ڿ� Awords[i]�� ���� ���̴�.
			char AcombStr1[201], AcombStr2[201];
			//���� AcombStr1�� Awords[[i]�� �����ϰ�,
			strcpy(AcombStr1, Awords[i]);
			//�� �ڿ� Awords[j]�� ����.
			strcat(AcombStr1, Awords[j]);

			//���� ������� AcombStr2���� Awords[j]�� �����ϰ�, �� �ڿ� Awords[i]�� ����.
			strcpy(AcombStr2, Awords[j]);
			strcat(AcombStr2, Awords[i]);

			//B�� �ܾ���� ����� �迭�� �� ��ȸ��.
			for (k = 0; k < BwordsIter; k++) {
				//���� AcombStr1�̳� AcombStr2�� �Ȱ��� �ܾ �ִٸ�
				if (strcmp(AcombStr1, Bwords[k]) == 0 || strcmp(AcombStr2, Bwords[k]) == 0) {
					//�� �ܾ resultStr�� �־����.
					//���ڿ� �迭�� ũ�⸦ �𸣱� ������ realloc���� �ٽ� �Ҵ����ش�.
					//resultIter+1�� ũ�⸸ŭ �ٽ� �Ҵ����ش�.
					resultStr = (char**)realloc(resultStr, sizeof(char*)*(resultIter+1));
					//�����Ҵ��� ����� ���� �ʾ��� ���
					if (resultStr == NULL) {
						printf("Not Enough Memory");
						//���α׷� ����
						return -1;
					}
					//���ڹ迭 �޸� �����Ҵ�(Bwords[k]�� ����+1 ��ŭ)
					resultStr[resultIter] = (char*)malloc(sizeof(char)*(strlen(Bwords[k])+1));
					//�����Ҵ��� ����� ���� �ʾ��� ���
					if (resultStr[resultIter] == NULL) {
						printf("Not Enough Memory");
						//���α׷� ����
						return -1;
					}
					//�����Ҵ� �� ������ ���ڿ��� �־��ش�.
					strcpy(resultStr[resultIter++], Bwords[k]);
				}
			}

		}
	}


	//���ڿ��� ���̰� �� ������� �����ϴ� �ڵ�
	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			//j���� j+1�� ��� ���� ����(���� ����)
			if (strlen(resultStr[i]) < strlen(resultStr[j])) {
				char tmpStr1[101];
				strcpy(tmpStr1, resultStr[i]);
				strcpy(resultStr[i], resultStr[j]);
				strcpy(resultStr[j], tmpStr1);
			}
		}
	}

	//���ڿ��� ���̰� ���� ���� ���� ������� �����ؾ���.
	for (i = 0; i < resultIter; i++) {
		for (j = i; j < resultIter; j++) {
			//���ڿ��� ���̰� ����
			if (strlen(resultStr[i]) == strlen(resultStr[j])) {
				//j���� j+1�� ���� ������ �����ٸ�
				if (strcmp(resultStr[i], resultStr[j]) > 0) {
					//���� ����(��������)
					char tmpStr1[101];
					strcpy(tmpStr1, resultStr[i]);
					strcpy(resultStr[i], resultStr[j]);
					strcpy(resultStr[j], tmpStr1);
				}
			}
		}
	}

	//���� �Ȱ��� ���� �־ �� ���� ����ؾ� ��.
	for (i = 0; i < resultIter; i++) {
		//i�� 0�� ���� �׳� ����ϰ�
		if (i == 0) {
			printf("%s\n", resultStr[i]);
		}
		//�� ���� ��쿡�� ���� �ε����� ���ڿ��ϰ� �ٸ� ���� ���
		else if (strcmp(resultStr[i], resultStr[i - 1])!=0) {
			printf("%s\n", resultStr[i]);
		}
	}

	//�޸� �Ҵ� ����
	//resultStr �޸� �Ҵ� ����
	for (i = 0; i < resultIter; i++) {
		free(resultStr[i]);
	}
	free(resultStr);
	//Awords �޸� �Ҵ� ����
	for (i = 0; i < AwordsIter; i++) {
		free(Awords[i]);
	}
	free(Awords);
	//Bwords �޸� �Ҵ� ����
	for (i = 0; i < BwordsIter; i++) {
		free(Bwords[i]);
	}
	free(Bwords);


}