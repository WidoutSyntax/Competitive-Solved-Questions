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

const int MX = 505;
vector<vector<int>> mat(MX, vector<int>(MX, LONG_MAX));

void flyod(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mat[i][k] == LONG_MAX || mat[k][j] == LONG_MAX)
                    continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mat[a][b] = min(mat[a][b], w);
        mat[b][a] = min(mat[a][b], w);
    }

    for (int i = 0; i <= n; i++) mat[i][i] = 0;
    flyod(n);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (mat[a][b] == LONG_MAX)
            cout << -1;
        else
            cout << mat[a][b];
        cout << endl;
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
