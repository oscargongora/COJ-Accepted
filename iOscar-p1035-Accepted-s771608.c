#include <stdio.h>
#include <math.h>

int v[1000001];

int main()
{
	int i, a;
	v[0] = 1;
	for(i=1; i<1000001; i++)
	{
		a = i-sqrt(i);
 	    v[i] =  v[a];
		a = log(i);
		v[i] += v[a];
        a=i*sin(i)*sin(i);
		v[i] += v[a];
 	    v[i] %= 1000000;
	}
	while(scanf("%d", &i) && i != -1) printf("%d\n", v[i]);
	return 0;
}