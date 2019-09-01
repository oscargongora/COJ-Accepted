#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int *pA = &a, *pB = &b;
    cout<<*pA+*pB;
    return 0;
}
