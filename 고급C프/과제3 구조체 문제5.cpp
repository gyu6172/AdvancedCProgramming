#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�л� ����ü ����
typedef struct stu {
	//�̸�, �й�, ������ ����, �����̸�, �������
	char name[31];
	int id;
	int gradeCnt;
	char grade[10][31];
	double point;
}Student;
//����ü �迭 ����
Student students[100];
//�л� ���� ���� �������� ����
int studentCnt = 0;
//�Է� �Լ�
void inputStudent();
//���� �Լ�
void sortStudent(Student arr[], int cnt);
//���� �Լ�
void deleteStudent();
//��� �Լ�
void printStudent(Student arr[], int cnt);
int main() {
	while (1) {
		//��ɾ� �Է¹���
		char code;
		scanf("%c", &code);
		//���๮�� ����
		getchar();
		//�л����� �Է�
		if (code == 'I') {
			inputStudent();
		}
		//�л� �̸������� ���� �� ���
		else if (code == 'S') {
			sortStudent(students, studentCnt);
		}
		//�л����� ����
		else if (code == 'D') {
			deleteStudent();
		}
		//�����ִ� ��� �л� ���� ���
		else if (code == 'P') {
			printStudent(students, studentCnt);
		}
		//���α׷� ����
		else if (code == 'Q') {
			break;
		}
	}
}

//�Է� �Լ�
void inputStudent()
{
	//�л� ����ü���� ����
	Student tmp;
	//��� ���� 0���� �ʱ�ȭ
	tmp.point = 0;
	//�̸�, �й�, ���� �� �Է¹���
	scanf("%s %d %d", &tmp.name, &tmp.id, &tmp.gradeCnt);
	//���� �� ��ŭ �ݺ��ؼ� �����̸��� �� ������ ���� �Է¹���
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf", &tmp.grade[i], &p);
		//������ ������ �� ������ �����ش�.
		tmp.point += p;
	}
	//���๮�� ����
	getchar();
	//����ü �迭�� ����ü���� �߰�
	students[studentCnt] = tmp;
	//�л� �� 1������Ŵ.
	studentCnt++;
}

//���� �Լ�
void sortStudent(Student arr[], int cnt)
{
	//���� �Լ��� �״�� �ξ�� �ϹǷ� ���ο� ����ü �迭�� �ϳ� �����ؼ� �� �迭�� ������ ������ ���� �����Ͽ� �����.
	Student newArr[100];
	int i, j;
	//���ο� �迭�� ����ü ����
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	//���ο� �迭�� �̸� ������ �������ش�.
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			//���� �̸��� ���� ������ ���̶��
			if (strcmp(newArr[i].name, newArr[j].name) > 0) {
				//����ü ����� �ٲ��ش�.
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	//����Լ� �ҷ��ͼ� ���ο� �迭 ���
	printStudent(newArr, cnt);
}

//�л� ���� �Լ�
void deleteStudent()
{
	//�����ϰ��� �ϴ� �̸��� �Է¹��� ����
	char findName[31];
	//�̸� �Է¹ް� ���๮�� ����
	scanf("%s", &findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		//�迭 ��ȸ �ϸ鼭 �Է� ���� �̸��� ã�� ���
		if (strcmp(students[i].name, findName) == 0) {
			//ã�� ��ġ���� �迭�� ������ �� ĭ�� ������ ���.
			for (int j = i; j < studentCnt - 1; j++) {
				students[j] = students[j + 1];
			}
			//�л� �� 1 ���ҽ�Ŵ.
			studentCnt--;
		}
	}
}

//��� �Լ�
void printStudent(Student arr[], int cnt)
{
	//����ü �迭�� ��ȸ�ϸ� �̸�, �й�, �����, ��ü ���� �������.
	for (int i = 0; i < cnt; i++) {
		printf("%s %d %d %.2f\n", arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point / arr[i].gradeCnt);
	}
}