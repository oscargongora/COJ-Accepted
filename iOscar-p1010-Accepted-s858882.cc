#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX_N 101

using namespace std;

struct edge
{
	int n, v, w, c;
} e;

int n, m;
vector<edge> graph;
vector<int> mst;
int parent[MAX_N];

void reset_parent()
{
	int i;
	for(i=1; i<=n; i++) 
	    parent[i] = i;
}

int find_parent(int n)
{
	if(n != parent[n])
	    return parent[n] = find_parent(parent[n]);
	return parent[n];    
}

int first_mst()
{
	int i, j, k, fmst = 0;
	reset_parent();
	for(i=0; i<m; i++)
	{
		j = find_parent(graph[i].v);
		k = find_parent(graph[i].w);
		if(j != k)
		{
			fmst += graph[i].c;
			parent[j] = k;
			mst.push_back(i);
		}
	}
	return fmst;
}

int second_mst(int edge)
{
	int i, j, k, l=1, smst = 0;
	reset_parent();
	for(i=0; i<m; i++)
	{
		j = find_parent(graph[i].v);
		k = find_parent(graph[i].w);
		if(j != k && i!=edge)
		{
			smst += graph[i].c;
			parent[j] = k;
			l ++;
		}
	}
	return l == n? smst: 1 << 30;
}

int main()
{
	int t, i, j, fmst, smst;
	scanf("%d", &t);
	while(t --)
	{
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++)
		{
			e.n = i;
			scanf("%d %d %d", &e.v, &e.w, &e.c);
			graph.push_back(e);
		}
		
		sort(graph.begin(), graph.end(), [](edge e1, edge e2){return e1.c < e2.c;});
		
		fmst = first_mst();
		
		smst = 1 << 30;
		for(i=0; i<n-1; i++)
		{
			j = second_mst(mst[i]);
			if(j < smst)
			    smst = j;
		}
		
		printf("%d %d\n", fmst, smst);
		graph.clear();
		mst.clear();
	}
	return 0;
}