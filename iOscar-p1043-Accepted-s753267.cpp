#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

int w, i, dishes[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
vector<int> seleccion;
stringstream sstream;

void d(int acum)
{
	if(acum == w)
	{
		if(seleccion.size() > 0)
		{
			for(i=seleccion.size()-1; i>=0; i--)
			{
				sstream << seleccion[i] << " ";
			}
			sstream << endl;
		}
	}
	for(i=14; i>=0; i--)
	{
		if(acum+dishes[i] <= w)
		{
			seleccion.push_back(i);
			d(acum+dishes[i]);
			seleccion.pop_back();
		}
	}
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &w);
		d(0);
	}
	printf("%s", sstream.str().c_str());
	return 0;
}