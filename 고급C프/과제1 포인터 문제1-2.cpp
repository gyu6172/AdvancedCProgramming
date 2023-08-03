#include <stdio.h>
int* MAX(int ar[]);
int* MIN(int ar[]);
int main() {
	//�� ���� �Է¹��� ���� n ����
	int n;
	//�� �� �Է¹���
	scanf("%d", &n);
	int i, j;

	//n�� �ݺ��ϸ� �Է¹���.
	for (i = 0; i < n; i++) {
		//�Է¿� ���� a
		int a;
		//�Է¹��� ������ ����� �迭 arr
		int arr[100];
		//�迭 arr�� ũ�⸦ �˷��ִ� ���� arrIter
		int arrIter = 0;
		while (1) {
			//a �Է¹���
			scanf("%d", &a);
			//arr�� a�� ����
			arr[arrIter] = a;
			//�迭 ũ�� 1������Ŵ.
			arrIter++;
			//���� 0�� �Է��ߴٸ� break�� �ݺ��� Ż���Ͽ� �Է��� �׸�����
			if (a == 0)
				break;
		}
		//maxPos�� minPos���� ���� �迭�� �ִ��� �ּ�, �ּڰ��� �ּҰ� �����.
		int* maxPos = MAX(arr);
		int* minPos = MIN(arr);
		//���� �ּڰ��� �ִ񰪺��� �ڿ� �ִٸ�
		if (minPos > maxPos + 1) {
			int* p;
			//�ִ� ���� ������ �ּڰ� �ٷ� �� ������ ���.
			for (p = maxPos + 1; p < minPos; p++) {
				printf("%d ", *p);
			}
		}
		//���� �ִ��� �ּڰ����� �ڿ� �ִٸ�
		else if (minPos + 1 < maxPos) {
			int* p;
			//�ּڰ� ���� ������ �ִ� �ٷ� �� ������ ���.
			for (p = minPos + 1; p < maxPos; p++) {
				printf("%d ", *p);
			}
		}
		//�� ���� ���(�ִ񰪰� �ּڰ��� ���ų�, �ִ񰪰� �ּڰ��� �پ��ִ� ���)����
		else {
			//none ���
			printf("none");
		}
		printf("\n");
	}
}
//�迭�� ���ڷ� �ǳ��޾� �� �迭�� �ִ��� �ּҸ� ��ȯ�ϴ� �Լ�
int* MAX(int ar[])
{
	//�迭 ��ȸ�� ������ ���� p
	int* p;
	//�ִ��� �ּҰ� ����� ����. �迭�� ù��° ������ �ʱ�ȭ ��Ŵ.
	int* max = ar;
	for (p = ar; *p != 0; p++) {
		//�迭�� ��ȸ�ϸ� �ִ񰪺��� ū ���� ���� ���
		if (*max < *p) {
			//max�� �� ���� �ּҷ� �ٲ۴�.
			max = p;
		}
	}
	//�ִ��� �ּ� ����
	return max;
}

//�迭�� �ּڰ��� �ּҸ� ��ȯ�ϴ� �Լ�
int* MIN(int ar[])
{
	//�迭 ��ȸ�� ������ ���� p
	int* p;
	//�ּڰ��� �ּҰ� ����� �����ͺ��� min. �迭�� �ּҷ� �ʱ�ȭ��Ŵ.
	int* min = ar;
	for (p = ar; *p != 0; p++) {
		//�ݺ����� ��ȸ�ϴٰ� ���� �ּڰ����� ���� ���� ������
		if (*min > *p) {
			//�ּڰ��� �ּҸ� �ٲ��ش�.
			min = p;
		}
	}
	return min;
}