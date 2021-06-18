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

const int MX = 2505, INF = 1e18;
vector<pair<int, int>> adj[MX];
vector<int> dist(MX, INF);
vector<int> relaxVertex(MX, -1);

void bell(int u, int n)
{
    dist[u] = 0;
    int change = -1;
    for (int times = 1; times <= n; times++)
    {
        change = -1;
        for (int i = 1; i <= n; i++)
        {
            for (auto to : adj[i])
            {
                int x = to.first, w = to.second;
                if (dist[x] > dist[i] + w)
                {
                    dist[x] = dist[i] + w;
                    relaxVertex[x] = i;
                    change = i;
                }
            }
        }
    }

    if (change == -1)
        cout << "NO" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            change = relaxVertex[change];
        vector<int> path;
        for (int i = change; ; i = relaxVertex[i])
        {
            path.push_back(i);
            if (i == change && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        for (int point : path)
            cout << point << " ";
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

    for (int i = 1; i <= n; i++)
        if (adj[i].size() > 0)
        {
            bell(i, n);
            break;
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
