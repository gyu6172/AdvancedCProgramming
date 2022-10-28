#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
	char name[8];
	int kor,eng,math;
	double avg;
}Student;
typedef struct st {
	char *str;
	int cnt;
}St;
int main() {
	//problem 1
	//int n,i;
	//scanf("%d",&n);
	//int *p=(int*)malloc(sizeof(int)*n);
	//for (i = 0; i < n; i++) {
	//	scanf("%d",&p[i]);
	//}
	//int sum=0;
	//for (i = 0; i < n; i++) {
	//	sum += p[i];
	//}
	//printf("%d",sum);
	//free(p);



	//problem 2
	//int n;
	//int i;
	//scanf("%d", &n);
	//float* p = (float*)malloc(sizeof(float) * n);
	//for (i = 0; i < n; i++) {
	//	scanf("%f", p+i);
	//}
	//
	//float max=p[0];
	//for (i = 0; i < n; i++) {
	//	if(max < p[i])
	//		max = p[i];
	//}
	//printf("%.2lf",max);
	//free(p);


	
	//problem 3(OJ에서 X)
	//int n,i,d;
	//scanf("%d",&n);
	//int *p = (int*)malloc(sizeof(int)*n);
	//for (i = 0; i < n; i++) {
	//	scanf("%d",(p+i));
	//}
	//scanf("%d",&d);
	//realloc(p, n-d);
	//for (i = 0; i < n - d; i++) {
	//	printf("%d\n",*(p+i));
	//}
	//free(p);




	//problem 3
	//int n,i,j;
	//char c1,c2;
	//int cnt1=0, cnt2=0;
	//scanf("%d",&n);
	//getchar();
	//char *pStr = (char*)malloc(sizeof(char)*(n+1));
	//scanf("%s",pStr);
	//getchar();
	//scanf("%c %c",&c1, &c2);
	//for (i = 0; i < n; i++) {
	//	if(c1==pStr[i])
	//		cnt1++;
	//	if(c2==pStr[i])
	//		cnt2++;
	//}
	//printf("%d %d",cnt1,cnt2);
	//free(pStr);




	//problem 4
	//int n,i;
	//scanf("%d",&n);
	//getchar();
	//Student *stus = (Student*)malloc(sizeof(Student)*n);
	//for (i = 0; i < n; i++) {
	//	scanf("%s %d %d %d",&(stus+i)->name, &(stus+i)->kor, &(stus+i)->eng, &(stus+i)->math);
	//	(stus+i)->avg = ((stus[i].kor)+(stus[i].eng)+(stus[i].math))/3.0;
	//	getchar();
	//}
	//for (i = 0; i < n; i++) {
	//	printf("%s %.1f ", stus[i].name, stus[i].avg);
	//	if ((stus[i].kor >= 90) || (stus[i].eng >= 90) || (stus[i].math >= 90)) {
	//		printf("GREAT ");
	//	}
	//	if ((stus[i].kor < 70) || (stus[i].eng < 70) || (stus[i].math < 70)) {
	//		printf("BAD");
	//	}
	//	printf("\n");
	//}
	//free(stus);



	//problem 5
	//int n,i,j;
	//scanf("%d",&n);
	//int *arr = (int*)malloc(sizeof(int)*n);
	//for (i = 0; i < n; i++) {
	//	scanf("%d",&arr[i]);
	//}
	//for (i = 0; i < n - 1; i++) {
	//	if (arr[i] > arr[i + 1]) {
	//		int tmp = arr[i];
	//		arr[i] = arr[i+1];
	//		arr[i+1] = tmp;
	//	}
	//}
	//for (i = 0; i < n; i++) {
	//	printf("%d\n",arr[i]);
	//}
	//free(arr);




	//problem 6
	//int n;
	//scanf("%d",&n);
	//char *str = (char*)malloc(sizeof(char)*(n+1));
	//getchar();
	//scanf("%s",str);
	//int cnt=0;
	//for (int i = 0; i < n; i++) {
	//	if (str[i] == 'c' && str[i + 1] == 'a' && str[i+2] == 't') {
	//		cnt++;
	//	}
	//}
	//printf("%d",cnt);
	//free(str);





	//problem 7
	//int x,y,i,j;
	//scanf("%d %d",&x, &y);
	//int **p=(int**)malloc(sizeof(int*)*y);
	//for (i = 0; i < y; i++) {
	//	p[i]=(int*)malloc(sizeof(int*)*x);
	//}
	//char a='a';
	//for (i = 0; i < y; i++) {
	//	for (j = 0; j < x; j++) {
	//		p[i][j] = a;
	//		if (a == 'z') {
	//			a='A'-1;
	//		}
	//		else if (a == 'Z') {
	//			a='a'-1;
	//		}
	//		a++;
	//	}
	//}
	//for (i = 0; i < y; i++) {
	//	for (j = 0; j < x; j++) {
	//		printf("%c ",p[i][j]);
	//	}
	//	printf("\n");
	//}
	//for (i = 0; i < y; i++) {
	//	free(p[i]);
	//}
	//free(p);





	//9주차 실습문제
	int n,i,j,k;
	scanf("%d",&n);
	St *strs = (St*)malloc(sizeof(St)*n);
	char tmpStr[101];
	for (i = 0; i < n; i++) {
		strs[i].str = (char*)malloc(sizeof(char)*101);
	}
	for (i = 0; i < n; i++) {
		int cnt=0;
		getchar();
		scanf("%s", tmpStr);
		strcpy((strs+i)->str, tmpStr);
		for (j = 0; j < strlen(tmpStr); j++) {
			if (tmpStr[j] != 'a' && tmpStr[j] != 'e' && tmpStr[j] != 'i' && tmpStr[j] != 'o' && tmpStr[j] != 'u') {
				cnt++;
			}
		}
		(strs+i)->cnt = cnt;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (strs[i].cnt > strs[j].cnt) {
				St tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %d\n",strs[i].str,strs[i].cnt);
	}
	for (i = 0; i < n; i++) {
		free(strs[i].str);
	}
	free(strs);








}