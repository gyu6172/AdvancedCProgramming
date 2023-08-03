#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ü ����
typedef struct student {
	char* name;		//�̸�
	int firstStage;	//1�ܰ� ����
	int interview;	//���� ����
	double sum;		//����
}Student;
int main() {
	//n,m ����
	int n, p, m;
	scanf("%d %d", &n, &p);		//n,m �Է¹���
	getchar();	//���๮�� ����

	//����ü �迭 �޸� �Ҵ�
	Student* stus = (Student*)malloc(sizeof(Student) * n);

	//�ݺ��� ��ȸ�� ����
	int i, j;
	for (i = 0; i < n; i++) {
		//�̸� ����� ���ڿ�����
		char name[101];
		//�̸�, 1�ܰ� ����, ���� ���� �Է¹���
		scanf("%s %d %d", name, &stus[i].firstStage, &stus[i].interview);
		//���� ���� ����
		getchar();
		//����ü ��� �̸� ���� �޸� �Ҵ�
		stus[i].name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		//���ڿ� ������
		strcpy(stus[i].name, name);
		//������ 1�ܰ�����*7 + ���� ����*3 �� �ʱ�ȭ��(���߿� ����� �� 10���� ������ ����� ����)
		stus[i].sum = stus[i].firstStage * 7 + stus[i].interview * 3;
	}

	//���� �������� �������� �����ϴ� �ڵ�
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			//stus[i]�� ������ stus[j]�� ������ ���ؼ� �� ū���� �տ� ������
			if (stus[j].sum < stus[j+1].sum) {
				//��������
				Student tmp = stus[j];
				stus[j] = stus[j+1];
				stus[j+1] = tmp;
			}
		}
	}
	//������ ������ 1�ܰ� ���� �������� �����ؾ���
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			//���� ������ ���ٸ�,
			if (stus[j+1].sum == stus[j].sum) {
				//1�ܰ� ������ �������� �������ش�.
				if (stus[j].firstStage < stus[j+1].firstStage) {
					//�� �� �� ū ���� ���� ����ü �迭�� ��Ұ� �տ� ���� ��.(��������)
					Student tmp = stus[j];
					stus[j] = stus[j+1];
					stus[j+1] = tmp;

				}
			}
		}
	}

	m = n*p/100;
	//m���� �հ��ڸ� ����������, ������ ���� 1�ܰ������� ���� ����� ��� ������.
	//i=m ���� �����ؼ� i-1�� i�� ���ؼ� 1�ܰ� ������ ���� ���� i�� 1�� ������Ŵ
	for (i = m; i < n; i++) {
		if (stus[i - 1].firstStage != stus[i].firstStage) {
			//���� i-1�� i�� 1�ܰ� ������ �ٸ��ٸ�, �ݺ��� Ż��.
			break;
		}
	}
	//m=i�� �ٲ��ش�.
	m = i;

	//0���� m���� ������ش�.
	for (i = 0; i < m; i++) {
		printf("%s %d %d %.1f\n", stus[i].name, stus[i].firstStage, stus[i].interview, stus[i].sum / 10);
	}
	//�������� �� �հ��ڼ� ���.
	printf("%d", m);

	//����ü �迭�� �� ��������� ����� �̸��� �޸� �Ҵ� �������ش�.
	for (i = 0; i < n; i++) {
		free(stus[i].name);
	}
	//���������� ����ü �迭�� �޸� �Ҵ� �������ش�.
	free(stus);
}