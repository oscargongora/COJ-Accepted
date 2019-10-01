#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
	stringstream strstream;
	float c, sum;
	int cards, i;
	scanf("%f", &c);
	while(c)
	{
		sum = 0.5;
		cards = 1;
		i = 3;
		while(sum < c)
		{
			sum += 1.00/i;
			i++;
			cards++;
		}
		strstream << cards << " card(s)\n";
	    scanf("%f", &c);
	}
	printf("%s", strstream.str().c_str());
	return 0;
}