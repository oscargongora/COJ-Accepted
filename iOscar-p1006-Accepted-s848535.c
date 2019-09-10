#include <stdio.h>
#include <string.h>
#define MAXL 20001

int p;
char  str[MAXL], aux[MAXL]; 

char change(char c)
{
	if(c>='A' && c<='Z') 
	    return c == 'A'? 'Z': c - 1;
	if(c>='a' && c<='z') 
	    return c == 'a'? 'z': c - 1;  
	return c;  
}

void f(int begin, int end)
{
	if(begin == end)
	{
		aux[begin] = change(str[p]);
	    p ++;
	}
	else if(begin < end)
	{
		int half = (begin + end) / 2;
	    aux[half] = change(str[p]);
	    p ++;
	    f(begin, half - 1);
	    f(half + 1, end);
	}
	return;
}

int main()
{
	int i, length;
	while(gets(str))
	{
		p = 0;
		length = strlen(str);
		
		f(0, length-1);
		
        for(i=0; i<length; i++)
            printf("%c", aux[i]);
        printf("\n");    
	}
	return 0;
}