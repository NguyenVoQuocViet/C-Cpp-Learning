#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

pair<ll, ll> zero(ll n)
{
    ll two = 0, five = 0;
    while (n > 0 && n % 2 == 0)
    {
        two++;
        n /= 2;
    }
    while (n > 0 && n % 5 == 0)
    {
        five++;
        n /= 5;
    }
    return {two, five};
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        p.push_back(zero(x));
    }
    vector<vector<int>> dp(k + 1, vector<int>(3000, -1));

    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int two = p[i].first;
        int five = p[i].second;
        for (int j = k; j >= 1; j--)
        {
            for (int w = 0; w <= 2900; w++)
            {
                if (w - five >= 0 && dp[j - 1][w - five] != -1)
                    dp[j][w] = max(dp[j - 1][w - five] + two, dp[j][w]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i < 3000; i++)
    {
        res = max(res, min(i, dp[k][i]));
    }
    cout << res;
}