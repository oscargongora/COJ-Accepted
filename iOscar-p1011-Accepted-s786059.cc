#include <stdio.h>

using namespace std;

int main()
{
	int T, NG, NM, i, MI, maxG, maxMG;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &NG, &NM);
		maxG = -1;
		for(i=0; i<NG; i++)
		{
			scanf("%d", &MI);
			if(MI > maxG)
			{
				maxG = MI;
			}
		}
		maxMG = -1;
		for(i=0; i<NM; i++)
		{
			scanf("%d", &MI);
			if(MI > maxMG)
			{
				maxMG = MI;
			}
		}
		
		bool winner = [](int a, int b) -> bool {return a >= b;}(maxG, maxMG);
		
		if(winner)
		{
			printf("Godzilla\n");
		}
		else
		{
			printf("MechaGodzilla\n");
		}
	}
	return 0;
}