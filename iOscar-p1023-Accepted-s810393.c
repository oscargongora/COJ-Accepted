#include <stdio.h>

int main()
{
	int T = 12;
	float S = 0, Bi;
	while(T--)
	{
		scanf("%f", &Bi);
		S += Bi;
	}
	printf("$%.2f\n", (S/12));
	return 0;
}
