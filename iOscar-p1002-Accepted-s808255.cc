#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T, N, i, j, a, b, c, d, Len, mLen;
	bool f;
	vector<string> L(10);
	cin >> T;
	while(T--)
	{
		mLen = 0;
		cin >> N;
		for(i=0; i<N; i++) cin >> L[i];
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(L[i][j] == '.')
				{
					Len = 0;
					a = i;
					b = j;
					while(L[a][b] == '.')
					{
						f = true;
						for(c=a; c>=i; c--) if(L[c][b] == '#') f = false;
						if(!f) break;
						for(d=b; d>=j; d--) if(L[a][d] == '#') f = false;
						if(!f) break;
						a++, b++, Len++;
						if(a>=N || b>=N) break;
					}
					if(Len > mLen) mLen = Len;
				}
			}
		}
		cout << mLen << endl;
	}
	return 0;
}