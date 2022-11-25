#include <stdio.h>
int main() {
	FILE *fp;
	fp = fopen("data.txt", "w+");
	if (fp == NULL) {
		printf("파일 오류");
		return -1;
	}
	int n;
	scanf("%d",&n);
	while (!feof(stdin)) {
		fprintf(fp, "%d\n", n);
		scanf("%d",&n);
	}
	fclose(fp);

	fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("파일 오류");
		return -1;
	}

	int cnt=0;
	int sum=0;
	double avg=0.0;
	fscanf(fp, "%d", &n);
	while (!feof(fp)) {
		cnt++;
		sum += n;
		fscanf(fp, "%d", &n);
	}
	avg = (double)sum/cnt;
	fclose(fp);
	printf("%d\n%d\n%.2f",cnt,sum,avg);

}