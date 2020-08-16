#include <stdio.h>
#define maxnm 10001

int m, n, p[maxnm], min[maxnm], memo[maxnm];

int max(int a, int b)
{
	return a > b? a: b;
}

int points()
{
	int i, j;
	for(i=0; i<=m; i++) memo[i] = 0;
	for(i=1; i<=n; i++)
	{
		for(j=min[i]; j<=m; j++)
		{
			if(j < min[i])
				memo[j] = memo[j-min[i]];
			else
				memo[j] = max(memo[j], p[i] + memo[j-min[i]]);
		}	
	}
	return memo[m];
}

int main()
{
	int k, i;
	scanf("%d", &k);
	while(k--)
	{
		scanf("%d%d", &m, &n);
		for(i=1; i<=n; i++) scanf("%d %d", &p[i], &min[i]);
		i = points();
		printf("%d\n", i);
	}
	return 0;
}