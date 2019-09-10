#include <stdio.h>
#include <string.h>
#define MAXL 20001

int p;
char  str[MAXL], aux[MAXL]; 

char change(char c)
{
	if(c == 'a') return 'z';
	if(c == 'A') return 'Z';
	if((c >= 'b' && c <= 'z') || (c >= 'B' && c <= 'Z')) 
	    return c - 1;
	return c;
}

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
            printf("%c", change(aux[i]));
        printf("\n");    
	}
	return 0;
}