#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10000, 0);

int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    int mod = 1e9 + 7, res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= i)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
                if (i == n && j == sum)
                {
                    res = dp[i - 1][j - i];
                }
            }
            else
                dp[i][j] = dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << "  ";
        cout << endl;
    }
    cout << res;
    return 0;
}