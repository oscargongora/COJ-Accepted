#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a > b? a: b;
}

struct member 
{
	int step1, step2;
	bool operator <(const member &m) const
	{
		return step2 > m.step2;
	}
};

int main()
{
	int t, n, i, acc1, acc2;
	member team[12];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d%d", &team[i].step1, &team[i].step2);
		sort(team, team + n);
		acc1 = acc2 = 0;
		for(i=0; i<n; i++)
		{
			acc1 += team[i].step1;
			acc2 = max(acc2, acc1 + team[i].step2);
		}	
		printf("%d\n", acc2);
	}
	return 0;
}