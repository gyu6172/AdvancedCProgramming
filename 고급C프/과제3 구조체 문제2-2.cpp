#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�л� ����ü ����
typedef struct student {
	//�̸�
	char name[21];
	//���� ����
	int kor;
	//���� ����
	int eng;
	//���� ����
	int math;
	//���
	double avg;
}Student;
//�Լ� ����
void read_data(Student* pSt, int n);
void sort_score(Student* pSt, int n);
Student* select_out(Student* p, Student* q, int n);
int main() {
	//�л� �� �Է�
	int n;
	scanf("%d", &n);
	//����ü �迭 �� ���� ������ ����ü ������ ���� �ΰ�, ���� ����� ������ ���� ����
	Student st1[49], st2[49], * pSt, * qSt, * finalSt;
	//pSt�� st1��, qSt�� st2�� ����Ű�� ��
	pSt = st1;
	qSt = st2;
	//�� ���� ����ü �Է¹���
	read_data(pSt, n);
	read_data(qSt, n);
	//�� ����ü ����
	sort_score(pSt, n);
	sort_score(qSt, n);
	//�� ����ü �߿��� ���ǿ� �´� ����ü�����͸� ��ȯ�Ͽ� finalSt�� ����
	finalSt = select_out(pSt, qSt, n);
	//finalSt�� ��ȸ�ϸ� ����Ѵ�.
	for (Student* iter = finalSt; iter < finalSt + n; iter++) {
		printf("%s %d %d %d %.1f\n", iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	}
}
//�Է� �Լ�
void read_data(Student* pSt, int n)
{
	//�ݺ��� ��ȸ��	����ü ������ ����
	Student* iter;
	for (iter = pSt; iter < pSt + n; iter++) {
		//n�� �ݺ��ϸ� �Է¹���
		scanf("%s %d %d %d", &iter->name, &iter->kor, &iter->eng, &iter->math);
		getchar();
		//��հ� �ʱ�ȭ����.
		iter->avg = ((iter->kor) + (iter->eng) + (iter->math)) / 3.0;
	}
}

//���� �Լ�
void sort_score(Student* pSt, int n)
{
	//��ȸ�� ����ü ������ ���� �ΰ� ����
	Student* iter1, * iter2;
	//iter1�� pSt~������ ����, iter2�� iter1~������ ����.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//���� iter1�� ��հ����� iter2�� ��հ��� �� ũ�ٸ�
			if (iter1->avg < iter2->avg) {
				//���� �ٲ��ش�.
				Student p = *iter1;
				*iter1 = *iter2;
				*iter2 = p;
			}
		}
	}
	//��հ��� ���� ��쿡�� ���������� ū ������ �����ؾ���.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//���� ��հ��� ����,
			if (iter1->avg == iter2->avg) {
				//���������� �� ũ�ٸ�
				if (iter1->kor < iter2->kor) {
					//�� ����ü�� ���� �ٲ���.
					Student p = *iter1;
					*iter1 = *iter2;
					*iter2 = p;
				}
			}
		}
	}
	//��հ��� ����, ������������ ���� ��쿡�� ���������� ū ������ �����ؾ���.
	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
			//��հ��� ����,
			if (iter1->avg == iter2->avg) {
				//���������� ���� ��쿡
				if (iter1->kor == iter2->kor) {
					//���������� ���Ͽ� �� ����ü�� �ٲ���.
					if (iter1->eng < iter2->eng) {
						Student p = *iter1;
						*iter1 = *iter2;
						*iter2 = p;
					}
				}
			}
		}
	}
}

//���ڷ� ���� �� ����ü �迭 ������ ���� �߿��� �߰� ��� �л��� ����� �� ���� �����͸� ��ȯ��.
Student* select_out(Student* p, Student* q, int n)
{
	;	//p�� �߰� ��� �л��� ����� q�� �߰� ��� �л��� ��պ��� ������
	if ((p + n / 2)->avg > (q + n / 2)->avg) {
		//p�� ��ȯ
		return p;
	}
	//�׷��� ���� ��쿡�� q ��ȯ.
	else if ((p + n / 2)->avg < (q + n / 2)->avg) {
		return q;
	}
}