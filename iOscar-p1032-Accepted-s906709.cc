#include <bits/stdc++.h>
#define MAX_N 200005
#define LOG_MAX_N 20

using namespace std;

typedef vector<int> vi;

int n, idx;
int L[MAX_N];
int LCA[MAX_N][LOG_MAX_N];
int K[MAX_N];
int P[MAX_N];
int M[MAX_N];
int MN[MAX_N];
vector<vi> AdjList;
vector<vi> party;

void bfs(int r)
{
    int u, v, i, j, lg;
    queue<int> q;
    q.push(r);
    L[r] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i = 0; i < AdjList[u].size(); i ++)
        {
            v = AdjList[u][i];
            if(P[u] == v)
            {
                continue;
            }
            L[v] = L[u] + 1;
            if(M[K[v]] < L[v])
            {
                M[K[v]] = L[v];
                MN[K[v]] = v;
            }
            LCA[v][0] = u;
            q.push(v);
            lg = log2(L[v]);
            for(j = 1; j <= lg; j ++)
            {
                LCA[v][j] = LCA[LCA[v][j - 1]][j - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if(L[a] < L[b])
        swap(a, b);
    int i, lg = log2(L[a]);
    for(i = lg; i >= 0; i --)
    {
        if(L[a] - (1 << i) >= L[b])
        {
            a = LCA[a][i];
        }
    }
    if(a == b) return a;
    for(i = lg; i >= 0; i --)
    {
        if(L[a] >= (1 << i) && LCA[a][i] != LCA[b][i])
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return P[a];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, i, j, r, ran, tmp;
    cin >> n >> k;
    AdjList.assign(n + 1, vi());
    party.assign(k + 1, vi());
    for(i = 1; i <= n; i ++)
    {
        cin >> K[i] >> P[i];
        AdjList[i].push_back(P[i]);
        AdjList[P[i]].push_back(i);
        party[K[i]].push_back(i);
        if(P[i] == 0) r = i;
    }
    bfs(r);
    for(i = 1; i <= k; i ++)
    {
        ran = 0;
        for(j = 0; j < party[i].size(); j ++)
        {
            tmp = L[MN[i]] + L[party[i][j]] - 2 * L[lca(MN[i], party[i][j])];
            if(ran < tmp) ran = tmp;
        }
        cout << ran << "\n";
    }
    return 0;
}
