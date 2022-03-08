#include<bits/stdc++.h>
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
vector<int> dist(MX, INT_MIN);
vector<int> par(MX, -1);

void dij(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[u] = 0;
    par[u] = -1;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second, w = p.first;
        if (dist[x] > w) continue;

        for (int to : adj[x])
        {
            if (dist[to] < w + 1)
            {
                dist[to] = w + 1;
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
    }

    dij(1);

    if (dist[n] == INT_MIN)
        cout << "IMPOSSIBLE";
    else
    {
        int i = n;
        vector<int> ans;
        while (i != -1)
        {
            ans.push_back(i);
            i = par[i];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int ver : ans)
            cout << ver << " ";
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
