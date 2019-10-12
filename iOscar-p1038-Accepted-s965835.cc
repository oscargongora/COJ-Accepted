#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string in;
    int a, b, c;
    while(cin >> in)
    {
        if(in[0] == 'E')
        {
            break;
        }
        if(in.compare("1") == 0)
        {
            cout << "1\n";
            continue;
        }
        a = in.size();
        b = log10(a) + 1;
        c = 1;
        while(a != b)
        {
            c ++;
            a = b;
            b = log10(a) + 1;
        }
        cout << c + 1 << "\n";
    }
    return 0;
}
