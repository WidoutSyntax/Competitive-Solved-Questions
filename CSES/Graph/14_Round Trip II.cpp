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

const int MX = 1e5 + 5;
vector<int> adj[MX];
vector<bool> vis(MX, false), rec(MX, false);
vector<int> path;

bool isCycle(int u)
{
    if (!vis[u])
    {
        vis[u] = rec[u] = true;
        path.push_back(u);
        for (int to : adj[u])
        {
            if (!vis[to] && isCycle(to))
                return true;
            else if (rec[to])
            {
                path.push_back(to);
                return true;
            }
        }
        path.pop_back();
    }
    rec[u] = false;
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
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i))
            {
                vector<int> ans;
                int n = path.size();
                ans.push_back(path[n - 1]);
                for (int i = n - 2; i >= 0; i--)
                {
                    ans.push_back(path[i]);
                    if (path[i] == path[n - 1])
                        break;
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (int ver : ans)
                    cout << ver << " ";
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
