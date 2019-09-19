#include <stdio.h>
#include <math.h>

void f(double x)
{
	int j;
	double i, k, xabs = fabs(x);
    for(i=2; (k=i*i)<=xabs; i++)
	{
		j = 2;
		while(k < xabs)
		{
			k *= i;
			j++;
		}
		if(k == xabs)
		{
			if(x > 0 || j % 2)
		    {
			    printf("%d\n", j);
			    return;
		    }
		}
	}
	printf("1\n");
}

int main()
{
    double x;
	while(scanf("%lf", &x) && x) f(x);
	return 0;
}
