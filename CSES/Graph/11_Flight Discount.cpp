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

const int MX = 100005, INF = 1e18;
vector<pair<int, int>> adj[MX];
vector<int> dist(MX, INF), disc(MX, INF);

void dij(int u)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    disc[u] = dist[u] = 0;
    pq.push({0, {u, 0}});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int x = p.second.first, cupon = p.second.second;

        if (cupon == 0)
            if (dist[x] < d) continue;
        if (cupon == 1)
            if (disc[x] < d) continue;

        for (auto to : adj[x])
        {
            int x1 = to.first, w1 = to.second;
            if (cupon == 0)
            {
                if (disc[x1] > d + w1 / 2)
                {
                    disc[x1] = d + w1 / 2;
                    pq.push({disc[x1], {x1, 1}});
                }

                if (dist[x1] > d + w1)
                {
                    dist[x1] = d + w1;
                    pq.push({dist[x1], {x1, 0}});
                }
            }
            else
            {
                if (disc[x1] > d + w1)
                {
                    disc[x1] = d + w1;
                    pq.push({disc[x1], {x1, 1}});
                }
            }

        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        mp[ {a, b}] = w;
    }

    dij(1);

    cout << disc[n];
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
