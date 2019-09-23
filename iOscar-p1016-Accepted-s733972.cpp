#include <stdio.h>
#include <queue>
#include <math.h>
#include <utility>
#define oo 1 << 29

using namespace std;

double distancia(double x, double y, double x1, double y1)
{
	return sqrt(pow(x1-x, 2) + pow(y1-y, 2));
}

struct Estado
{
	int nodo;
	double costo;
	Estado(int _nodo, double _costo):nodo(_nodo), costo(_costo){};
	bool operator<(const Estado &estado) const{
		return costo > estado.costo;
	}
};

int main()
{
	double G[100][100], x, y, dist=0;
	vector< pair<double, double> > freckles;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf", &x, &y);
		freckles.push_back(pair<double, double>(x, y));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G[i][j] = G[j][i] = distancia(freckles[i].first, freckles[i].second, freckles[j].first, freckles[j].second);
		}
	}

	vector<bool> visitado(n, false);
	vector<double> distancia(n, oo);
	priority_queue<Estado> estados;

	estados.push(Estado(0, 0));
	distancia[0] = 0;

	while (!estados.empty())
	{
		Estado actual = estados.top();
		estados.pop();
		
		visitado[actual.nodo] = true;

		for (i = 0; i < n; i++)
		{
			if (!visitado[i] && distancia[i] > G[actual.nodo][i])
			{
				estados.push(Estado(i, G[actual.nodo][i]));
				distancia[i] = G[actual.nodo][i];
			}
		}
	}
	
	for (i = 0; i < n; i++)
	{
		dist += distancia[i];
	}
	printf("%.2lf", dist);
	
	return 0;
}