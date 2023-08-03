#include <stdio.h>
typedef struct student {
	char name[10];
	int score;
}Student;
Student* select_min(Student* p);
int main() {
	Student stus[5], *rst;
	int i,j;
	for (i = 0; i < 5; i++) {
		scanf("%s %d",&stus[i].name, &stus[i].score);
		getchar();
	}
	rst = select_min(stus);
	printf("%s %d",rst->name, rst->score);

}

Student* select_min(Student* p)
{
	Student* iter, *rst;
	int min=100;
	for (iter = p;iter<p+5; iter++) {
		if (min > iter->score) {
			min = iter->score;
			rst = iter;
		}
	}
	return rst;
}
