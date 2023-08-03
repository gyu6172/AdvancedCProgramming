//헤더파일 선언
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//구조체 정의
typedef struct ContactInfo {
	char* name;		//이름
	char* phone;		//전화번호
	char* birth;		//생일
} Contact;
Contact** tel_list;		//구조체 이중포인터 변수 선언
int max_num;			//최대 크기 변수
int count;				//현재 크기 변수

void printMainMenu();		//메인메뉴 출력
void swapContact(Contact** telList, int index1, int index2);	//두 구조체 멤버변수 바꾸기
void sortContact(Contact** telList, int numContact);			//구조체 정렬하기
void insertContact(Contact** telList, int* numContact);		//새로운 연락처 입력받기
void deleteContact(Contact** telList, int* numContact);		//연락처 삭제하기
void printAll(Contact** telList, int numContact);			//저장된 연락처 출력하기
void findContactByBirth(Contact** telList, int numContact);	//생일로 연락처 찾기

int main()
{
	//최대 크기 입력받음
	printf("Max_num:");
	scanf("%d", &max_num);

	//구조체 이중포인터 동적할당받음
	tel_list = (Contact**)malloc(sizeof(Contact*) * max_num);

	int menu;
	while (1) {
		printMainMenu(); //메뉴 출력
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1: insertContact(tel_list, &count); //등록
			break;
		case 2: printAll(tel_list, count); // 보기
			break;
		case 3: deleteContact(tel_list, &count); //삭제
			break;
		case 4: findContactByBirth(tel_list, count); //생일자 검색
			break;
		case 5:
			free(tel_list);	//구조체 배열 동적할당 해제함.
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
void swapContact(Contact** telList, int index1, int index2)
{
	Contact tmp = *telList[index1];
	*telList[index1] = *telList[index2];
	*telList[index2] = tmp;
}

//연락처 이름순으로 정렬하기
void sortContact(Contact** telList, int numContact)
{
	int i;
	//마지막에 저장된 연락처의 이름과 그 바로 앞에 연락처의 이름을 비교하여
	//사전 순으로 바꾼다.
	//뒤에서부터 맨 앞까지 비교함.
	for (i = numContact - 1; i > 0; i--) {
		if (strcmp(telList[i]->name, telList[i - 1]->name) < 0) {
			swapContact(telList, i, i - 1);
		}
	}
}

//연락처 입력받기
void insertContact(Contact** telList, int* numContact)
{
	//만약 현재 연락처의 개수가 max_num보다 크거나 같으면 입력을 받으면 안된다.
	if (*numContact >= max_num) {
		//OVERFLOW 출력한다.
		printf("OVERFLOW\n");
		//함수 종료(메뉴로 돌아가기)
		return;
	}
	//구조체 배열에 동적할당 받음.
	telList[*numContact] = (Contact*)malloc(sizeof(Contact));
	//입력받을 이름, 폰 번호, 생일 변수 선언
	char name[100];
	char phone[100];
	char birth[100];
	printf("Name:");
	scanf("%s", &name);		//이름 입력받음
	printf("Phone_number:");
	scanf("%s", &phone);	//핸드폰 번호 입력받음
	printf("Birth:");
	scanf("%s", &birth);	//생일 입력받음

	//입력받은 이름의 길이+1만큼 동적할당 받음.
	telList[*numContact]->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	//입력받은 폰 번호의 길이+1만큼 동적할당 받음.
	telList[*numContact]->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
	//입력받은 생일의 길이+1만큼 동적할당 받음.
	telList[*numContact]->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
	//동적할당 받은 공간에 각각 이름, 폰 번호, 생일 저장함.
	strcpy(telList[*numContact]->name, name);
	strcpy(telList[*numContact]->phone, phone);
	strcpy(telList[*numContact]->birth, birth);

	*numContact = *numContact + 1;		//구조체 배열의 크기 1 증가
	printf("<<%d>>\n", *numContact);		//구조체 크기 출력
	sortContact(telList, *numContact);	//구조체 이름순으로 정렬
}

//연락처 삭제하는 함수
void deleteContact(Contact** telList, int* numContact)
{
	//만약 현재 연락처가 저장되어 있지 않다면
	if (*numContact == 0) {
		//NO MEMBER출력하고 함수 종료(메인으로 돌아간다.)
		printf("NO MEMBER\n");
		return;
	}
	char name[21];
	printf("Name:");
	scanf("%s", name);	//삭제할 이름 입력받음.
	int i, j;		//반복문 순회용 변수 선언
	for (i = 0; i < *numContact; i++) {
		//만약 연락처 중에 입력받은 이름과 같은 이름을 가진 연락처가 있다면
		if (strcmp(name, telList[i]->name) == 0) {
			//그 연락처의 이름, 폰 번호, 생일 문자열 동적할당 해제
			free(telList[i]->name);
			free(telList[i]->phone);
			free(telList[i]->birth);
			//구조체 배열의 요소 동적할당 해제
			free(telList[i]);
			//그 연락처의 인덱스부터 끝까지 순회하면서
			for (j = i; j < *numContact - 1; j++) {
				//구조체 멤버변수를 한 칸씩 앞으로 옮김.
				telList[j] = telList[j + 1];
			}
			//구조체 배열의 크기 1 감소시킴.
			*numContact = *numContact - 1;
		}
	}
}

//현재 저장된 연락처 출력하는 함수
void printAll(Contact** telList, int numContact)
{
	int i;
	//구조체 배열의 크기만큼 반복문을 돌린다.
	for (i = 0; i < numContact; i++) {
		//이름, 전화번호, 생년월일을 출력한다.
		printf("%s %s %s\n", telList[i]->name, telList[i]->phone, telList[i]->birth);
	}
}

//생일을 입력받아 그 생일인 사람 출력하는 함수
void findContactByBirth(Contact** telList, int numContact)
{
	int birth;
	printf("Birth:");	//달 입력받음(정수형)
	scanf("%d", &birth);
	int i;
	//구조체 배열의 크기만큼 순회를 돈다.
	for (i = 0; i < numContact; i++) {
		//atoi함수로 생년월일을 정수형으로 바꿔서 저장해놓는다.
		int birthday = atoi(telList[i]->birth);
		//birthday에서 태어난 달만 뽑아냄.
		int month = (birthday % 10000) / 100;
		//만약 뽑아낸 달이 아까 입력받은 달과 같다면
		if (month == birth) {
			//그 연락처의 이름, 핸드폰 번호, 생년월일 출력한다.
			printf("%s %s %s\n", telList[i]->name, telList[i]->phone, telList[i]->birth);
		}
	}
}

