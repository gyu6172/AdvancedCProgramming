#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define cap(A) ('A'<=A&&A<='Z')
#define small(A) ('a'<=A&&A<='z')
#define num(A) ('0'<=A&&A<='9')

int main() {
    char str[201];
    int num, save = 0, start, strend, hub;
    gets_s(str);
    scanf("%d", &num);
    strend = strlen(str);
    for (int i = 0; i < strend; i++) {
        if (cap(str[i])) {
            str[i] += num;
            //if (!cap(str[i])) str[i] = str[i] - 'Z' + 'A' + 1;
        }
        else if (small(str[i])) {
            str[i] -= num;
            //if (!small(str[i])) str[i] = 'a' - str[i] + 'z';
        }
        else if (num(str[i])) {
            start = i;
            save = atoi(&str[i]);
            if (save > 10)
                hub = 2;
            else 
                hub = 1;
            for (int j = strlen(str); j >= start+hub; j--)
                str[j + num-hub] = str[j];

            //숫자는 save 이고 num번 반복해야한다 시작은 i에서 부터 i+num까지

            for (int j = start; j < start + num; j++)
                str[j] = 'A' + save - 1;
            i += num - 1;
            strend -= hub;  
            strend += num;
        }
        else {
            str[i] = ' ';
        }
    }
    str[strend] = '\0';
    printf("%s", str);
}
