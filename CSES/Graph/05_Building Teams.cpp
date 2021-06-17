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
vector<int> team(MX, -1);
 
bool bfs(int u)
{
    queue<int> q;
    team[u] = 0;
    q.push(u);
 
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
 
        for (int to : adj[x])
        {
            if (team[to] == -1)
            {
                team[to] = 1 - team[x];
                q.push(to);
            }
            else
            {
                if (team[to] != 1 - team[x])
                    return false;
            }
        }
    }
    return true;
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
        if (team[i] == -1)
            if (!bfs(i))
            {
                cout << "IMPOSSIBLE";
                return;
            }
 
    }
    for (int i = 1; i <= n; i++)
        cout << team[i] + 1 << " ";
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