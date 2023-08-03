#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���� ����ü ����
typedef struct subject {
	char *name;		//������ �̸�
	double score;	//�� ������ ����
}Subject;
//�л� ����ü ����
typedef struct student {
	char *name;		//�л��� �̸�
	char id[5];		//�л��� �й�
	int numSubject;	//������ ����
	Subject *pSub;	//�����
	double avg;		//���� ������ ���
}Student;
int main() {
	//n�Է¹���
	int n;
	scanf("%d", &n);

	//�л� ����ü �迭 �����Ҵ�
	Student* stus = (Student*)malloc(sizeof(Student) * n);

	//�ݺ��� ��ȸ�� ����
	int i, j;
	//n���� �л��� ������ �Է¹���
	for (i = 0; i < n; i++) {
		//�̸��� �й� ����� ���� ����
		char name[101], id[5];
		//���� �̸� ����� ���� ����
		char subjectStr[101];
		//�̸��� �й� �Է¹���
		scanf("%s %s ",name,id);
		//���� �̸��� �Է¹���
		gets_s(subjectStr);
		//������ ���� ������ ����
		int subjectCnt = 0;
		for (j = 0; j <= strlen(subjectStr); j++) {
			//�����ڿ��� �� ��ȸ�ϸ鼭 �����̳� �ι��ڸ� ������ ������ ���� 1 ������Ŵ
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				subjectCnt++;
			}
		}
		//���� ���ڿ� �� ������ �����̸�, ������ �� ������ �����̴�.
		subjectCnt /= 2;
		//�л��� �̸��� �����Ҵ� ����
		stus[i].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
		//�޸� ������ ����.
		strcpy(stus[i].name, name);
		//�й� ����
		strcpy(stus[i].id, id);
		//������ ���� ����
		stus[i].numSubject = subjectCnt;
		//�л��� ������ ���� ����
		stus[i].pSub = (Subject*)malloc(sizeof(Subject) * subjectCnt);
		//���� ���ڿ��� �ܾ�� ���� �� �� �ܾ ����� ���� tmp
		char tmp[101];
		//tmp�� ũ��
		int tmpIter = 0;
		//���� �ܾ ��������� �������� �˷��� ����
		int wordsCnt = 0;
		//���� ����ü �迭�� ũ��
		int pSubIter=0;
		//������ ���
		double avg = 0.0;
		//���� ���ڿ��� ó������ ������ ��ȸ�� ��
		for (j = 0; j <= strlen(subjectStr); j++) {
			//���� �����̳� �ι��ڸ� �����ٸ�
			if (subjectStr[j] == ' ' || subjectStr[j] == NULL) {
				//���� �ܾ �������� �ι��� �߰�
				tmp[tmpIter++] = NULL;
				//���� ���� �ܾ ���� ���̶��
				if (wordsCnt%2 == 0) {
					//���� ����ü �迭�� �̸��� ������ ������ �����Ҵ� ����.
					(stus[i].pSub)[pSubIter].name = (char*)malloc(sizeof(tmpIter));
					//�� ������ �����̸� ����.
					strcpy((stus[i].pSub)[pSubIter].name, tmp);
				}
				//���� ���� �ܾ ���� �������
				else if (wordsCnt%2 == 1) {
					//������ ������ �Ǽ������� ��ȯ�ؼ� ����.
					(stus[i].pSub)[pSubIter++].score = atof(tmp);
					//��հ��� �����ϴ� �������� ���� ���� �����ش�.(���߿� ���񰳼��� ����)
					avg += atof(tmp);
				}
				//wordsCnt 1 ����
				wordsCnt++;
				//���� �ܾ��� ���� �ʱ�ȭ
				tmpIter = 0;
			}
			//���� �����̳� �ι��ڰ� �ƴ϶��
			else {
				//���� �ܾ ���� ����.
				tmp[tmpIter++] = subjectStr[j];
			}
		}
		//�ݺ��� ���� ��, �л��� ��տ� avg�� ������ ������ ���� ���� ����.
		stus[i].avg = avg/stus[i].numSubject;
	}

	//�л��� ����� ���� ������� �����ϴ� �ڵ�
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//���� i���� j�� ����� ���ٸ�
			if (stus[i].avg < stus[j].avg) {
				//�� ����ü ����� �ٲ��ش�.(��������)
				Student tmp = stus[i];
				stus[i] = stus[j];
				stus[j] = tmp;
			}
		}
	}
	//����� ���� �л��� �й������ �����ؾ��Ѵ�.
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			//���� ����� ����,
			if (stus[i].avg == stus[j].avg) {
				//i�� �й����� j�� �й��� �����ٸ�
				if (strcmp(stus[i].id, stus[j].id) > 0) {
					//���� ����
					Student tmp = stus[i];
					stus[i] = stus[j];
					stus[j] = tmp;
				}
			}
		}
	}

	//k �Է¹���
	int k;
	scanf("%d",&k);

	//k��° �л��� ������.
	Student kStudent = stus[k-1];

	//k��° �л��� ���� �� �� ���� �̸��� ������ ������ �� ������ ������ ������ ����
	char highSubName[101];
	double highSubScore=0.0;

	//�� �л��� �� ������ �� üũ��.
	for (i = 0; i < kStudent.numSubject; i++) {
		//���� �ִ񰪺��� ���� ������ �ִٸ�
		if (kStudent.pSub[i].score > highSubScore) {
			//�����̸��� �ٲ��ְ�
			strcpy(highSubName, kStudent.pSub[i].name);
			//�ִ� ������ �ٲ��ش�.
			highSubScore = kStudent.pSub[i].score;
		}
	}
	//���������� �̸��� �й�, ���, ���� �� �� ����, �� ������ ������ ������ش�.
	printf("%s %s %.2lf %s %.2lf",kStudent.name, kStudent.id, kStudent.avg, highSubName, highSubScore);

	//�Ҵ���� �޸𸮸� �����Ѵ�.
	for (i = 0; i < n; i++) {
		free(stus[i].pSub);
		free(stus[i].name);
	}
	//�л� ����ü �迭 ����
	free(stus);

}