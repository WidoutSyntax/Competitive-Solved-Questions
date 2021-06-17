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
 
int arrX[] = {0, 0, -1, 1};
int arrY[] = { -1, 1, 0, 0};
int dir[] = {'L', 'R', 'U', 'D'};
 
bool bfs(int sx, int sy, int dx, int dy, int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &vis, string &path)
{
    vector<vector<char>> trace(n, vector<char>(m, '#'));
    queue<pair<int, int>> q;
    vis[sx][sy] = true;
    q.push({sx, sy});
 
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        if (x == dx && y == dy)
            break;
        for (int k = 0; k < 4; k++)
        {
            int newX = x + arrX[k], newY = y + arrY[k];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m)
                continue;
            if (mat[newX][newY] && !vis[newX][newY])
            {
                vis[newX][newY] = true;
                trace[newX][newY] = dir[k];
                q.push({newX, newY});
            }
        }
    }
 
    if (trace[dx][dy] == '#')
        return false;
 
    int i = dx, j = dy;
    string currPath = "";
    while (i != sx || j != sy)
    {
        char ch = trace[i][j];
        currPath.push_back(ch);
        if (ch == 'L') j++;
        else if (ch == 'R') j--;
        else if (ch == 'U') i++;
        else i--;
    }
    reverse(currPath.begin(), currPath.end());
    path = currPath;
    return true;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.') mat[i][j] = 1;
            if (ch == 'A') start_x = i, start_y = j, mat[i][j] = 1;
            if (ch == 'B') end_x = i, end_y = j, mat[i][j] = 1;
        }
 
    string path = "";
    if (bfs(start_x, start_y, end_x, end_y, n, m, mat, vis, path))
    {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path;
    }
    else cout << "NO";
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