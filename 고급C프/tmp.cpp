#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <string.h>

typedef struct {
    char* str; // 문자열 저장
    int cnt1; // 자음 수 저장
    int cnt2; // 총 문자 수 저장
    int num; // 숫자 저장
    int pos; // 위치 저장
    int result; // 곱셈결과 저장
}st;

int main() {

    int N;
    scanf("%d", &N);
    getchar();
    st* p;
    p = (st*)malloc(sizeof(st) * N);
    if (p == NULL) {
        printf("벩");
        return -1;
    }
    st* q;
    for (q = p; q < p + N; ++q) {
        char tmp[101];
        gets_s(tmp);
        int cnt = 0;
        q->str = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(q->str, tmp);
        q->cnt2 = strlen(tmp);
        for (int i = 0; i < strlen(tmp); ++i) {
            if ((q->str)[i] == 'A' || (q->str)[i] == 'E' || (q->str)[i] == 'I' || (q->str)[i] == 'O' || (q->str)[i] == 'U'
                || (q->str)[i] == 'a' || (q->str)[i] == 'e' || (q->str)[i] == 'i' || (q->str)[i] == 'o' || (q->str)[i] == 'u') {
                cnt++;
            }
            if ((q->str)[i] >= '0' && (q->str)[i] <= '9') {
                q->num = (q->str)[i] - '0';
                q->pos = i+1;
            }
        }
        q->cnt1 = q->cnt2-cnt-1;
        q->result = (q->num) * (q->cnt1) * (q->cnt2) * (q->pos);
    }
    st* k;
    st temp;
    int i;
    for (q = p, i=0; q < p + N; ++q,i++) {
        for (k = p; k < p + N - 1 - i; ++k) {
            if (k->result < (k + 1)->result) {
                temp = *k;
                *k = *(k + 1);
                *(k + 1) = temp;
            }
        }
    }
    for (q = p; q < p + N; ++q) {
        printf("%s\n", q->str);
    }


    free(p);



    return 0;
}