#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�л� ����ü ����
typedef struct student {
	//�̸�
	char name[10];
	//�й�
	char id[11];
	//����
	char grade;
}Student;
int main() {
	//����ü �迭 ����
	Student stus[5];
	//�ݺ��� ��ȸ�� ����
	int i, j;
	//5���� �л��� ���� ������ �Է¹޾ƾ��ϹǷ� 5�� �ݺ�
	for (i = 0; i < 5; i++) {
		//�̸�, �й�, ���� �Է�
		scanf("%s %s %c", &stus[i].name, &stus[i].id, &stus[i].grade);
		//���ۿ� �����ִ� ���๮�� ����
		getchar();
	}
	//ã���� �ϴ� �л��� �̸�, �� �л��� ����, �� �л��� ���г⵵
	char findName[10], findGrade, findYear[5];
	//�̸� �Է�
	scanf("%s", &findName);
	for (i = 0; i < 5; i++) {
		//���� �Է¹��� �̸��� ���� �̸��� �л��� ����ü �迭�� �����Ѵٸ�
		if (strcmp(findName, stus[i].name) == 0) {
			//�� �л��� ������ ���г⵵�� ���� ������.
			findGrade = stus[i].grade;
			strncpy(findYear, stus[i].id, 4);
		}
	}
	findYear[4] = NULL;

	//���ǿ� �´� �л��� �ִ��� ������ ��Ÿ�� ����
	int chk = 0;
	for (i = 0; i < 5; i++) {
		char strYear[5];
		strncpy(strYear, stus[i].id, 4);
		strYear[4] = NULL;
		//���� �Է¹��� �л��� ������ ���� ������ ���� �л��� ã�´ٸ�
		if (findGrade == stus[i].grade) {
			//�Է¹��� �л��� �ƴϰ�, ���г⵵�� ���ٸ�
			if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear) == 0)) {
				//chk���� �ٲ��ְ� �̸��� ������ش�.
				chk = 1;
				printf("%s ", stus[i].name);
			}
		}
	}
	//���� chk���� �ٲ��� �ʾҴٸ� 0�� ���
	if (!chk)
		printf("0\n");
	printf("\n");
	//ã���� �ϴ� �л��� ���г⵵�� ���г⵵�� 131�� ���� ������ ���
	int num = atoi(findYear) % 131;
	printf("%s %d", findYear, num);
}