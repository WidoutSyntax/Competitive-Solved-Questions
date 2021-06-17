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
vector<pair<int, int>> adj[MX];
vector<int> dist(MX, LONG_MAX);
 
void dij(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[u] = 0;
    pq.push({0, u});
 
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int x = p.second;
        if (dist[x] < p.first)
            continue;
        for (pair<int, int> to : adj[x])
        {
            int x1 = to.first, w1 = to.second;
            if (dist[x1] > dist[x] + w1)
            {
                dist[x1] = dist[x] + w1;
                pq.push({dist[x1], x1});
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
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
 
    dij(1);
 
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
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