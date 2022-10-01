#include <stdio.h>
void input(int* a, int* b, int* c);
void output(int* a, int* b, int* c);
void swap(int* a, int* b);
int* mid(int ar[]);
void gcdlcm(int a, int b, int* p1, int* p2);
void strcopy(char a[], char b[]);

int main() {
	//problem 7
	//int x,y,z;
	//input(&x,&y,&z);
	//output(&x,&y,&z);



	//problem 8
	//int n;
	//scanf("%d",&n);

	//int ar[50];
	//for (int i = 0; i < n; i++) {
	//	scanf("%d",&ar[i]);
	//}

	//int a,b;
	//scanf("%d %d",&a,&b);
	//swap(&ar[a],&ar[b]);

	//for (int i = 0; i < n; i++) {
	//	printf(" %d",ar[i]);
	//}


	//problem 9
	int x[3];
	int* p;
	p = x;
	scanf("%d %d %d",p,p+1,p+2);

	printf("%d",*mid(x));



	//problem 10
	//int a,b;
	//scanf("%d %d",&a,&b);

	//int n1,n2;
	//gcdlcm(a,b,&n1,&n2);
	//printf("%d %d",n1,n2);



	//problem 11
	//char a[6],b[6];
	//char* p=a;
	//for (p = p; p < a + 6; p++) {
	//	scanf("%c",p);
	//}
	//
	//strcopy(a,b);

	//for (p = b; p < b + 6; p++) {
	//	printf("%c",*p);
	//}


	//problem 12
	//int n;
	//scanf("%d",&n);
	//int ar[100];
	//int arIter = 0;
	//int i;
	//for (i = 0; i < n; i++) {
	//	scanf("%d",&ar[i]);
	//}
	//ar[n] = 0;
	//while (arIter != 1) {
	//	arIter = 0;
	//	for (i = 0; i < n; i += 2) {
	//		if (ar[i] < ar[i + 1]) {
	//			ar[arIter] = ar[i + 1];
	//			arIter++;
	//		}
	//		else {
	//			ar[arIter] = ar[i];
	//			arIter++;
	//		}
	//	}
	//	for (i = 0; i < arIter; i++) {
	//		printf("%d ", ar[i]);
	//	}
	//	n = arIter;
	//	ar[n] = 0;
	//	printf("\n");
	//}



	//problem 13
	//int n;
	//int ar[100];
	//int arIter=0;
	//int i,j;
	//while (1) {
	//	scanf("%d",&n);
	//	if (n<0)
	//		break;

	//	int chk=0;
	//	for (i = 0; i < arIter; i++) {
	//		if (ar[i] == n) {
	//			chk=1;
	//			break;
	//		}
	//	}
	//	if (!chk) {
	//		printf("1");
	//		ar[arIter] = n;
	//		arIter++;
	//	}
	//	else {
	//		printf("0");
	//	}
	//}





}

void input(int* a, int* b, int* c)
{
	scanf("%d %d %d",a,b,c);
}

void output(int* a, int* b, int* c)
{
	printf("%d %d %d",*a,*b,*c);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* mid(int ar[])
{
	int* a;
	int* b;
	int* c;
	a = ar;
	b = ar+1;
	c = ar+2;

	int* p = ar;

	if (*a >= *b && *a >= *c) {
		p = (*b>*c)? b:c;
	}
	else if (*b >= *a && *b >= *c) {
		p = (*a > *c) ? a : c;
	}
	else if (*c >= *b && *c >= *a) {
		p = (*a > *b) ? a : b;
	}
	
	return p;
}

void gcdlcm(int a, int b, int* p1, int* p2)
{
	int i,j;
	int n1,n2;
	for (i = a; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			n1 = i;
			break;
		}
	}
	for (i = a;; i++) {
		if (i % a == 0 && i % b == 0) {
			n2 = i;
			break;
		}
	}
	*p1 = n1;
	*p2 = n2;
}

void strcopy(char a[], char b[])
{
	char *p1 = a;
	char *p2 = b;
	for (p1=a,p2=b;p1<a+6;p1++,p2++) {
		*p2 = *p1;
	}
}
