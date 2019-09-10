#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXL 20001

int p;
char  str[MAXL], aux[MAXL]; 

void decode(int begin, int end)
{
	if(begin > end) return;
	int half = (begin + end) >> 1;
	aux[half] = str[p];
	p ++;
	decode(begin, half - 1);
	decode(half + 1, end);
}

int main()
{
	int i, length;
	while(gets(str))
	{
		p = 0;
		length = strlen(str);
		
		decode(0, length-1);
		
        for(i=0; i<length; i++)
        {
        	if(aux[i] == 'a')
        	{
        		printf("z");
        		continue;
        	}
        	else if(aux[i] == 'A')
        	{
        		printf("Z");
        		continue;
        	}
        	printf("%c", isalpha(aux[i])? aux[i]-1: aux[i]);
        }
        printf("\n");    
	}
	return 0;
}