#include <stdio.h>

int main()
{
	int i, t;
	float h, d, r, acc = 0;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%f %f", &h, &d);
		r = (d * d) / h;
		r = (h - r) / 2;
		printf("%.1f\n", r);
		acc += r;
	}
	printf("%.1f\n", acc/t);
	return 0;
}