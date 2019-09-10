#include <stdio.h>
#include <string.h>
#define MAXL 20001

using namespace std;

int I;
char  str[MAXL], str1[MAXL]; 

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
	if(begin > end) return;
	int half = (begin + end) / 2;
	str1[half] = change(str[I]);
	I ++;
	f(begin, half - 1);
	f(half + 1, end);
}

int main()
{
	int i, length;
	while(gets(str))
	{
		I = 0;
		length = strlen(str);
		
		f(0, length - 1);
		
        for(i=0; i<length; i++)
            printf("%c", str1[i]);
        printf("\n");    
	}
	return 0;
}