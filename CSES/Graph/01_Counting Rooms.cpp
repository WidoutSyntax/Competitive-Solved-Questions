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
 
int arrX[] = {1, -1, 0, 0};
int arrY[] = {0, 0, 1, -1};
 
void dfs(int x, int y, int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &vis)
{
    vis[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int dx = x + arrX[k], dy = y + arrY[k];
        if (dx < 0 || dx >= n || dy < 0 || dy >= m)
            continue;
        if (mat[dx][dy] && !vis[dx][dy])
            dfs(dx, dy, n, m, mat, vis);
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.') mat[i][j] = 1;
        }
 
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] && !vis[i][j])
            {
                dfs(i, j, n, m, mat, vis);
                rooms++;
            }
        }
    }
    cout << rooms;
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