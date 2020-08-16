#include <bits/stdc++.h>
#define MAX_N 10001

using namespace std;

typedef vector<int> vi;

vi p[9];
int tmp[4] = {1, 3, 7, 9};

bool prime(int n)
{
    if(n < 4)
        return n > 1;
    if((n % 2 == 0) || (n % 3 == 0))
        return 0;
    int i;
    for(i = 5; (i * i) <= n; i += 6)
        if((n % i == 0) || (n % (i + 2) == 0))
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, j, k, l;
    p[1].push_back(2);
    p[1].push_back(3);
    p[1].push_back(5);
    p[1].push_back(7);
    for(i = 2; i < 9; i ++)
    {
        for(j = 0; j < p[i - 1].size(); j ++)
        {
            for(k = 0; k < 4; k ++)
            {
                l = 10 * p[i - 1][j] + tmp[k];
                if(prime(l))
                {
                    p[i].push_back(l);
                }
            }
        }
    }
    while(cin >> n)
    {
        for(i = 0; i < p[n].size(); i ++)
            cout << p[n][i] << "\n";
    }
    return 0;
}
