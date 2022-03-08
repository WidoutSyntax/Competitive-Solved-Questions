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
vector<int> parent(MX, -1);
int sv, ev;

bool dfs(int u, int par)
{
    vis[u] = true;
    parent[u] = par;
    for (int to : adj[u])
    {
        if (to == par)
            continue;
        else if (!vis[to])
        {
            if (dfs(to, u))
                return true;
        }
        else if (to != par)
        {
            sv = to;
            ev = u;
            return true;
        }
    }

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

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                vector<int> ans;
                ans.push_back(ev);
                int tv = ev;
                while (tv != sv)
                {
                    ans.push_back(parent[tv]);
                    tv = parent[tv];
                }
                ans.push_back(ev);
                cout << ans.size() << endl;
                for (int x : ans)
                    cout << x << " ";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE";
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