#include<bits/stdc++.h>
#define int long long
using namespace std;
 
void IOS()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
const int MX = 100005;
vector<int> adj[MX];
vector<int> dist(MX, INT_MAX);
vector<int> par(MX, -1);
 
void dij(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[u] = 0;
    par[u] = -1;
    pq.push({0, u});
 
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
 
        int x = p.second;
        for (int to : adj[x])
        {
            if (dist[to] > dist[x] + 1)
            {
                dist[to] = dist[x] + 1;
                par[to] = x;
                pq.push({dist[to], to});
            }
        }
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dij(1);
 
    if (dist[n] == INT_MAX)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n] + 1 << endl;
        vector<int> path;
        int ind = n;
        while (ind != -1)
        {
            path.push_back(ind);
            ind = par[ind];
        }
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
    }
    cout << endl;
}
 
int32_t main()
{
    IOS();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}