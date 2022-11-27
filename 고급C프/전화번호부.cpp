//헤더파일 선언
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//최대 연락처개수 정의
#define MAXCONTACT 100
//구조체 정의
typedef struct ContactInfo {
	char name[21];		//이름
	char phone[16];		//전화번호
	char birth[9];		//생일
} Contact;
void printMainMenu();		//메인메뉴 출력
void swapContact(Contact* contactData, int index1, int index2);	//두 구조체 멤버변수 바꾸기
void sortContact(Contact* contactData, int numContact);			//구조체 정렬하기
void insertContact(Contact* contactData, int* numContact);		//새로운 연락처 입력받기
void deleteContact(Contact* contactData, int* numContact);		//연락처 삭제하기
void printAll(Contact* contactData, int numContact);			//저장된 연락처 출력하기
void findContactByBirth(Contact* contactData, int numContact);	//생일로 연락처 찾기

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
			return 0;		//프로그램 종료
		}
	}
	return 0;
}

//메인메뉴 출력
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

//구조체 멤버 변수 바꾸기
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp = *(contactData+index1);
	*(contactData + index1) = *(contactData + index2);
	contactData[index2] = tmp;
}

//연락처 이름순으로 정렬하기
void sortContact(Contact* contactData, int numContact)
{
	int i;
	//마지막에 저장된 연락처의 이름과 그 바로 앞에 연락처의 이름을 비교하여
	//사전 순으로 바꾼다.
	//뒤에서부터 맨 앞까지 비교함.
	for (i = numContact - 1; i > 0; i--) {
		if (strcmp(contactData[i].name, contactData[i - 1].name)<0) {
			swapContact(contactData, i, i-1);
		}
	}
}

//연락처 입력받기
void insertContact(Contact* contactData, int* numContact)
{
	//만약 현재 연락처의 개수가 100개보다 크거나 같으면 입력을 받으면 안된다.
	if (*numContact >= 100) {
		//OVERFLOW 출력한다.
		printf("OVERFLOW\n");
		//함수 종료(메뉴로 돌아가기)
		return;
	}
	//새로운 구조체 변수 선언
	Contact newPerson;
	printf("Name:");		
	scanf("%s",newPerson.name);		//이름 입력받아서 저장함.
	printf("Phone_number:");
	scanf("%s", newPerson.phone);	//핸드폰 번호 입력받아서 저장함.
	printf("Birth:");
	scanf("%s", newPerson.birth);	//생일 입력받아서 저장함.
	contactData[*numContact] = newPerson;	//구조체 배열의 맨 마지막에 해당 구조체 변수를 저장함.
	*numContact = *numContact+1;		//구조체 배열의 크기 1 증가
	printf("<<%d>>\n",*numContact);		//구조체 크기 출력
	sortContact(contactData, *numContact);	//구조체 이름순으로 정렬
}

//연락처 삭제하는 함수
void deleteContact(Contact* contactData, int* numContact)
{
	//만약 현재 연락처가 저장되어 있지 않다면
	if (*numContact == 0) {
		//NO MEMBER출력하고 함수 종료(메인으로 돌아간다.)
		printf("NO MEMBER\n");
		return;
	}
	char name[21];
	printf("Name:");
	scanf("%s",name);	//삭제할 이름 입력받음.
	int i,j;		//반복문 순회용 변수 선언
	for (i = 0; i < *numContact; i++) {
		//만약 연락처 중에 입력받은 이름과 같은 이름을 가진 연락처가 있다면
		if (strcmp(name, contactData[i].name) == 0) {
			//그 연락처의 인덱스부터 끝까지 순회하면서
			for (j = i; j < *numContact - 1; j++) {
				//구조체 멤버변수를 한 칸씩 앞으로 옮김.
				contactData[j] = contactData[j+1];
			}
			//구조체 배열의 크기 1 감소시킴.
			*numContact = *numContact-1;
		}
	}
}

//현재 저장된 연락처 출력하는 함수
void printAll(Contact* contactData, int numContact)
{
	int i;
	//구조체 배열의 크기만큼 반복문을 돌린다.
	for (i = 0; i < numContact; i++) {
		//이름, 전화번호, 생년월일을 출력한다.
		printf("%s %s %s\n",contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

//생일을 입력받아 그 생일인 사람 출력하는 함수
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth;
	printf("Birth:");	//달 입력받음(정수형)
	scanf("%d", &birth);
	int i;
	//구조체 배열의 크기만큼 순회를 돈다.
	for (i = 0; i < numContact; i++) {
		//atoi함수로 생년월일을 정수형으로 바꿔서 저장해놓는다.
		int birthday = atoi(contactData[i].birth);
		//birthday에서 태어난 달만 뽑아냄.
		int month = (birthday%10000)/100;
		//만약 뽑아낸 달이 아까 입력받은 달과 같다면
		if (month == birth) {
			//그 연락처의 이름, 핸드폰 번호, 생년월일 출력한다.
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}

