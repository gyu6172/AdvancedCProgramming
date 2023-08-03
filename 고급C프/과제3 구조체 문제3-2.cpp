#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ȣ�� ����ü ����
typedef struct hotel {
	//�̸�, ���, ����, �Ÿ�, �������Կ���
	char name[31];
	int level;
	double reputation;
	double distance;
	char includeBreakfast;
}HOTEL;
//�Լ� ����
int in_hotel_info(HOTEL* p);
void out_hotel_info(HOTEL* p, int N, int G, double D);
int main() {
	//����ü �迭�� �� �迭�� ����Ű�� ������ ���� ����
	HOTEL hotels[100], * pHotel;
	pHotel = hotels;
	//ȣ�ڵ��� ������ �Է¹ް� �Է¹��� ������ ��ȯ�Ͽ� hotelCnt�� ����.
	int hotelCnt = in_hotel_info(pHotel);
	int G;
	double D;
	//G, D �Է¹���
	scanf("%d %lf", &G, &D);
	//�Լ��ҷ��ͼ� ������ ���
	out_hotel_info(pHotel, hotelCnt, G, D);
}
//ȣ�� ���� �Է� �Լ�
int in_hotel_info(HOTEL* p)
{
	//�Է¹��� ȣ���� ����
	int hotelCnt = 0;
	while (1) {
		//�̸��� �Է¹���
		scanf("%s", &p->name);
		//���� 0�� �ԷµǾ��ٸ� �ݺ��� Ż��
		if (strcmp(p->name, "0") == 0) {
			break;
		}
		//���, ����, �Ÿ�, �������Կ���(Y/N) �Է¹���
		scanf("%d %lf %lf %c", &p->level, &p->reputation, &p->distance, &p->includeBreakfast);
		//���๮������
		getchar();
		//�Է� ������ ������ ���� 1 ������Ŵ.
		hotelCnt++;
		p++;
	}
	//���������� �Է� ���� ���� ��ȯ.
	return hotelCnt;
}

//��¿� �Լ�
void out_hotel_info(HOTEL* p, int N, int G, double D)
{
	//�ݺ��� ��ȸ�� ����ü������ ���� ����
	HOTEL* iter1, * iter2;
	//���� ���ǵ��� ���� ������ �����ؾ���
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			//�ݺ����� ��ȸ�ϴٰ� iter2�� ������ �� ���ٸ� ���� �ٲ���.
			if (iter1->reputation < iter2->reputation) {
				HOTEL tmp = *iter1;
				*iter1 = *iter2;
				*iter2 = tmp;
			}
		}
	}
	//���ǵ� ������ ���ĵ� �迭���� �������� ���� ������ ����
	for (iter1 = p; iter1 < p + N; iter1++) {
		for (iter2 = iter1; iter2 < p + N; iter2++) {
			//���� ���ǵ��� ����
			if (iter1->reputation == iter2->reputation) {
				//���������� �����ٸ� ���� �ٲ���.
				if (strcmp(iter1->name, iter2->name) > 0) {
					HOTEL tmp = *iter1;
					*iter1 = *iter2;
					*iter2 = tmp;
				}
			}
		}
	}
	//����� G���� ũ�ų� ����, �Ÿ��� D���� �۰ų� ���� ȣ�ڵ��� ������ �����.
	for (iter1 = p; iter1 < p + N; iter1++) {
		if (iter1->level >= G) {
			if (iter1->distance <= D) {
				printf("%s %d %.1f %.1f %c\n", iter1->name, iter1->level, iter1->reputation, iter1->distance, iter1->includeBreakfast);
			}
		}
	}
}