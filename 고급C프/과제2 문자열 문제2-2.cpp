#include <stdio.h>
#include <string.h>
int main() {
	//������ ������ ���ڿ��� ����� �迭 str, ���Ӱ� �Է¹��� �ܾ ����� �迭 addWord, �������� ����� �迭 resultArr
	char str[4001], addWord[201], resultArr[4001] = "";
	//str�� addWord �Է¹���.
	gets_s(str);
	gets_s(addWord);
	//str�� �ܾ� ������ �и��Ͽ� 2���� �迭�� strArr�� ������.
	char strArr[20][201];
	//str�� ���� ����
	int len = strlen(str);
	//�ݺ��� ��ȸ�� ���� �̸� ����
	int i, j;
	//strArr�� ���ڿ��� ������ �� ����� ���� x�� y
	int x = 0, y = 0;
	//str�� ù ���ں��� ������ ���ڱ��� ��ȸ ��.
	for (i = 0; i < len; i++) {
		//���� ������ ���Դٸ�,
		if (str[i] == ' ') {
			//�� �ܾ��� �������� �ι��� �߰��ϰ�,
			strArr[y][x] = NULL;
			//x�� 0���� �ʱ�ȭ ��Ű�� y 1������Ŵ.
			x = 0;
			y++;
			continue;
		}
		//������ ������ �ʾҴٸ� 2���� �迭�� ���� ����.
		strArr[y][x] = str[i];
		x++;
	}
	//�������� �ι��� �߰�����.
	strArr[y][x] = NULL;
	y++;
	//���� �Է¹��� �ܾ 2���� �迭�� �ִ��� ������ �˷��� ����
	int chk = 0;
	//strArr�� ��ȸ�ϸ�
	for (i = 0; i < y; i++) {
		//���� addWord�� ������ �ܾ strArr�� �ִٸ�, chk�� 1�� �ٲ�
		if (strcmp(addWord, strArr[i]) == 0) {
			chk = 1;
		}
	}
	//���� chk�� 0�̶��, �� strArr�� addWord�� ���ٸ�,
	if (!chk) {
		//strArr �������� addWord�� �߰����ش�.
		strcpy(strArr[y], addWord);
		y++;
	}
	//strArr���
	for (i = 0; i < y; i++) {
		printf("%s\n", strArr[i]);
	}
	//��������� �����ϴ� �ڵ�
	//strcmp(s1,s2)�� s1>s2�̸� 1, s1==s2�̸� 0, s1<s2�̸� -1�� ��ȯ��.
	for (i = 0; i < y; i++) {
		for (j = i; j < y; j++) {
			//strArr[i] > strArr[j] ���, �� �ܾ��� ��ġ�� �ٲ��ش�.
			if (strcmp(strArr[i], strArr[j]) > 0) {
				char tmp[21];
				strcpy(tmp, strArr[i]);
				strcpy(strArr[i], strArr[j]);
				strcpy(strArr[j], tmp);
			}
		}
	}
	//�������� ����� ���ڿ� �� �ڿ� strArr�� �� �ܾ���� �̾���̰�, ���鵵 ���� ����
	for (i = 0; i < y; i++) {
		strcat(resultArr, strArr[i]);
		strcat(resultArr, " ");
	}
	//���� ����� ���
	printf("%s", resultArr);
}