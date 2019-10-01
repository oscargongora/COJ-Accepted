#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int k, i, j, min_supp;
	scanf("%d", &k);
	vector<int> groups(k);
	for(i=0; i<k; i++)
	{
		scanf("%d", &groups[i]);
	}
	sort(groups.begin(), groups.end());
	k /= 2;
	min_supp = 0;
	for(i=0; i<=k; i++)
	{
		min_supp += (groups[i]/2)+1;
	}
	printf("%d\n", min_supp);
	return 0;
}
