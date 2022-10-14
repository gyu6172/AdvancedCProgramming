#include <stdio.h>
typedef struct student {
	int kor,eng,math;
	char name[21];
	double avg;
}Student;
typedef struct average {
	double kor,eng,math;
}Average;
Average calculate_avg(Student* st, int n);
int main() {
	int n, i, j;
	int korCnt=0, engCnt=0, mathCnt=0;
	scanf("%d",&n);
	getchar();
	Student stus[50];
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d",&stus[i].name, &stus[i].kor, &stus[i].eng, &stus[i].math);
		getchar();
		stus[i].avg = (stus[i].kor + stus[i].eng + stus[i].math)/3.0;
	}
	Average rst = calculate_avg(stus, n);
	printf("%.1f %.1f %.1f\n",rst.kor, rst.eng, rst.math);
	for (i = 0; i < n; i++) {
		if(stus[i].kor < rst.kor)
			korCnt++;
		if (stus[i].eng < rst.eng)
			engCnt++;
		if (stus[i].math < rst.math)
			mathCnt++;
	}
	printf("%d %d %d",korCnt, engCnt, mathCnt);
	
}

Average calculate_avg(Student* st, int n)
{
	double korSum=0, engSum=0, mathSum=0;
	Student *p;
	for (p = st; p < st + n; p++) {
		korSum += p->kor;
		engSum += p->eng;
		mathSum += p->math;
	}
	Average tmp;
	tmp.kor = korSum/n;
	tmp.eng = engSum/n;
	tmp.math = mathSum/n;
	return tmp;
}
