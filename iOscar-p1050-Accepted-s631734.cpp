#include <iostream>

using namespace std;
int gcd(int n1, int n2);
int main()
{
    int n;
    cin >> n;
    int cont = 0;
    for(int i = 1; i<n ; i++)
    {
        if(gcd(i,n) == 1)
        {
            cont++;
        }
    }
    cout<<cont;
    return 0;
}

int gcd(int n1, int n2)
{
for(int i = 2; i <= n1; i++)
    {
    if(n1%i == 0 && n2%i == 0)
        {
        return i;
        }
    }
    return 1;
}
