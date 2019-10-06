#include <stdio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	char s[50], t[50];
	int i, cont, ls, lt;
	while(scanf("%s %s", s, t) != EOF)
	{
		cont = 0;
		for(i=0; i<strlen(t); i++)
		{
			if(s[cont] == t[i])
			{
				cont++;
			}
		}
		if(cont == strlen(s))
		printf("%s\n", "Yes");
		else
		printf("%s\n", "No");
	}
	return 0;
}