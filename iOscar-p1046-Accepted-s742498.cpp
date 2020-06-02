#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <sstream>


using namespace std;

int main()
{
	int t, a, b, i;
	stringstream sstream;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);
		double ac = 0;
		for (i = a; i <= b; i++)
		{
			ac += i * (i + 1) * (i + 2);
		}
		sstream << fmod(ac, 100) << endl;
	}
	printf("%s", sstream.str().c_str());
	return 0;
}