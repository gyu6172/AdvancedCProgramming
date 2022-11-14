#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct reserve {
	int id;
	char grade[4];
	int price;
}Reserve;
typedef struct tot_price {
	int id;
	int toal_price;
}Totalprice;
void input(Reserve* p, int n);
int cal_num(Reserve* p, int n);
void cal_sum(Reserve* p, int n, Totalprice* q);
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	Reserve* customers = (Reserve*)malloc(sizeof(Reserve) * n);
	if (customers == NULL)
		return -1;
	input(customers, n);

	int i, j;

	int customersCnt = cal_num(customers, n);
	Totalprice* totalPrice = (Totalprice*)malloc(sizeof(Totalprice)*customersCnt);

	if (totalPrice == NULL) {
		printf("Not Enough Memory");
		return -1;
	}

	cal_sum(customers, n, totalPrice);

	for (i = 0; i < customersCnt; i++) {
		printf("%d %d\n",totalPrice[i].id, totalPrice[i].toal_price);
	}
}

void input(Reserve* p, int n)
{
	Reserve* iter;
	for (iter = p; iter < p + n; iter++) {
		scanf("%d %s", &(iter->id), &(iter->grade));
		getchar();
		if (strcmp(iter->grade, "VIP") == 0) {
			iter->price = 140000;
		}
		else if (strcmp(iter->grade, "R") == 0) {
			iter->price = 110000;
		}
		else if (strcmp(iter->grade, "S") == 0) {
			iter->price = 85000;
		}
		else if (strcmp(iter->grade, "A") == 0) {
			iter->price = 55000;
		}
	}
}

int cal_num(Reserve* p, int n)
{
	Reserve* arr = (Reserve*)malloc(sizeof(Reserve)*n);
	if (arr == NULL) {
		printf("Not Enough Memory");
		return -1;
	}
	int i,j;
	Reserve* iterp, *iterq;
	for (iterp = p, iterq = arr; iterp < p + n; iterp++, iterq++) {
		iterq->id = iterp->id;
		strcpy(iterq->grade, iterp->grade);
		iterq->price = iterq->price;
	}
	for (iterp = arr; iterp < arr + n; iterp++) {
		for(iterq=iterp; iterq<arr+n;iterq++){
			if (iterp->id < iterq->id) {
				Reserve tmp = *iterp;
				*iterp = *iterq;
				*iterq = tmp;
			}
		}
	}

	int cnt=1;
	for (iterp = arr+1; iterp < arr + n; iterp++) {
		if ((iterp - 1)->id != iterp->id) {
			cnt++;
		}
	}
	free(arr);
	return cnt;
}

void cal_sum(Reserve* p, int n, Totalprice* q)
{
	Reserve* piter1, *piter2;
	Totalprice *qiter;
	Totalprice *mainQ=q;
	for (piter1 = p; piter1 < p + n; piter1++) {
		int chk=0;
		for (qiter = q; qiter < q + n; qiter++) {
			if (qiter->id == piter1->id) {
				chk=1;
				break;
			}
		}
		if (!chk) {
			mainQ->id = piter1->id;
			int sum=0;
			for (piter2 = p; piter2 < p + n; piter2++) {
				if (piter2->id == piter1->id) {
					sum += piter2->price;
				}
			}
			mainQ->toal_price = sum;
			mainQ++;
		}
	}
}
