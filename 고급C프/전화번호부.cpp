//������� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�ִ� ����ó���� ����
#define MAXCONTACT 100
//����ü ����
typedef struct ContactInfo {
	char name[21];		//�̸�
	char phone[16];		//��ȭ��ȣ
	char birth[9];		//����
} Contact;
void printMainMenu();		//���θ޴� ���
void swapContact(Contact* contactData, int index1, int index2);	//�� ����ü ������� �ٲٱ�
void sortContact(Contact* contactData, int numContact);			//����ü �����ϱ�
void insertContact(Contact* contactData, int* numContact);		//���ο� ����ó �Է¹ޱ�
void deleteContact(Contact* contactData, int* numContact);		//����ó �����ϱ�
void printAll(Contact* contactData, int numContact);			//����� ����ó ����ϱ�
void findContactByBirth(Contact* contactData, int numContact);	//���Ϸ� ����ó ã��

int main()
{
	Contact contactData[MAXCONTACT];//100�� ����ü���� ����
	int numContact = 0;//����ε���
	int menu;
	while (1) {
		printMainMenu(); //�޴� ���
		scanf("%d", &menu); //�޴�����
		switch (menu) {
		case 1: insertContact(contactData, &numContact); //���
			break;
		case 2: printAll(contactData, numContact); // ����
			break;
		case 3: deleteContact(contactData, &numContact); //����
			break;
		case 4: findContactByBirth(contactData, numContact); //������ �˻�
			break;
		case 5:
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
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp = *(contactData+index1);
	*(contactData + index1) = *(contactData + index2);
	contactData[index2] = tmp;
}

//����ó �̸������� �����ϱ�
void sortContact(Contact* contactData, int numContact)
{
	int i;
	//�������� ����� ����ó�� �̸��� �� �ٷ� �տ� ����ó�� �̸��� ���Ͽ�
	//���� ������ �ٲ۴�.
	//�ڿ������� �� �ձ��� ����.
	for (i = numContact - 1; i > 0; i--) {
		if (strcmp(contactData[i].name, contactData[i - 1].name)<0) {
			swapContact(contactData, i, i-1);
		}
	}
}

//����ó �Է¹ޱ�
void insertContact(Contact* contactData, int* numContact)
{
	//���� ���� ����ó�� ������ 100������ ũ�ų� ������ �Է��� ������ �ȵȴ�.
	if (*numContact >= 100) {
		//OVERFLOW ����Ѵ�.
		printf("OVERFLOW\n");
		//�Լ� ����(�޴��� ���ư���)
		return;
	}
	//���ο� ����ü ���� ����
	Contact newPerson;
	printf("Name:");		
	scanf("%s",newPerson.name);		//�̸� �Է¹޾Ƽ� ������.
	printf("Phone_number:");
	scanf("%s", newPerson.phone);	//�ڵ��� ��ȣ �Է¹޾Ƽ� ������.
	printf("Birth:");
	scanf("%s", newPerson.birth);	//���� �Է¹޾Ƽ� ������.
	contactData[*numContact] = newPerson;	//����ü �迭�� �� �������� �ش� ����ü ������ ������.
	*numContact = *numContact+1;		//����ü �迭�� ũ�� 1 ����
	printf("<<%d>>\n",*numContact);		//����ü ũ�� ���
	sortContact(contactData, *numContact);	//����ü �̸������� ����
}

//����ó �����ϴ� �Լ�
void deleteContact(Contact* contactData, int* numContact)
{
	//���� ���� ����ó�� ����Ǿ� ���� �ʴٸ�
	if (*numContact == 0) {
		//NO MEMBER����ϰ� �Լ� ����(�������� ���ư���.)
		printf("NO MEMBER\n");
		return;
	}
	char name[21];
	printf("Name:");
	scanf("%s",name);	//������ �̸� �Է¹���.
	int i,j;		//�ݺ��� ��ȸ�� ���� ����
	for (i = 0; i < *numContact; i++) {
		//���� ����ó �߿� �Է¹��� �̸��� ���� �̸��� ���� ����ó�� �ִٸ�
		if (strcmp(name, contactData[i].name) == 0) {
			//�� ����ó�� �ε������� ������ ��ȸ�ϸ鼭
			for (j = i; j < *numContact - 1; j++) {
				//����ü ��������� �� ĭ�� ������ �ű�.
				contactData[j] = contactData[j+1];
			}
			//����ü �迭�� ũ�� 1 ���ҽ�Ŵ.
			*numContact = *numContact-1;
		}
	}
}

//���� ����� ����ó ����ϴ� �Լ�
void printAll(Contact* contactData, int numContact)
{
	int i;
	//����ü �迭�� ũ�⸸ŭ �ݺ����� ������.
	for (i = 0; i < numContact; i++) {
		//�̸�, ��ȭ��ȣ, ��������� ����Ѵ�.
		printf("%s %s %s\n",contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

//������ �Է¹޾� �� ������ ��� ����ϴ� �Լ�
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth;
	printf("Birth:");	//�� �Է¹���(������)
	scanf("%d", &birth);
	int i;
	//����ü �迭�� ũ�⸸ŭ ��ȸ�� ����.
	for (i = 0; i < numContact; i++) {
		//atoi�Լ��� ��������� ���������� �ٲ㼭 �����س��´�.
		int birthday = atoi(contactData[i].birth);
		//birthday���� �¾ �޸� �̾Ƴ�.
		int month = (birthday%10000)/100;
		//���� �̾Ƴ� ���� �Ʊ� �Է¹��� �ް� ���ٸ�
		if (month == birth) {
			//�� ����ó�� �̸�, �ڵ��� ��ȣ, ������� ����Ѵ�.
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}

