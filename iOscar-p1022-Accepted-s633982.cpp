#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream strStream;
    int cases;
    cin>>cases;
    while(cases>0)
    {
        int swaps = 0;
        int n;
        cin>>n;
        int carriages[n];
        int *pCarriages = carriages;
        while(pCarriages < (&carriages[n]))
        {
            cin >> *pCarriages;
            pCarriages++;
        }
        pCarriages = carriages;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                if(*(pCarriages+j) > *(pCarriages+j+1))
                {
                    *(pCarriages+j) += *(pCarriages+j+1);
                    *(pCarriages+j+1) = *(pCarriages+j) - *(pCarriages+j+1);
                    *(pCarriages+j) -= *(pCarriages+j+1);
                    swaps++;
                }
            }
        }
        strStream << "Optimal train swapping takes " << swaps << " swaps.\n";
        cases--;
    }
    cout<<strStream.str();
    return 0;
}
