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

int knapSack(int n, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &DP)
{
    for (int j = 0; j <= x; j++) DP[0][j] = 0;
    for (int i = 0; i <= n; i++) DP[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (price[i - 1] <= j)
                DP[i][j] = max(pages[i - 1] + DP[i - 1][j - price[i - 1]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    return DP[n][x];
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> DP;
    DP.resize(n + 1);
    for (int i = 0; i <= n; i++)
        DP[i].resize(x + 1, -1);

    cout << knapSack(n, x, price, pages, DP);
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