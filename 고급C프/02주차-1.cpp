#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int ar[100];
	int arIter = 0;
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	ar[n] = 0;
	while (arIter != 1) {
		arIter = 0;
		for (i = 0; i < n; i += 2) {
			if (ar[i] < ar[i + 1]) {
				ar[arIter] = ar[i + 1];
				arIter++;
			}
			else {
				ar[arIter] = ar[i];
				arIter++;
			}
		}
		for (i = 0; i < arIter; i++) {
			printf("%d ", ar[i]);
		}
		n = arIter;
		ar[n] = 0;
		printf("\n");
	}
}