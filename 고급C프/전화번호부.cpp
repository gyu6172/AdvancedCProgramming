#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
} Contact;
void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

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
			return 0;
		}
	}
	return 0;
}

void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

void swapContact(Contact* contactData, int index1, int index2)
{
}

void sortContact(Contact* contactData, int numContact)
{
}

void insertContact(Contact* contactData, int* numContact)
{
}

void deleteContact(Contact* contactData, int* numContact)
{
}

void printAll(Contact* contactData, int numContact)
{
}

void findContactByBirth(Contact* contactData, int numContact)
{
}

