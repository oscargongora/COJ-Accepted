#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct state
{
	int row, col, len;
	bool operator<(const state &s) const
	{
		return len < s.len;
	}
}st, temp;

int main()
{
	int n, r, c, i, j, k, l, max;
	vector<vector<int> > G(110);
	string name;
	cin >> n;
	while(n--)
	{
		cin >> name >> r >> c;
		for(i=0; i<r; i++) G[i] = vector<int>(c);
		max = 0;
		priority_queue<state> pq;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cin >> G[i][j];
				st.row = i;
				st.col = j;
				st.len = 1;
				pq.push(st);
			}
    	}
		while(!pq.empty())
		{
			st = pq.top(); pq.pop();
			if(st.len > max) max = st.len;
			if((st.row-1>=0) && G[st.row][st.col]>G[st.row-1][st.col])
			{
				temp.row = st.row-1;
				temp.col = st.col;
				temp.len = st.len + 1;
				pq.push(temp);
			}
			if((st.row+1<r) && G[st.row][st.col]>G[st.row+1][st.col])
			{
				temp.row = st.row + 1;
				temp.col = st.col;
				temp.len = st.len + 1;
				pq.push(temp);
			}
			if((st.col-1>=0) && G[st.row][st.col]>G[st.row][st.col-1])
			{
				temp.row = st.row;
				temp.col = st.col - 1;
				temp.len = st.len + 1;
				pq.push(temp);
			}
			if((st.col+1<c) && G[st.row][st.col]>G[st.row][st.col+1])
			{
				temp.row = st.row;
				temp.col = st.col + 1;
				temp.len = st.len + 1;
				pq.push(temp);
			}
		}
		cout <<name <<": " <<max << endl;
	}
	return 0;
}