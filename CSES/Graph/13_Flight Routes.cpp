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

const int MX = 100005, INF = 1e17;
vector<pair<int, int>> adj[MX];
vector<vector<int>> dist;
vector<int> ans;

void dij(int u, int k, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int w = p.first, x = p.second;
        if (dist[x][k - 1] < w) continue;

        for (auto to : adj[x])
        {
            int x1 = to.first, w1 = to.second;
            if (dist[x1][k - 1] > w + w1)
            {
                dist[x1][k - 1] = w + w1;
                pq.push({dist[x1][k - 1], x1});
                sort(dist[x1].begin(), dist[x1].end());
            }
        }
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dist.resize(n + 1);
    for (int i = 0; i <= n; i++)
        dist[i].resize(k, INF);
    dij(1, k, n);

    for (int pathLength : dist[n])
        cout << pathLength << " ";
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
