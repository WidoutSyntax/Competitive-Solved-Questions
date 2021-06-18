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

const int MX = 2505;
const int INF = 1e17;
const int NINF = (-1) * INF;
vector<pair<int, int>> adj[MX];
vector<int> dist(MX, INF);

void bell(int u, int n)
{
    dist[u] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] == INF) continue;
            for (pair<int, int> to : adj[j])
            {
                int x = to.first, w = to.second;
                if (dist[x] > dist[j] + w)
                {
                    dist[x] = dist[j] + w;
                    dist[x] = max(dist[x], NINF);
                }
            }
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] == INF) continue;
            for (pair<int, int> to : adj[j])
            {
                int x = to.first, w = to.second;
                if (dist[x] > dist[j] + w)
                    dist[x] = NINF;

            }
        }
    }

    if (dist[n] == NINF) cout << -1;
    else cout << (-1) * dist[n];
    cout << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w * (-1)});
    }

    bell(1, n);
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
