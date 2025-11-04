#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    bool dp[1001][1001] = {false};
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            if(j >= a[i])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
            else    
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][s];
}
