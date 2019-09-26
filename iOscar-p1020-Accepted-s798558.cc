#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 110

using namespace std;

bool f(char m1, char m2)
{
	if((m1 == 'r' && m2 == 's') || (m1 == 's' && m2 == 'p') || (m1 == 'p' && m2 == 'r'))
		   return true;
	return false;
}

int main()
{
	int n, k, p1, p2, win[MAXN], lose[MAXN], games, i;
	char m1[10], m2[10];
	bool first = true;
	while(scanf("%d", &n) && n)
	{
		scanf("%d", &k);
		for(i=1; i<=n; i++)
		{
			win[i] = lose[i] = 0;
		}
		
		games = k*n*(n-1)/2;
		for(i=0; i<games; i++)
		{
			scanf("%d %s %d %s", &p1, &m1, &p2, &m2);
			if(m1[0] != m2[0])
			{
				if(f(m1[0], m2[0]))
				{
					win[p1]++; lose[p2]++;
				}
				else
				{
					win[p2]++; lose[p1]++;
				}
			}
		}
		
		if (!first)	printf("\n");
        first = false;
        
		for(i=1; i<=n; i++)
		{
			if(win[i]+lose[i] == 0) printf("-\n");
			else printf("%.3lf\n", ((double) win[i]/(win[i]+lose[i])));
		}
	}
	return 0;
}