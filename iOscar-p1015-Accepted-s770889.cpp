#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 1001
#define oo 1<<30

using namespace std;

struct Arista
{
	int destino;
	int costo;
	Arista(int d, int c): destino(d), costo(c){
	};
	Arista():destino(0), costo(0){
	};
};

vector<Arista> G[MAXN];
vector<int> caminos;
vector<long long int> distancia;

struct Estado
{
	int nodo;
	int costo;
	Estado(int n, int c): nodo(n), costo(c){
	};
	Estado():nodo(0), costo(0){
	};
	bool operator <(const Estado &e) const
	{
		return costo > e.costo;
	}
}actual;

int c(int b)
{
	if(caminos[b] != -1)
		return caminos[b];
	int ca = 0;
	for(int i=0; i<G[b].size(); i++)
		if(distancia[G[b][i].destino] > distancia[b])
			ca += c(G[b][i].destino);
	return caminos[b] = ca;
	
}

int main()
{
	int n, m, i, a, b, d, j;
	while(scanf("%d", &n) && n)
	{
		for(i=1; i<=n; i++)
			G[i].clear();
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d %d %d", &a, &b, &d);
			G[a].push_back(Arista(b, d));
			G[b].push_back(Arista(a, d));
		}
		distancia = vector<long long int>(n+1, oo);
		distancia[2] = 0;
		priority_queue<Estado> pqueue;
		pqueue.push(Estado(2, 0));
		while(!pqueue.empty())
		{
			actual = pqueue.top();
			pqueue.pop();
			for(i=0; i<G[actual.nodo].size(); i++)
			{
				if(distancia[G[actual.nodo][i].destino] > actual.costo+G[actual.nodo][i].costo)
				{
					distancia[G[actual.nodo][i].destino] = actual.costo+G[actual.nodo][i].costo;
					pqueue.push(Estado(G[actual.nodo][i].destino, actual.costo+G[actual.nodo][i].costo));
				}
			}
		}
		caminos = vector<int>(n+1, -1);
		caminos[1] = 1;
		printf("%d\n",c(2));
	}
	return 0;
}
