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

const int MX = 100005, MOD = 1e9 + 7;
vector<int> adj[MX];
vector<int> indeg(MX, 0);
vector<int> cnt(MX, 0);

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 2; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int to : adj[x])
        {
            indeg[to]--;
            if (indeg[to] == 0)
                q.push(to);
        }
    }

    cnt[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int to : adj[x])
        {
            indeg[to]--;
            cnt[to] = (cnt[to] + cnt[x]) % MOD;
            if (indeg[to] == 0)
                q.push(to);
        }
    }

    cout << cnt[n];
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
