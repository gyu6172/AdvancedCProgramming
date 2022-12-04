//������� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//����ü ����
typedef struct ContactInfo {
	char* name;		//�̸�
	char* phone;		//��ȭ��ȣ
	char* birth;		//����
} Contact;
Contact** tel_list;		//����ü ���������� ���� ����
int max_num;			//�ִ� ũ�� ����
int count;				//���� ũ�� ����

void printMainMenu();		//���θ޴� ���
void swapContact(Contact** telList, int index1, int index2);	//�� ����ü ������� �ٲٱ�
void sortContact(Contact** telList, int numContact);			//����ü �����ϱ�
void insertContact(Contact** telList, int* numContact);		//���ο� ����ó �Է¹ޱ�
void deleteContact(Contact** telList, int* numContact);		//����ó �����ϱ�
void printAll(Contact** telList, int numContact);			//����� ����ó ����ϱ�
void findContactByBirth(Contact** telList, int numContact);	//���Ϸ� ����ó ã��

int main()
{
	//�ִ� ũ�� �Է¹���
	printf("Max_num:");
	scanf("%d", &max_num);

	//����ü ���������� �����Ҵ����
	tel_list = (Contact**)malloc(sizeof(Contact*) * max_num);

	int menu;
	while (1) {
		printMainMenu(); //�޴� ���
		scanf("%d", &menu); //�޴�����
		switch (menu) {
		case 1: insertContact(tel_list, &count); //���
			break;
		case 2: printAll(tel_list, count); // ����
			break;
		case 3: deleteContact(tel_list, &count); //����
			break;
		case 4: findContactByBirth(tel_list, count); //������ �˻�
			break;
		case 5:
			free(tel_list);	//����ü �迭 �����Ҵ� ������.
			return 0;		//���α׷� ����
		}
	}
	return 0;
}

//���θ޴� ���
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

//����ü ��� ���� �ٲٱ�
void swapContact(Contact** telList, int index1, int index2)
{
	Contact tmp = *telList[index1];
	*telList[index1] = *telList[index2];
	*telList[index2] = tmp;
}

//����ó �̸������� �����ϱ�
void sortContact(Contact** telList, int numContact)
{
	int i;
	//�������� ����� ����ó�� �̸��� �� �ٷ� �տ� ����ó�� �̸��� ���Ͽ�
	//���� ������ �ٲ۴�.
	//�ڿ������� �� �ձ��� ����.
	for (i = numContact - 1; i > 0; i--) {
		if (strcmp(telList[i]->name, telList[i - 1]->name) < 0) {
			swapContact(telList, i, i - 1);
		}
	}
}

//����ó �Է¹ޱ�
void insertContact(Contact** telList, int* numContact)
{
	//���� ���� ����ó�� ������ max_num���� ũ�ų� ������ �Է��� ������ �ȵȴ�.
	if (*numContact >= max_num) {
		//OVERFLOW ����Ѵ�.
		printf("OVERFLOW\n");
		//�Լ� ����(�޴��� ���ư���)
		return;
	}
	//����ü �迭�� �����Ҵ� ����.
	telList[*numContact] = (Contact*)malloc(sizeof(Contact));
	//�Է¹��� �̸�, �� ��ȣ, ���� ���� ����
	char name[100];
	char phone[100];
	char birth[100];
	printf("Name:");
	scanf("%s", &name);		//�̸� �Է¹���
	printf("Phone_number:");
	scanf("%s", &phone);	//�ڵ��� ��ȣ �Է¹���
	printf("Birth:");
	scanf("%s", &birth);	//���� �Է¹���

	//�Է¹��� �̸��� ����+1��ŭ �����Ҵ� ����.
	telList[*numContact]->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	//�Է¹��� �� ��ȣ�� ����+1��ŭ �����Ҵ� ����.
	telList[*numContact]->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
	//�Է¹��� ������ ����+1��ŭ �����Ҵ� ����.
	telList[*numContact]->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
	//�����Ҵ� ���� ������ ���� �̸�, �� ��ȣ, ���� ������.
	strcpy(telList[*numContact]->name, name);
	strcpy(telList[*numContact]->phone, phone);
	strcpy(telList[*numContact]->birth, birth);

	*numContact = *numContact + 1;		//����ü �迭�� ũ�� 1 ����
	printf("<<%d>>\n", *numContact);		//����ü ũ�� ���
	sortContact(telList, *numContact);	//����ü �̸������� ����
}

//����ó �����ϴ� �Լ�
void deleteContact(Contact** telList, int* numContact)
{
	//���� ���� ����ó�� ����Ǿ� ���� �ʴٸ�
	if (*numContact == 0) {
		//NO MEMBER����ϰ� �Լ� ����(�������� ���ư���.)
		printf("NO MEMBER\n");
		return;
	}
	char name[21];
	printf("Name:");
	scanf("%s", name);	//������ �̸� �Է¹���.
	int i, j;		//�ݺ��� ��ȸ�� ���� ����
	for (i = 0; i < *numContact; i++) {
		//���� ����ó �߿� �Է¹��� �̸��� ���� �̸��� ���� ����ó�� �ִٸ�
		if (strcmp(name, telList[i]->name) == 0) {
			//�� ����ó�� �̸�, �� ��ȣ, ���� ���ڿ� �����Ҵ� ����
			free(telList[i]->name);
			free(telList[i]->phone);
			free(telList[i]->birth);
			//����ü �迭�� ��� �����Ҵ� ����
			free(telList[i]);
			//�� ����ó�� �ε������� ������ ��ȸ�ϸ鼭
			for (j = i; j < *numContact - 1; j++) {
				//����ü ��������� �� ĭ�� ������ �ű�.
				telList[j] = telList[j + 1];
			}
			//����ü �迭�� ũ�� 1 ���ҽ�Ŵ.
			*numContact = *numContact - 1;
		}
	}
}

//���� ����� ����ó ����ϴ� �Լ�
void printAll(Contact** telList, int numContact)
{
	int i;
	//����ü �迭�� ũ�⸸ŭ �ݺ����� ������.
	for (i = 0; i < numContact; i++) {
		//�̸�, ��ȭ��ȣ, ��������� ����Ѵ�.
		printf("%s %s %s\n", telList[i]->name, telList[i]->phone, telList[i]->birth);
	}
}

//������ �Է¹޾� �� ������ ��� ����ϴ� �Լ�
void findContactByBirth(Contact** telList, int numContact)
{
	int birth;
	printf("Birth:");	//�� �Է¹���(������)
	scanf("%d", &birth);
	int i;
	//����ü �迭�� ũ�⸸ŭ ��ȸ�� ����.
	for (i = 0; i < numContact; i++) {
		//atoi�Լ��� ��������� ���������� �ٲ㼭 �����س��´�.
		int birthday = atoi(telList[i]->birth);
		//birthday���� �¾ �޸� �̾Ƴ�.
		int month = (birthday % 10000) / 100;
		//���� �̾Ƴ� ���� �Ʊ� �Է¹��� �ް� ���ٸ�
		if (month == birth) {
			//�� ����ó�� �̸�, �ڵ��� ��ȣ, ������� ����Ѵ�.
			printf("%s %s %s\n", telList[i]->name, telList[i]->phone, telList[i]->birth);
		}
	}
}

