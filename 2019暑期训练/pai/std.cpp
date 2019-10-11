#include <bits/stdc++.h>
using namespace std;

const int N = 2505, M = 5005;
const long long INF = 1E18 + 7;

int n, m, p, u[M], v[M], w[M];
bool vis[2][N];
long long dst[N];
vector<int> adj[2][N];

void DFS(int u, bool *vis, vector<int> *adj)
{
    vis[u] = true;
    for (int &v : adj[u])
        if (!vis[v])
            DFS(v, vis, adj);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> p;
    fill(dst + 2, dst + n + 1, INF);
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        w[i] = p - w[i];
        adj[0][u[i]].push_back(v[i]);
        adj[1][v[i]].push_back(u[i]);
    }
    DFS(1, vis[0], adj[0]);
    DFS(n, vis[1], adj[1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dst[v[j]] = min(dst[v[j]], dst[u[j]] + w[j]);
    for (int i = 1; i <= m; i++)
        if (dst[u[i]] + w[i] < dst[v[i]] && vis[0][v[i]] && vis[1][v[i]])
            return cout << -1, 0;
    cout << -min(dst[n], 0LL);
}

