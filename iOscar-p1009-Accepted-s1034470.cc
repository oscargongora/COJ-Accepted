#include <bits/stdc++.h>
#define MAX_N 100005

using namespace std;

int P[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i, j;
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(i = 0; i < n; i ++) cin >> P[i];
        sort(P, P + n);
        j = -1;
        for(i = 0; i < n; i ++)
        {
            if(P[i] > 3)
            {
                j = i;
                break;
            }
        }
        if(j != -1) sort(P + j, P + n, [](int a, int b){return a > b;});
        for(i = 0; i < n; i ++) cout << P[i] << " ";
        cout << "\n";
    }
    return 0;
}
