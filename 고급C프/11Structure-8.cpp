#include <stdio.h>
typedef struct complex {
	double real;
	double img;
}Complex;
Complex add(Complex i1, Complex i2);

int main() {
	Complex i1, i2, rst;
	scanf("%lf %lf", &i1.real, &i1.img);
	scanf("%lf %lf", &i2.real, &i2.img);

	rst = add(i1, i2);
	printf("%.1f + %.1fi", rst.real, rst.img);
}
Complex add(Complex i1, Complex i2) {
	Complex rst;
	rst.real = i1.real + i2.real;
	rst.img = i1.img + i2.img;
	return rst;
}