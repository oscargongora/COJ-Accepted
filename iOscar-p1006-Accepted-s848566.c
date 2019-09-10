#include <stdio.h>
#include <string.h>
#define MAXL 20001

char  str[MAXL], aux[MAXL]; 

char change(char c)
{
	if(c == 'a') return 'z';
	if(c == 'A') return 'Z';
	if((c >= 'b' && c <= 'z') || (c >= 'B' && c <= 'Z')) 
	    return c - 1;
	return c;
}

void decode(int i, int j, int k, int l)
{
	if(i > j) return;
	aux[k + (j - i) / 2] = str[i];
	decode(i + 1, (i + j) / 2, k, (k + l) / 2 - 1);
	decode((i + j) / 2 + 1, j, (k + l) / 2 + 1, l);
}

int main()
{
	int i, length;
	while(gets(str))
	{
		length = strlen(str);
		
		decode(0, length-1, 0, length-1);
		
        for(i=0; i<length; i++)
            printf("%c", change(aux[i]));
        printf("\n");    
	}
	return 0;
}