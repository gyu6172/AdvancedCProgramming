#include <stdio.h>
struct test {
	int max;
	int min;
	char pass;
	int standard;
	int difference;
};
void passorfail(struct test* p);
int main() {
	struct test p1;
	scanf("%d %d %d",&p1.max, &p1.min, &p1.standard);
	p1.difference = p1.max - p1.min;
	passorfail(&p1);
	printf("%d %c",p1.difference, p1.pass);

}

void passorfail(test* p)
{
	if (p->difference <= p->standard) {
		p->pass='P';
	}
	else {
		p->pass='F';
	}
}
