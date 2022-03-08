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
vector<int> indeg(MX, 0);
set<int> s;
vector<int> order;

void topo()
{
    while (!s.empty())
    {
        int x = *(s.begin());
        s.erase(s.begin());
        order.push_back(x);

        for (int to : adj[x])
        {
            indeg[to]--;
            if (indeg[to] == 0)
                s.insert(to);
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
        indeg[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            s.insert(i);
    topo();

    if (order.size() != n)
        cout << "IMPOSSIBLE";
    else
    {
        for (int ver : order)
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
