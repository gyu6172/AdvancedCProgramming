#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//problem 1-2
////�л� ����ü ����
//typedef struct student {
//	//�̸�
//	char name[10];
//	//�й�
//	char id[11];
//	//����
//	char grade;
//}Student;
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//problem 2-2
//�л� ����ü ����
//typedef struct student {
//	//�̸�
//	char name[21];
//	//���� ����
//	int kor;
//	//���� ����
//	int eng;
//	//���� ����
//	int math;
//	//���
//	double avg;
//}Student;
////�Լ� ����
//void read_data(Student* pSt, int n);
//void sort_score(Student* pSt, int n);
//Student* select_out(Student* p, Student* q, int n);
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//problem 3-2
////ȣ�� ����ü ����
//typedef struct hotel {
//	//�̸�, ���, ����, �Ÿ�, �������Կ���
//	char name[31];
//	int level;
//	double reputation;
//	double distance;
//	char includeBreakfast;
//}HOTEL;
////�Լ� ����
//int in_hotel_info(HOTEL *p);
//void out_hotel_info(HOTEL *p, int N, int G, double D);
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//problem 4
//���� ���� ����ü ����
//typedef struct parking_info {
//	//�� ��ȣ, �� ��ȣ, ��ǰ �ڵ�, ����� ���� ����(Y/N), ����� ����, ���� �ð�, ���� ���
//	int carNum;
//	int phoneNum;
//	char product;
//	char isRegular;
//	int regularDay;
//	int parkingTime;
//	double cost = 0;
//}PARKING_INFO;
////�Լ� ����
//void input(PARKING_INFO *p, int n);
//void compute(PARKING_INFO *p);
//void display(PARKING_INFO *p, int n);
//void parking_info_sort(PARKING_INFO *p, int n);
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//problem 5
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
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	//problem 1-2
	////����ü �迭 ����
	//Student stus[5];
	////�ݺ��� ��ȸ�� ����
	//int i,j;
	////5���� �л��� ���� ������ �Է¹޾ƾ��ϹǷ� 5�� �ݺ�
	//for (i = 0; i < 5; i++) {
	//	//�̸�, �й�, ���� �Է�
	//	scanf("%s %s %c",&stus[i].name, &stus[i].id, &stus[i].grade);
	//	//���ۿ� �����ִ� ���๮�� ����
	//	getchar();
	//}
	////ã���� �ϴ� �л��� �̸�, �� �л��� ����, �� �л��� ���г⵵
	//char findName[10], findGrade, findYear[5];
	////�̸� �Է�
	//scanf("%s",&findName);
	//for (i = 0; i < 5; i++) {
	//	//���� �Է¹��� �̸��� ���� �̸��� �л��� ����ü �迭�� �����Ѵٸ�
	//	if (strcmp(findName, stus[i].name)==0) {
	//		//�� �л��� ������ ���г⵵�� ���� ������.
	//		findGrade = stus[i].grade;
	//		strncpy(findYear,stus[i].id,4);
	//	}
	//}
	//findYear[4] = NULL;

	////���ǿ� �´� �л��� �ִ��� ������ ��Ÿ�� ����
	//int chk=0;
	//for (i = 0; i < 5; i++) {
	//	char strYear[5];
	//	strncpy(strYear, stus[i].id, 4);
	//	strYear[4]=NULL;
	//	//���� �Է¹��� �л��� ������ ���� ������ ���� �л��� ã�´ٸ�
	//	if (findGrade == stus[i].grade) {
	//		//�Է¹��� �л��� �ƴϰ�, ���г⵵�� ���ٸ�
	//		if ((strcmp(findName, stus[i].name) != 0) && (strcmp(strYear, findYear)==0)) {
	//			//chk���� �ٲ��ְ� �̸��� ������ش�.
	//			chk=1;
	//			printf("%s ",stus[i].name);
	//		}
	//	}
	//}
	////���� chk���� �ٲ��� �ʾҴٸ� 0�� ���
	//if(!chk)
	//	printf("0\n");
	//printf("\n");
	////ã���� �ϴ� �л��� ���г⵵�� ���г⵵�� 131�� ���� ������ ���
	//int num = atoi(findYear)%131;
	//printf("%s %d",findYear,num);
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	//problem 2-2
	////�л� �� �Է�
	//int n;
	//scanf("%d",&n);
	////����ü �迭 �� ���� ������ ����ü ������ ���� �ΰ�, ���� ����� ������ ���� ����
	//Student st1[49], st2[49], *pSt, *qSt, *finalSt;
	////pSt�� st1��, qSt�� st2�� ����Ű�� ��
	//pSt = st1;
	//qSt = st2;
	////�� ���� ����ü �Է¹���
	//read_data(pSt, n);
	//read_data(qSt, n);
	////�� ����ü ����
	//sort_score(pSt, n);
	//sort_score(qSt, n);
	////�� ����ü �߿��� ���ǿ� �´� ����ü�����͸� ��ȯ�Ͽ� finalSt�� ����
	//finalSt = select_out(pSt, qSt, n);
	////finalSt�� ��ȸ�ϸ� ����Ѵ�.
	//for (Student* iter = finalSt; iter < finalSt + n; iter++) {
	//	printf("%s %d %d %d %.1f\n",iter->name, iter->kor, iter->eng, iter->math, iter->avg);
	//}
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	//problem 3-2
	////����ü �迭�� �� �迭�� ����Ű�� ������ ���� ����
	//HOTEL hotels[100], *pHotel;
	//pHotel = hotels;
	////ȣ�ڵ��� ������ �Է¹ް� �Է¹��� ������ ��ȯ�Ͽ� hotelCnt�� ����.
	//int hotelCnt = in_hotel_info(pHotel);
	//int G;
	//double D;
	////G, D �Է¹���
	//scanf("%d %lf",&G,&D);
	////�Լ��ҷ��ͼ� ������ ���
	//out_hotel_info(pHotel, hotelCnt, G, D);
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	//problem 4
	////����ü �迭 ����
	//PARKING_INFO parkingLot[100];
	////����ü �迭�� ����Ű�� ������ ����
	//PARKING_INFO *p=parkingLot;
	////�� ���� �Է¹���
	//int n;
	//scanf("%d",&n);
	//getchar();
	////�Լ� �ҷ��ͼ� ����ü �迭�� �� ����
	//input(p, n);
	////�迭�� ��ȸ�ϸ� �� ����ü�� ��������� �����
	//for (p = parkingLot; p < parkingLot + n; p++) {
	//	compute(p);
	//}
	////������ �ʱ�ȭ
	//p=parkingLot;
	////����ü �迭 �����Լ� �ҷ���
	//parking_info_sort(p,n);
	////���� �� ���
	//display(p,n);
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	//problem 5

	while (1) {
		//��ɾ� �Է¹���
		char code;
		scanf("%c",&code);
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
		else if(code=='Q'){
			break;
		}
	}
	
}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

////�Է� �Լ�
//void read_data(Student* pSt, int n)
//{
//	//�ݺ��� ��ȸ��	����ü ������ ����
//	Student* iter;
//	for (iter = pSt; iter < pSt + n; iter++) {
//		//n�� �ݺ��ϸ� �Է¹���
//		scanf("%s %d %d %d",&iter->name, &iter->kor, &iter->eng, &iter->math);
//		getchar();
//		//��հ� �ʱ�ȭ����.
//		iter->avg = ((iter->kor) + (iter->eng) + (iter->math))/3.0;
//	}
//}
//
////���� �Լ�
//void sort_score(Student* pSt, int n)
//{
//	//��ȸ�� ����ü ������ ���� �ΰ� ����
//	Student* iter1, *iter2;
//	//iter1�� pSt~������ ����, iter2�� iter1~������ ����.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//���� iter1�� ��հ����� iter2�� ��հ��� �� ũ�ٸ�
//			if (iter1->avg < iter2->avg) {
//				//���� �ٲ��ش�.
//				Student p = *iter1;
//				*iter1 = *iter2;
//				*iter2 = p;
//			}
//		}
//	}
//	//��հ��� ���� ��쿡�� ���������� ū ������ �����ؾ���.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//���� ��հ��� ����,
//			if (iter1->avg == iter2->avg) {
//				//���������� �� ũ�ٸ�
//				if (iter1->kor < iter2->kor) {
//					//�� ����ü�� ���� �ٲ���.
//					Student p = *iter1;
//					*iter1 = *iter2;
//					*iter2 = p;
//				}
//			}
//		}
//	}
//	//��հ��� ����, ������������ ���� ��쿡�� ���������� ū ������ �����ؾ���.
//	for (iter1 = pSt; iter1 < pSt + n; iter1++) {
//		for (iter2 = iter1; iter2 < pSt + n; iter2++) {
//			//��հ��� ����,
//			if (iter1->avg == iter2->avg) {
//				//���������� ���� ��쿡
//				if (iter1->kor == iter2->kor) {
//					//���������� ���Ͽ� �� ����ü�� �ٲ���.
//					if (iter1->eng < iter2->eng) {
//						Student p = *iter1;
//						*iter1 = *iter2;
//						*iter2 = p;
//					}
//				}
//			}
//		}
//	}
//}
//
////���ڷ� ���� �� ����ü �迭 ������ ���� �߿��� �߰� ��� �л��� ����� �� ���� �����͸� ��ȯ��.
//Student* select_out(Student* p, Student* q, int n)
//{
//;	//p�� �߰� ��� �л��� ����� q�� �߰� ��� �л��� ��պ��� ������
//	if ((p+n/2)->avg > (q+n/2)->avg) {
//		//p�� ��ȯ
//		return p;
//	}
//	//�׷��� ���� ��쿡�� q ��ȯ.
//	else if ((p+n/2)->avg < (q+n/2)->avg) {
//		return q;
//	}
//}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

////ȣ�� ���� �Է� �Լ�
//int in_hotel_info(HOTEL* p)
//{	
//	//�Է¹��� ȣ���� ����
//	int hotelCnt=0;
//	while (1) {
//		//�̸��� �Է¹���
//		scanf("%s" ,&p->name);
//		//���� 0�� �ԷµǾ��ٸ� �ݺ��� Ż��
//		if (strcmp(p->name, "0") == 0) {
//			break;
//		}
//		//���, ����, �Ÿ�, �������Կ���(Y/N) �Է¹���
//		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
//		//���๮������
//		getchar();
//		//�Է� ������ ������ ���� 1 ������Ŵ.
//		hotelCnt++;
//		p++;
//	}
//	//���������� �Է� ���� ���� ��ȯ.
//	return hotelCnt;
//}
//
////��¿� �Լ�
//void out_hotel_info(HOTEL* p, int N, int G, double D)
//{
//	//�ݺ��� ��ȸ�� ����ü������ ���� ����
//	HOTEL *iter1, *iter2;
//	//���� ���ǵ��� ���� ������ �����ؾ���
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//�ݺ����� ��ȸ�ϴٰ� iter2�� ������ �� ���ٸ� ���� �ٲ���.
//			if (iter1->reputation < iter2->reputation) {
//				HOTEL tmp = *iter1;
//				*iter1 = *iter2;
//				*iter2 = tmp;
//			}
//		}
//	}
//	//���ǵ� ������ ���ĵ� �迭���� �������� ���� ������ ����
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		for (iter2 = iter1; iter2 < p + N; iter2++) {
//			//���� ���ǵ��� ����
//			if (iter1->reputation == iter2->reputation) {
//				//���������� �����ٸ� ���� �ٲ���.
//				if (strcmp(iter1->name, iter2->name)>0) {
//					HOTEL tmp = *iter1;
//					*iter1 = *iter2;
//					*iter2 = tmp;
//				}
//			}
//		}
//	}
//	//����� G���� ũ�ų� ����, �Ÿ��� D���� �۰ų� ���� ȣ�ڵ��� ������ �����.
//	for (iter1 = p; iter1 < p + N; iter1++) {
//		if (iter1->level >= G) {
//			if (iter1->distance <= D) {
//				printf("%s %d %.1f %.1f %c\n",iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
//			}
//		}
//	}
//}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

////�Է¿� �Լ�
//void input(PARKING_INFO* p, int n)
//{
//	//�ݺ��� ��ȸ�� �����ͺ��� ����
//	PARKING_INFO *iter;
//	for (iter = p; iter < p + n; iter++) {
//		//�� ��ȣ, �� ��ȣ, ��ǰ ���� �Է¹���.
//		scanf("%d %d %c ",&iter->carNum, &iter->phoneNum, &iter->product);
//		//���� ��ǰ������ S���, ����� �������ο� ����� ������ �Է¹���
//		if (iter->product == 'S') {
//			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
//		}
//		//���� �ð� �Է¹���.
//		scanf("%d",&iter->parkingTime);
//		getchar();
//	}
//}
//
////���� ��� ��� �Լ�
//void compute(PARKING_INFO* p)
//{
//	//���� ����� ������ ���� ����� ���� ������ش�.
//	//���� ��ǰ�� S�� ���
//	if (p->product == 'S') {
//		//������� ������ �ִٸ�
//		if (p->isRegular == 'Y') {
//			//�ʰ� �ð��� ���� ��길 �ϸ� �ǹǷ� ���⼭�� �ƹ��۾��� ���� �ʴ´�.
//		}
//		//������� ������ ���� �ʴٸ�
//		else if (p->isRegular == 'N') {
//			//7�� ����� ����� cost�� �߰�����.
//			if (p->regularDay == 7) {
//				p->cost += 30000;
//			}
//			//30�� ����� ����� cost�� �߰�����.
//			else if (p->regularDay == 30) {
//				p->cost += 100000;
//			}
//			//180�� ����� ����� cost�� �߰�����.
//			else if (p->regularDay == 180) {
//				p->cost += 500000;
//			}
//		}
//	}
//	//���� ��ǰ�� D�� ���
//	else if (p->product == 'D') {
//		//���ϱ� ��� 5000���� cost�� �߰����ش�.
//		p->cost += 5000;
//	}
//	//���� �����ð��� 4�ð�, �� 240���� �Ѿ� ���ٸ�
//	if (p->parkingTime > 240) {
//		//240���� �Ѿ�� 10�и��� 200���̹Ƿ� ���� �����ð����� 240�� ���ְ�,
//		int time = (p->parkingTime) - 240;
//		//�� ���� 10���� ���� ���� 200�� ���ؼ� cost�� �����ش�.
//		int tmp = time / 10;
//		p->cost += (tmp * 200);
//	}
//}
//
////��¿� �Լ�
//void display(PARKING_INFO* p, int n)
//{
//	//�ݺ��� ��ȸ�� �����ͺ���
//	PARKING_INFO *iter;
//	//���ϱ� ��� �հ�, ����� ��� �հ踦 ������ ����
//	double Dsum=0, Ssum=0;
//	for (iter = p; iter < p + n; iter++) {
//		//�ݺ��� ��ȸ�ϸ鼭 �� ��ȣ, �� ��ȣ, ��ǰ ����, ���� ��� ������ش�.
//		printf("%d %d %c %.0f\n",iter->carNum, iter->phoneNum, iter->product, iter->cost);
//		//��ǰ ������ D��� ���ϱ� ����հ迡 ���� ����� �����ְ�
//		if(iter->product == 'D')
//			Dsum += iter->cost;
//		//��ǰ ������ S��� ����� ����հ迡 ���� ����� �����ش�.
//		else if(iter->product == 'S')
//			Ssum += iter->cost;
//	}
//	//D�հ�, S�հ�, ���� ��� ����(D+S)�� ������ش�.
//	printf("%.1f %.1f %.1f",Dsum,Ssum, Dsum+Ssum);
//}
//
////���� ���� ���� �Լ�
//void parking_info_sort(PARKING_INFO* p, int n)
//{
//	//�ݺ��� ��ȸ�� ���� ����
//	PARKING_INFO *x, *y;
//	//���� ��ǰ ������� �������ش�.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//D�� ���� ������, �� ���� S�� ���;���.
//			if (x->product > y->product) {
//				PARKING_INFO tmp = *x;
//				*x = *y;
//				*y = tmp;
//			}
//		}
//	}
//	//��ǰ ������� �����ϰ� ���� �� ��ȣ��� �������ش�.
//	for (x = p; x < p + n; x++) {
//		for (y = x; y < p + n; y++) {
//			//��ǰ�� ������ ���� ��쿡
//			if (x->product == y->product) {
//				//�� ��ȣ��� �������ش�.
//				if (x->carNum > y->carNum) {
//					PARKING_INFO tmp = *x;
//					*x = *y;
//					*y = tmp;
//				}
//			}
//		}
//	}
//	
//}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

//�Է� �Լ�
void inputStudent()
{	
	//�л� ����ü���� ����
	Student tmp;
	//��� ���� 0���� �ʱ�ȭ
	tmp.point=0;
	//�̸�, �й�, ���� �� �Է¹���
	scanf("%s %d %d",&tmp.name, &tmp.id, &tmp.gradeCnt);
	//���� �� ��ŭ �ݺ��ؼ� �����̸��� �� ������ ���� �Է¹���
	for (int i = 0; i < tmp.gradeCnt; i++) {
		double p;
		scanf("%s %lf",&tmp.grade[i], &p);
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
	int i,j;
	//���ο� �迭�� ����ü ����
	for (i = 0; i < cnt; i++) {
		newArr[i] = arr[i];
	}
	//���ο� �迭�� �̸� ������ �������ش�.
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			//���� �̸��� ���� ������ ���̶��
			if (strcmp(newArr[i].name, newArr[j].name)>0) {
				//����ü ����� �ٲ��ش�.
				Student tmp = newArr[i];
				newArr[i] = newArr[j];
				newArr[j] = tmp;
			}
		}
	}
	//����Լ� �ҷ��ͼ� ���ο� �迭 ���
	printStudent(newArr,cnt);
}

//�л� ���� �Լ�
void deleteStudent()
{
	//�����ϰ��� �ϴ� �̸��� �Է¹��� ����
	char findName[31];
	//�̸� �Է¹ް� ���๮�� ����
	scanf("%s",&findName);
	getchar();
	for (int i = 0; i < studentCnt; i++) {
		//�迭 ��ȸ �ϸ鼭 �Է� ���� �̸��� ã�� ���
		if (strcmp(students[i].name, findName) == 0) {
			//ã�� ��ġ���� �迭�� ������ �� ĭ�� ������ ���.
			for (int j = i; j < studentCnt-1; j++) {
				students[j] = students[j+1];
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
		printf("%s %d %d %.2f\n",arr[i].name, arr[i].id, arr[i].gradeCnt, arr[i].point/arr[i].gradeCnt);
	}
}
