#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	stringstream sstream;
	int a, b, i, ci, anotb, bnota;
	scanf("%d %d", &a, &b);
	while(a || b)
	{
		vector<int> acards(a), bcards(b);
		for(i=0; i<a; i++)
		{
			scanf("%d", &ci);
			if(!binary_search(acards.begin(), acards.end(), ci))
			{
				acards.push_back(ci);
			}
		}
		for(i=0; i<b; i++)
		{
			scanf("%d", &ci);
			if(!binary_search(bcards.begin(), bcards.end(), ci))
			{
				bcards.push_back(ci);
			}
		}
		anotb = 0;
		for(i=0; i<acards.size(); i++)
		{
			if(!binary_search(bcards.begin(), bcards.end(), acards[i]))
			{
				anotb++;
			}
		}
		bnota = 0;
		for(i=0; i<bcards.size(); i++)
		{
			if(!binary_search(acards.begin(), acards.end(), bcards[i]))
			{
				bnota++;
			}
		}
		if(bnota <= anotb)
		{
			sstream << bnota << endl;
		}
		else
		{
			sstream << anotb << endl;
		}
		scanf("%d %d", &a, &b);
	}
	printf("%s", sstream.str().c_str());
	return 0;
}