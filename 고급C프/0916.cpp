#include <stdio.h>
void addArray(int* p1, int* p2, int *p3, int size);
int arrsum(int* s, int* e);
int add_to_k(int *p1, int* p2);
void ABC(int *p, int k);
int* MAX(int ar[]);
int* MIN(int ar[]);
int main() {
	//problem 12
	//int n;
	//int x[20],y[20],z[20];
	//scanf("%d",&n);
	//int *p;
	//for (p = x; p < x + n; p++) {
	//	scanf("%d",p);
	//}
	//for (p = y; p < y + n; p++) {
	//	scanf("%d", p);
	//}
	//addArray(x,y,z,n);
	//for (p = z; p < z + n; p++) {
	//	printf(" %d",*p);
	//}



	//problem 13
	//int n,s,e;
	//int i,j;
	//int arr[100];
	//scanf("%d %d %d",&n,&s,&e);
	//int *p = arr;
	//for (p = p; p < arr + n; p++) {
	//	scanf("%d",p);
	//}
	//p = arr;
	//printf("%d",arrsum(p+s,p+e));



	//problem 14
	//int d[100];
	//int n;
	//scanf("%d",&n);
	//int *p;
	//for (p = d; p < d + n; p++) {
	//	scanf("%d",p);
	//}
	//int sum=0;
	//p=d;
	//for (int i = 0; i < n; i++) {
	//	sum += add_to_k(p,p+i);
	//}
	//printf("%d",sum);



	//problem 15
	//int arr[20];
	//int *p;
	//for (p = arr; p < arr + 10; p++) {
	//	scanf("%d",p);
	//}
	//int k;
	//for (p = arr,k=10; p < arr + 10; p++,k--) {
	//	ABC(p,k);
	//}
	//for (p = arr; p < arr + 10; p++) {
	//	printf(" %d",*p);
	//}


	//문자열
	//problem 1
	//char str[20];
	//scanf("%s",str);
	//int i;
	//for (i = 0; str[i] != NULL; i++) {
	//	if('a' <= str[i] && str[i] <= 'z')
	//		printf("%c",str[i]);
	//}



	//problem 2
	int n;
	char str[10];
	int strIter=0;
	scanf("%d",&n);
	while (n != 0) {
		int a = n%10;
		str[strIter] = (char)(a+48);
		strIter++;
		n /= 10;
	}
	str[strIter] = '\0';
	printf("%s",str);





	//3주차 포인터 실습
	//problem 1
	//int n;
	//scanf("%d",&n);
	//for (int i = 0; i < n; i++) {
	//	int arr[100];
	//	int arrIter = 0;
	//	int a;
	//	for (int j = 0; j < 100; j++) {
	//		scanf("%d", &arr[j]);
	//		if(arr[j]==0)
	//			break;
	//	}

	//	printf("%d %d\n", *MAX(arr), *MIN(arr));
	//}



}

void addArray(int* p1, int* p2, int* p3, int size)
{
	for (int i = 0; i < size; i++) {
		*(p3+i) = *(p1+i) + *(p2+(size-i-1));
	}
}

int arrsum(int* s, int* e)
{
	int sum=0;
	for (int* p = s; p <= e; p++) {
		sum += *p;
	}

	return sum;
}

int add_to_k(int* p1, int* p2)
{
	int sum = 0;
	for (int* p = p1; p <= p2; p++) {
		sum += *p;
	}
	return sum;
}

void ABC(int* p, int k)
{
	int *max = p;
	int *x;
	for (x=p;x<p+k;x++) {
		if (*max < *x) {
			int *tmp = max;
			max = x;
			x = tmp;
		}
	}
	int tmp = *p;
	*p = *max;
	*max = tmp;
}

int* MAX(int ar[])
{
	int *p;
	int *max = ar;
	for (p = ar; *p != 0; p++) {
		if (*max < *p) {
			int *tmp = max;
			max = p;
			p = tmp;
		}
	}
	return max;
}

int* MIN(int ar[])
{
	int* p;
	int* min = ar;
	for (p = ar; *p != 0; p++) {
		if (*min > *p) {
			int* tmp = min;
			min = p;
			p = tmp;
		}
	}
	return min;
}
