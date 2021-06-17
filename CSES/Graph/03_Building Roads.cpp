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
vector<bool> vis(MX, false);
 
void dfs(int u)
{
    vis[u] = true;
    for (int to : adj[u])
    {
        if (!vis[to])
            dfs(to);
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
 
    int conn = 0, prev = -1;
    vector<pair<int, int>> roads;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            conn++;
            if (conn == 1)
                prev = i;
            else
            {
                roads.push_back({prev, i});
                prev = i;
            }
        }
    }
    cout << conn - 1 << endl;
    for (auto p : roads)
        cout << p.first << " " << p.second << endl;
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