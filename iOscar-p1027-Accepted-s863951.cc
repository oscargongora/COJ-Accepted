#include <stdio.h>
#include <vector>
#include <queue>
#include <limits>
#define MAX_N 105

using namespace std;

int n, m;

struct edge
{
	int w, r, d;
	edge(int _w, int _r, int _d)
	{
		w = _w;
		r = _r;
		d = _d;
	}
};

struct state
{
	int n, r;
	state(int _n, int _r)
	{
		n = _n;
		r = _r;
	}
	bool operator <(const state &s) const
	{
	    return r < s.r;
	}
};

vector<edge> G[MAX_N];
int D[MAX_N], P[MAX_N], tmp;

int min(int a, int b){return a < b? a: b;}

int max(int a, int b){return a > b? a: b;}

void dijkstra1(int sn, int en)
{
	int i, j;
	for(i=1; i<=n; i++)
	{
		D[i] = 1 << 30;
	}
	D[sn] = 0;
	priority_queue<state> pq;
	pq.push(state(sn, 0));
	while(!pq.empty())
	{
		state s = pq.top();
		pq.pop();
		for(i=0; i<G[s.n].size(); i++)
		{
			j = max(D[s.n], G[s.n][i].r);
			if(D[G[s.n][i].w] > j)
			{
				D[G[s.n][i].w] = j;
				pq.push(state(G[s.n][i].w, D[G[s.n][i].w]));
			}
		}	
	}
} 

void dijkstra2(int sn, int en)
{
	int i;
	for(i=1; i<=n; i++)
	{
		D[i] = 1 << 30;
		P[i] = -1;
	}
	D[sn] = 0;
	priority_queue<state> pq;
	pq.push(state(sn, 0));
	while(!pq.empty())
	{
		state s = pq.top();
		pq.pop();
		for(i=0; i<G[s.n].size(); i++)
		{
			if(tmp >= G[s.n][i].r && D[G[s.n][i].w] > D[s.n] + G[s.n][i].d)
			{
				P[G[s.n][i].w] = s.n;
				D[G[s.n][i].w] = D[s.n] + G[s.n][i].d;
				pq.push(state(G[s.n][i].w,  D[s.n] + G[s.n][i].d));
			}
		}	
	}
} 

void print_path(int en)
{
	if(P[en] == -1)
	{
		printf("%d ", en);
		return;
	}
	print_path(P[en]);
	printf("%d ", en);
}

int main()
{
	int sn, en, i, v, w, rint, dint;
	float r, d;
	while(scanf("%d %d", &n, &m)==2)
	{
		for(i=1; i<=n; i++)
		{
			G[i].clear();
		}
		scanf("%d %d", &sn, &en);
		for(i=0; i<m; i++)
		{
			scanf("%d %d %f %f", &v, &w, &r, &d);
			rint = 10 * r;
			dint = 10 * d;
			G[v].push_back(edge(w, rint, dint));
			G[w].push_back(edge(v, rint, dint)); 
		}
		dijkstra1(sn, en);
		tmp = D[en];
		dijkstra2(sn, en);
		print_path(en);
		printf("\n%0.1f %0.1f\n", (D[en]/10.0), (tmp/10.0));
	}
	return 0;
}