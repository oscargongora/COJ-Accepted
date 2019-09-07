#include <stdio.h>

int main()
{
	int T, N, M;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		if(N == M)
		{
			if(N % 2) printf("R\n");
			else printf("L\n");
		}
		else if(N > M)
		{
			if(M % 2) printf("D\n");
			else printf("U\n");
		}
		else
		{
			if(N % 2) printf("R\n");
			else printf("L\n");
		}
	}
	return 0;
}
