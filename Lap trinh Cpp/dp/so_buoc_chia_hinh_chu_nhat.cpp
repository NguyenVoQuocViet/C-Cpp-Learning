#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, 0));
// so buoc it nhat chia hinh chu nhat thanh hinh vuong
int solve(int a, int b)
{
    if (a == b)
        return 0;
    if (dp[a][b] != 0)
        return dp[a][b];
    int res = 1e9;
    for (int i = b - 1; i >= 1; i--)
    {
        res = min(res, solve(a, i) + solve(a, b - i) + 1);
    }
    for (int i = a - 1; i >= 1; i--)
    {
        res = min(res, solve(i, b) + solve(a - i, b) + 1);
    }
    dp[a][b] = res;
    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}