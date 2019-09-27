#include <stdio.h>
#include <stdlib.h>

int f(int *v, int size, int val)
{
	int i;
	for(i=0; i<size; i++)
		if(v[i] == val)
		return 1;
	return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int k, ki, m, c, r, i, j, cont, ci, flag, *courses;

	while(scanf("%d", &k) && k)
	{
		courses = malloc(k*sizeof(courses));
		scanf("%d", &m);
		for(i=0; i<k; i++)
			scanf("%d", &courses[i]);
			
		flag = 1;
		for(i=0; i<m; i++)
		{
			scanf("%d %d", &c, &r);
			cont = 0;
			for(j=0; j<c; j++)
			{
				scanf("%d", &ci);
				if(f(courses, k, ci) == 1)
					cont++;
			}
			if(cont < r)
				flag = 0;
		}
		if(flag)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}