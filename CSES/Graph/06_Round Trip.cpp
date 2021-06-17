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
vector<int> order;
 
bool dfs(int u, int p = -1)
{
    vis[u] = true;
    order.push_back(u);
    for (int to : adj[u])
    {
        if (to == p)
            continue;
        else if (vis[to])
        {
            order.push_back(to);
            return true;
        }
        else
        {
            if (dfs(to, u))
                return true;
        }
    }
    order.pop_back();
    return false;
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
 
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
    {
        vector<int> ans;
        int n = order.size();
        ans.push_back(order[n - 1]);
        int ind = n - 2;
        while (order[ind] != order[n - 1])
            ans.push_back(order[ind]), ind--;
        ans.push_back(order[ind]);
        cout << ans.size() << endl;
        for (int v : ans)
            cout << v << " ";
    }
    else cout << "IMPOSSIBLE";
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