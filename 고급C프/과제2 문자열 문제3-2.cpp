#include <stdio.h>
#include <string.h>
int main() {
	//���ڿ� 1�� ����� str1�� ���ڿ� 2�� ����� str2 ����
	char str1[101], str2[101];
	//str1�� str2 �Է¹���
	gets_s(str1);
	gets_s(str2);

	//str1�� �� �ܾ ����� 2���� �迭 strArr
	char strArr[20][201];
	//str1�� ���� ����
	int len = strlen(str1);
	//�ݺ��� ��ȸ�� ���� ����
	int i, j;
	//strArr�� ���� �����Ҷ� ����� ���� x�� y
	int x = 0, y = 0;
	//str1�� ó������ ������ �ݺ��� ��ȸ
	for (i = 0; i < len; i++) {
		//�ܾ�� �����̳� .���� ���������Ƿ� ���� str1�� ��ȸ�ϴٰ� �����̳� .�� ������ ���
		if (str1[i] == ' ' || str1[i] == '.') {
			//strArr�� �������� �ι��� �߰�
			strArr[y][x] = NULL;
			//x�� �ʱ�ȭ�ϰ� y�� 1������Ŵ
			x = 0;
			y++;
			continue;
		}
		//�����̳� .�� ������ �ʴ´ٸ� �׳� strArr�� ���� �߰�
		strArr[y][x] = str1[i];
		x++;
	}
	//�������� �ι��� �߰����ش�.
	strArr[y][x] = NULL;
	y++;
	//��ġ�ϴ� �ܾ��� ������ ����� ���� cnt
	int cnt = 0;
	for (i = 0; i < y; i++) {
		//strArr�� ����� �ܾ���� str2�� ���ϸ鼭 ���� ���ٸ� cnt 1����
		if (strcmp(strArr[i], str2) == 0)
			cnt++;
	}
	//���� cnt���
	printf("%d", cnt);
}