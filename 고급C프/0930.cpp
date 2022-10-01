#include <stdio.h>
#include <string.h>
int check(char *p);
struct vector {
	int x;
	int y;
	int z;
};
struct time {
	int h;
	int m;
	int s;
};
typedef struct student {
	char name[10];
	char id[11];
	char grade;
}Student;
int main() {
	//problem 9
	//char str[31];
	//scanf("%s",str);
	//printf("%d %d",strlen(str),check(str));



	//problem 10
	//int n,i;
	//int min=100;
	//char minstr[200];
	//scanf("%d",&n);
	//getchar();
	//for (i = 0; i < n; i++) {
	//	char str[101];
	//	gets_s(str);
	//	if (strlen(str) < min) {
	//		min = strlen(str);
	//		strcpy(minstr,str);
	//	}
	//}
	//printf("%s",minstr);



	
	//problem 11
	//char str1[81], str2[11];
	//scanf("%s",str1);
	//getchar();
	//scanf("%s", str2);
	//int i,j;
	//int str1Len = strlen(str1);
	//int str2Len = strlen(str2);

	//for (i = 0; i < str1Len; i++) {
	//	if (str1[i] == str2[0]) {
	//		int chk=1;
	//		for (j = 0; j < str2Len; j++) {
	//			if (str1[i + j] != str2[j]) {
	//				chk=0;
	//			}
	//		}
	//		if (chk == 1) {
	//			printf("%d 1",str1Len);
	//			return 0;
	//		}
	//	}
	//}
	//printf("%d 0",str1Len);



	//problem 12
	//char str1[101], str2[101];
	//gets_s(str1);
	//scanf("%s",str2);
	//int str1Len = strlen(str1);
	//int str2Len = strlen(str2);
	//int i,j,k;
	//int cnt=0;
	//for (i = 0; i < str1Len; i++) {
	//	if (str1[i] == str2[0]) {
	//		int chk=1;
	//		for (j = 0; j < str2Len; j++) {
	//			if (str1[i + j] != str2[j]) {
	//				chk=0;
	//				break;
	//			}
	//		}
	//		if (chk) {
	//			cnt++;
	//			i+=str2Len-1;
	//		}
	//	}
	//}
	//printf("%d",cnt);




	//구조체
	//problem 1
	//struct vector v1,v2,v3;
	//scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
	//scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
	//v3.x = v1.x * v2.x;
	//v3.y = v1.y * v2.y;
	//v3.z = v1.z * v2.z;
	//printf("%d %d %d\n%d",v3.x,v3.y,v3.z,(v3.x+v3.y+v3.z));


	//problem 2
	//struct time t1, t2,t3;
	//scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	//scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	//t3.h = t2.h - t1.h;
	//if (t1.m > t2.m) {
	//	t3.h--;
	//	t3.m = t2.m - t1.m + 60;
	//}
	//else {
	//	t3.m = t2.m - t1.m;
	//}
	//if (t1.s > t2.s) {
	//	t3.m--;
	//	t3.s = t2.s - t1.s + 60;
	//}
	//else {
	//	t3.s = t2.s - t1.s;
	//}
	//printf("%d %d %d",t3.h,t3.m,t3.s);




	//실습문제
	//problem 1
	//Student stu[5];
	//int i,j;
	//for (i = 0; i < 5; i++) {
	//	scanf("%s %s %c",&stu[i].name, &stu[i].id, &stu[i].grade);
	//	getchar();
	//}
	//
	//char name[10];
	//scanf("%s",name);

	//for (i = 0; i < 5; i++) {
	//	if (!strcmp(name, stu[i].name)) {
	//		printf(" %s %c\n",stu[i].id, stu[i].grade);
	//	}
	//}


	

	//problem 2
	char str[201], maxLenStr[401], nowStr[401];
	gets_s(str);
	int len=strlen(str);
	int i;
	int maxCnt=0;
	int nowCnt=0;
	for (i = 0; i < len; i++) {
		if (str[i] != ' ') {
			nowStr[nowCnt] = str[i];
			nowCnt++;
		}
		else {
			if (nowCnt > maxCnt) {
				maxCnt = nowCnt;
				//nowStr[nowCnt] = NULL;
				strcpy(maxLenStr,nowStr);
			}
			nowCnt = 0;
		}
	}
	if (nowCnt > maxCnt) {
		maxCnt = nowCnt;
		//nowStr[nowCnt] = NULL;
		strcpy(maxLenStr, nowStr);
	}
	printf("%s",maxLenStr);






}

int check(char* p)
{
	int len = strlen(p);
	char *q = p+len-1;
	for (;p<q;p++,q--) {
		if (*p != *q) {
			return 0;
		}
	}
	return 1;
}
