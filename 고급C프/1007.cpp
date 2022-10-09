#include <stdio.h>
#include<string.h>
struct student {
	char belong[51];
	char id[10];

};
struct stud {
	char dept[50];
	char id[10];
};
struct number {
	int n;
	int order;
};
typedef struct complex {
	double real;
	double img;
}Complex;

Complex add(Complex i1, Complex i2);
//problem 3
//struct student {
//	char name[10];
//	int score;
//};

//problem 4,5
//struct student {
//	char name[20];
//	int t1,t2,t3;
//	double avg;
//	char grade;
//};

//problem 6
//struct student {
//	int gender;
//	int weight;
//	int height;
//};
int main() {
	//problem 3
	//struct student stu[5];
	//int i;
	//int sum=0;
	//for (i = 0; i < 5; i++) {
	//	scanf("%s %d", &stu[i].name, &stu[i].score);
	//	sum += stu[i].score;
	//}
	//double avg = sum/5.0;
	//for (i = 0; i < 5; i++) {
	//	if (stu[i].score <= avg) {
	//		printf("%s\n",stu[i].name);
	//	}
	//}

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

	//problem 4
	//int n;
	//scanf("%d",&n);
	//int i;
	//struct student stu[20];
	//for (i = 0; i < n; i++) {
	//	scanf("%s %d %d %d",&stu[i].name, &stu[i].t1, &stu[i].t2, &stu[i].t3);
	//	int sum=0;
	//	sum += stu[i].t1+stu[i].t2+stu[i].t3;
	//	stu[i].avg = sum/3.0;
	//	if (stu[i].avg >= 90) 
	//		stu[i].grade = 'A';
	//	
	//	else if(stu[i].avg >= 80)
	//		stu[i].grade = 'B';
	//	else if(stu[i].avg >= 70)
	//		stu[i].grade = 'C';
	//	else
	//		stu[i].grade = 'F';
	//}
	//for (i = 0; i < n; i++) {
	//	printf("%s %.1f %c\n", stu[i].name, stu[i].avg, stu[i].grade);
	//}

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

	//problem 5
	//int n;
	//scanf("%d",&n);
	//int i;
	//struct student students[50], *stu=students;
	//for (;stu<students+n;stu++) {
	//	scanf("%s %d %d %d", &stu->name, &stu->t1, &stu->t2, &stu->t3);
	//	int sum = 0;
	//	sum += stu->t1 + stu->t2 + stu->t3;
	//	stu->avg = sum / 3.0;
	//	if (stu->avg >= 90)
	//		stu->grade = 'A';
	//	else if (stu->avg >= 80)
	//		stu->grade = 'B';
	//	else if (stu->avg >= 70)
	//		stu->grade = 'C';
	//	else
	//		stu->grade = 'D';
	//}
	//for (stu=students; stu < students + n; stu++) {
	//	printf("%s %.1f %c\n",stu->name, stu->avg, stu->grade);
	//}

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

	//problem 6
	//int n;
	//scanf("%d",&n);
	//struct student stu[10];
	//int i;
	//int g1=0,g2=0,g3=0;
	//for (i = 0; i < n; i++) {
	//	scanf("%d %d %d",&stu[i].gender, &stu[i].weight, &stu[i].height);
	//}
	//for (i = 0; i < n; i++) {
	//	if (stu[i].gender == 1) {
	//		if (stu[i].weight < 60) {
	//			if (stu[i].height < 165) {
	//				g1++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g2++;
	//			}
	//			else {
	//				g3++;
	//			}
	//		}
	//		else if (stu[i].weight < 70) {
	//			if (stu[i].height < 165) {
	//				g3++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g1++;
	//			}
	//			else {
	//				g2++;
	//			}
	//		}
	//		else {
	//			if (stu[i].height < 165) {
	//				g2++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g3++;
	//			}
	//			else {
	//				g1++;
	//			}
	//		}
	//	}
	//	else if (stu[i].gender == 2) {
	//		if (stu[i].weight < 50) {
	//			if (stu[i].height < 165) {
	//				g1++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g2++;
	//			}
	//			else {
	//				g3++;
	//			}
	//		}
	//		else if (stu[i].weight < 60) {
	//			if (stu[i].height < 165) {
	//				g3++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g1++;
	//			}
	//			else {
	//				g2++;
	//			}
	//		}
	//		else {
	//			if (stu[i].height < 165) {
	//				g2++;
	//			}
	//			else if (stu[i].height < 175) {
	//				g3++;
	//			}
	//			else {
	//				g1++;
	//			}
	//		}
	//	}
	//}
	//printf("%d %d %d",g1,g2,g3);

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 7
	//int i,j;
 //   struct number nums[10];
 //   for(i=0;i<10;i++){
 //       scanf("%d",&nums[i].n);
 //   }
 //   for(i=0;i<10;i++){
 //       int cnt=1;
 //       for(j=0;j<10;j++){
 //           if(nums[i].n < nums[j].n){
 //               cnt++;
 //           }
 //       }
 //       nums[i].order = cnt;
 //   }
 //   int n1,n2;
 //   for(i=0;i<10;i++){
 //       if(nums[i].order==3)
 //           n1 = nums[i].n;
 //       else if(nums[i].order==7)
 //           n2=nums[i].n;
 //   }
 //   printf("%d %d",n1,n2);
 // 
 // ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//problem 8
	//Complex i1,i2,rst;
	//scanf("%lf %lf",&i1.real, &i1.img);
	//scanf("%lf %lf",&i2.real, &i2.img);
	//
	//rst = add(i1,i2);
	//printf("%.1f + %.1fi",rst.real, rst.img);

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	//6주차 실습문제 1
	struct student stu[100];
	int n;
	scanf("%d",&n);
	int i,j;
	getchar();
	for(i=0;i<n;i++){
	    gets_s(stu[i].belong);
	    gets_s(stu[i].id);
	}
	//for (i = 0; i < n; i++) {
	//	printf("%s %d\n", stu[i].belong, stu[i].id);
	//}
	//printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	for(i=0;i<n;i++){
	    for(j=i;j<n;j++){
	        if(strcmp(stu[i].belong, stu[j].belong)==1){
	            struct student tmp = stu[i];
	            stu[i] = stu[j];
	            stu[j] = tmp;
	        }
	    }
	}
	i=0;
	j=0;
	for(i=0;i<n;i++){
	    for(j=i;strcmp(stu[i].belong, stu[j].belong)==0;j++){
			if (strcmp(stu[j].belong, stu[j + 1].belong) == 0 && strcmp(stu[j].id, stu[j + 1].id) > 0) {
				struct student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}

	    }
	}
	for (i = 0; i < n; i++) {
		printf("%s %s\n",stu[i].belong, stu[i].id);
	}



	//교수님 코드
	//struct stud st[100];
	// 
	//int n;

	//scanf("%d", &n);
	//getchar();

	//for (int i = 0; i < n; i++) {
	//	gets(st[i].dept);
	//	gets(st[i].id);
	//}

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - i - 1; j++) {
	//		if (strcmp(st[j].dept, st[j + 1].dept) > 0) {
	//			struct stud temp;
	//			temp = st[j];
	//			st[j] = st[j + 1];
	//			st[j + 1] = temp;
	//		}
	//	}
	//}
	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - i - 1; j++) {
	//		if (strcmp(st[j].dept, st[j + 1].dept) == 0 && strcmp(st[j].id, st[j + 1].id) > 0) {
	//			struct stud temp;
	//			temp = st[j];
	//			st[j] = st[j + 1];
	//			st[j + 1] = temp;
	//		}
	//	}
	//}

	//for (int i = 0; i < n; i++) {
	//	printf("%s %s\n", st[i].dept, st[i].id);
	//}


}
Complex add(Complex i1, Complex i2) {
	Complex rst;
	rst.real = i1.real + i2.real;
	rst.img = i1.img + i2.img;
	return rst;
}