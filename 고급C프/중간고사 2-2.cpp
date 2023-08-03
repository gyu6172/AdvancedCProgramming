#include <stdio.h>
#include <string.h>
//6
//marriott 4 4.7 12.5 300
//ibis 2 3.4 5.6 150
//novotel 3 3.0 5.0 350
//renaissance 3 3.5 4.8 200
//bestwestern 2 3.3 3.8 200
//hyatt 5 3.5 7.4 500
typedef struct hotel {
	char name[31];
	int lv;
	double reputation;
	double distance;
	int price;
}Hotel;
void in_hotel(struct hotel* ar, int n);
void out_hotel(struct hotel* ar, char* name, int n);
int main() {
	Hotel hotels[100];
	int n;
	scanf("%d", &n);
	in_hotel(hotels, n);
	//for (int i = 0; i < n; i++) {
	//	printf("%s %d %lf %lf %d\n", hotels[i].name, hotels[i].lv, hotels[i].reputation, hotels[i].distance, hotels[i].price);
	//}
	char wantName[31];
	scanf("%s", wantName);
	Hotel* p;
	p = hotels;
	for (p = p; p < hotels + n; p++) {
		if (strcmp(wantName, p->name) == 0) {
			printf("%s %d %.1f %.1f %d\n", p->name, p->lv, p->reputation, p->distance, p->price);
		}
	}
	out_hotel(hotels, wantName, n);
}

void in_hotel(struct hotel* ar, int n)
{
	Hotel* p;
	for (p = ar; p < ar + n; p++) {
		scanf("%s %d %lf %lf %d", &(p->name), &(p->lv), &(p->reputation), &(p->distance), &(p->price));
		getchar();
	}
}

void out_hotel(struct hotel* ar, char* name, int n)
{
	Hotel* p;
	Hotel* wantHotel;
	Hotel* rstHotel;
	int minPrice = 2147483647;
	for (p = ar; p < ar + n; p++) {
		if (strcmp(name, p->name) == 0) {
			wantHotel = p;
			break;
		}
	}
	for (p = ar; p < ar + n; p++) {
		if ((wantHotel->reputation < p->reputation) && (wantHotel->price > p->price) && ((wantHotel->lv <= p->lv) || (wantHotel->distance > p->distance))) {
			printf("%s %d %.1f %.1f %d\n", p->name, p->lv, p->reputation, p->distance, p->price);
			if (minPrice > p->price) {
				minPrice = p->price;
				rstHotel = p;
			}
		}
	}
	printf("%s %d %.1f %.1f %d\n", rstHotel->name, rstHotel->lv, rstHotel->reputation, rstHotel->distance, rstHotel->price);
}
