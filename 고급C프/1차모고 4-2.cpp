//80점, sample submit에서는 Accept ㅡㅡ

#include <stdio.h>
#include <string.h>
int main() {
	char A[100], B[100], resultStr[250]="";
	char Aarr[100][100], Barr[100][100], tmpStr[100];
	int tmpIter=0, AarrIter=0, BarrIter=0;

	gets_s(A);
	gets_s(B);
	int Alen=strlen(A), Blen=strlen(B);
	int i,j;
	for (i = 0; i < Alen; i++) {
		if (A[i] == ' ') {
			tmpStr[tmpIter]=NULL;
			strcpy(Aarr[AarrIter++],tmpStr);
			tmpIter=0;
		}
		else {
			tmpStr[tmpIter++]=A[i];
		}
	}
	tmpStr[tmpIter] = NULL;
	strcpy(Aarr[AarrIter++], tmpStr);
	tmpIter = 0;
	for (i = 0; i < Blen; i++) {
		if (B[i] == ' ') {
			tmpStr[tmpIter] = NULL;
			strcpy(Barr[BarrIter++], tmpStr);
			tmpIter = 0;
		}
		else {
			tmpStr[tmpIter++] = B[i];
		}
	}
	tmpStr[tmpIter] = NULL;
	strcpy(Barr[BarrIter++], tmpStr);
	tmpIter = 0;
	//for (i = 0; i < AarrIter; i++) {
	//	printf("%s\n",Aarr[i]);
	//}
	//printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	//for (i = 0; i < BarrIter; i++) {
	//	printf("%s\n", Barr[i]);
	//}
	for (i = 0; i < AarrIter; i++) {
		for (j = i-1; j >= 0; j--) {
			if (strcmp(Aarr[i], Aarr[j]) == 0) {
				strcpy(Aarr[i],Barr[tmpIter++]);
			}
		}
	}
	//printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	//for (i = 0; i < AarrIter; i++) {
	//	printf("%s\n", Aarr[i]);
	//}
	//printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	for (i = 0; i < AarrIter; i++) {
		strcat(resultStr, Aarr[i]);
		strcat(resultStr," ");
	}

	printf("%s",resultStr);

}