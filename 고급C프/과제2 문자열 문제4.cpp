#include <stdio.h>
#include <string.h>
int s_check(char* p, char* q);

int main() {
	//m�� k1, k2, �ݺ��� ��ȸ�� ���� ����
	int m, k1, k2, i, j;
	//m�Է¹���
	scanf("%d", &m);
	//k1�� k2�Է¹���
	scanf("%d %d", &k1, &k2);
	//���ۿ� �����ִ� ���๮�� ����
	getchar();
	//m�� ���ڿ��� �ݺ��ؼ� �Է¹���.
	for (i = 0; i < m; i++) {
		//�Է¹��� ���ڰ� ����� ���� str
		char str[201];
		//�Լ��� �ѱ� �����ͺ��� ����
		char* p, * q;
		//str�Է¹���
		gets_s(str);
		//p�� q�ʱ�ȭ
		p = str + k1;
		q = str + k2;
		//���� k2�� str�� ���̺��� ��ٸ�
		if (k2 > strlen(str))
			//q�� str�� ������ ���ڸ� ����Ű������.
			q = str + strlen(str);
		//s_chkeck�� ��ȯ���� 0�̸� ��¿��� �����ؾ���
		if (s_check(p, q) != 0) {
			//0�� �ƴ� ��� ����Ѵ�.
			printf("%d\n", s_check(p, q));
		}
	}
}

int s_check(char* p, char* q)
{
	//�ҹ����� ������ ����� ���� cnt
	int cnt = 0;
	//�ݺ��� ��ȸ�� �����ͺ��� iter
	char* iter;
	//p���� q����(q����) �ݺ��� ��ȸ��.
	for (iter = p; iter <= q; iter++) {
		//���� iter�� ����Ű�� ���ڰ� �ҹ��ڶ�� cnt 1������Ŵ
		if ('a' <= *iter && *iter <= 'z')
			cnt++;
	}
	//cnt�� ��ȯ
	return cnt;
}