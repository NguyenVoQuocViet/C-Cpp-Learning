#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10000, 0);
int cnt = 0;
// de quy co nho
// tinh so buoc de n thanh so 0, moi lan tru di mot so tu n
int solve(int n)
{
    cnt++;
    if (n == 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    int res = 1e9;
    int m = n;
    while (m)
    {
        int r = m % 10;
        if (r)
        {
            res = min(res, solve(n - r) + 1);
        }
        m /= 10;
    }
    dp[n] = res;
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl
         << cnt;
    return 0;
}