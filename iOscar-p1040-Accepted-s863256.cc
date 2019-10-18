#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <queue>
#define MAX_N 1000001

using namespace std;

vector<int> graph[MAX_N];
int indegree[MAX_N];
stringstream ss;

int topo_sort(int n) {
	int i, j, node, p, tmp;
    queue<int> q;
     
    for(i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    p = 0;
    while(!q.empty()) {
        node = q.front(); 
		q.pop();
		p ++;
        ss << node << "\n";
        for(j = 0; j < graph[node].size(); j++) {
            tmp = graph[node][j];
            indegree[tmp]--;
            if(indegree[tmp] == 0) { 
                q.push(tmp);
            }
        }
    }
    
    return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m, a, b, i, j;
	bool f;
	while(cin >> n >> m)
	{
		if(!n) break;
		
		for(i=0; i<=n; i++)
		{
			graph[i].clear();
			indegree[i] = 0;
		}  
		    	  
		for(i=0; i<m; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b] ++;
		}
		
		j = topo_sort(n);
		if(j == n)
			cout << ss.str();
		else
			cout << "IMPOSSIBLE\n";
		ss.str("");	
	}
	return 0;
}