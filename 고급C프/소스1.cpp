#pragma warning(disable : 4996)//scnaf함수 사용
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define ch(A) ('a'<=*A&&*A<='z')

int s_check(char* p, char* q);
int main() {
    int m, k1, k2, hub;
    char arr[100];
    scanf("%d", &m);
    scanf("%d %d", &k1, &k2);
    getchar();
    for (int i = 0; i < m; i++) {
        gets_s(arr);
        hub = s_check(&arr[k1], &arr[k2]);
        if (hub == 0)continue;
        else printf("%d\n", hub);
    }

}
int s_check(char* p, char* q) {
    int cnt = 0;
    for (char* r = p; r <= q; r++) {
        if (ch(r))cnt++;
    }
    return cnt;
}
