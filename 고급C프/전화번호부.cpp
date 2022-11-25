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
	Contact contactData[MAXCONTACT];//100의 구조체공간 정의
	int numContact = 0;//요소인덱스
	int menu;
	while (1) {
		printMainMenu(); //메뉴 출력
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1: insertContact(contactData, &numContact); //등록
			break;
		case 2: printAll(contactData, numContact); // 보기
			break;
		case 3: deleteContact(contactData, &numContact); //삭제
			break;
		case 4: findContactByBirth(contactData, numContact); //생일자 검색
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

