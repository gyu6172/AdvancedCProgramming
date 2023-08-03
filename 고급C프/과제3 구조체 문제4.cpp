#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//���� ���� ����ü ����
typedef struct parking_info {
	//�� ��ȣ, �� ��ȣ, ��ǰ �ڵ�, ����� ���� ����(Y/N), ����� ����, ���� �ð�, ���� ���
	int carNum;
	int phoneNum;
	char product;
	char isRegular;
	int regularDay;
	int parkingTime;
	double cost = 0;
}PARKING_INFO;
//�Լ� ����
void input(PARKING_INFO* p, int n);
void compute(PARKING_INFO* p);
void display(PARKING_INFO* p, int n);
void parking_info_sort(PARKING_INFO* p, int n);
int main() {
	//����ü �迭 ����
	PARKING_INFO parkingLot[100];
	//����ü �迭�� ����Ű�� ������ ����
	PARKING_INFO* p = parkingLot;
	//�� ���� �Է¹���
	int n;
	scanf("%d", &n);
	getchar();
	//�Լ� �ҷ��ͼ� ����ü �迭�� �� ����
	input(p, n);
	//�迭�� ��ȸ�ϸ� �� ����ü�� ��������� �����
	for (p = parkingLot; p < parkingLot + n; p++) {
		compute(p);
	}
	//������ �ʱ�ȭ
	p = parkingLot;
	//����ü �迭 �����Լ� �ҷ���
	parking_info_sort(p, n);
	//���� �� ���
	display(p, n);
}

//�Է¿� �Լ�
void input(PARKING_INFO* p, int n)
{
	//�ݺ��� ��ȸ�� �����ͺ��� ����
	PARKING_INFO* iter;
	for (iter = p; iter < p + n; iter++) {
		//�� ��ȣ, �� ��ȣ, ��ǰ ���� �Է¹���.
		scanf("%d %d %c ", &iter->carNum, &iter->phoneNum, &iter->product);
		//���� ��ǰ������ S���, ����� �������ο� ����� ������ �Է¹���
		if (iter->product == 'S') {
			scanf("%c %d ", &iter->isRegular, &iter->regularDay);
		}
		//���� �ð� �Է¹���.
		scanf("%d", &iter->parkingTime);
		getchar();
	}
}

//���� ��� ��� �Լ�
void compute(PARKING_INFO* p)
{
	//���� ����� ������ ���� ����� ���� ������ش�.
	//���� ��ǰ�� S�� ���
	if (p->product == 'S') {
		//������� ������ �ִٸ�
		if (p->isRegular == 'Y') {
			//�ʰ� �ð��� ���� ��길 �ϸ� �ǹǷ� ���⼭�� �ƹ��۾��� ���� �ʴ´�.
		}
		//������� ������ ���� �ʴٸ�
		else if (p->isRegular == 'N') {
			//7�� ����� ����� cost�� �߰�����.
			if (p->regularDay == 7) {
				p->cost += 30000;
			}
			//30�� ����� ����� cost�� �߰�����.
			else if (p->regularDay == 30) {
				p->cost += 100000;
			}
			//180�� ����� ����� cost�� �߰�����.
			else if (p->regularDay == 180) {
				p->cost += 500000;
			}
		}
	}
	//���� ��ǰ�� D�� ���
	else if (p->product == 'D') {
		//���ϱ� ��� 5000���� cost�� �߰����ش�.
		p->cost += 5000;
	}
	//���� �����ð��� 4�ð�, �� 240���� �Ѿ� ���ٸ�
	if (p->parkingTime > 240) {
		//240���� �Ѿ�� 10�и��� 200���̹Ƿ� ���� �����ð����� 240�� ���ְ�,
		int time = (p->parkingTime) - 240;
		//�� ���� 10���� ���� ���� 200�� ���ؼ� cost�� �����ش�.
		int tmp = time / 10;
		p->cost += (tmp * 200);
	}
}

//��¿� �Լ�
void display(PARKING_INFO* p, int n)
{
	//�ݺ��� ��ȸ�� �����ͺ���
	PARKING_INFO* iter;
	//���ϱ� ��� �հ�, ����� ��� �հ踦 ������ ����
	double Dsum = 0, Ssum = 0;
	for (iter = p; iter < p + n; iter++) {
		//�ݺ��� ��ȸ�ϸ鼭 �� ��ȣ, �� ��ȣ, ��ǰ ����, ���� ��� ������ش�.
		printf("%d %d %c %.0f\n", iter->carNum, iter->phoneNum, iter->product, iter->cost);
		//��ǰ ������ D��� ���ϱ� ����հ迡 ���� ����� �����ְ�
		if (iter->product == 'D')
			Dsum += iter->cost;
		//��ǰ ������ S��� ����� ����հ迡 ���� ����� �����ش�.
		else if (iter->product == 'S')
			Ssum += iter->cost;
	}
	//D�հ�, S�հ�, ���� ��� ����(D+S)�� ������ش�.
	printf("%.1f %.1f %.1f", Dsum, Ssum, Dsum + Ssum);
}

//���� ���� ���� �Լ�
void parking_info_sort(PARKING_INFO* p, int n)
{
	//�ݺ��� ��ȸ�� ���� ����
	PARKING_INFO* x, * y;
	//���� ��ǰ ������� �������ش�.
	for (x = p; x < p + n; x++) {
		for (y = x; y < p + n; y++) {
			//D�� ���� ������, �� ���� S�� ���;���.
			if (x->product > y->product) {
				PARKING_INFO tmp = *x;
				*x = *y;
				*y = tmp;
			}
		}
	}
	//��ǰ ������� �����ϰ� ���� �� ��ȣ��� �������ش�.
	for (x = p; x < p + n; x++) {
		for (y = x; y < p + n; y++) {
			//��ǰ�� ������ ���� ��쿡
			if (x->product == y->product) {
				//�� ��ȣ��� �������ش�.
				if (x->carNum > y->carNum) {
					PARKING_INFO tmp = *x;
					*x = *y;
					*y = tmp;
				}
			}
		}
	}

}