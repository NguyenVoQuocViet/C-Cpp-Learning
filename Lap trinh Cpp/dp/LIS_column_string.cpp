#include <bits/stdc++.h>
using namespace std;

// leetcode 960
int minDeletionSize(vector<string> &strs)
{
    int n = strs.size(), m = strs[0].size();
    vector<int> dp(m, 1);
    int max_val = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bool check = false;
            for (int k = 0; k < n; k++)
            {
                if (strs[k][i] < strs[k][j])
                {
                    check = true;
                    break;
                }
            }
            if (!check)
                dp[i] = max(dp[i], dp[j] + 1);
            max_val = max(max_val, dp[i]);
        }
    }
    return m - max_val;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (string &x : s)
    {
        cin >> x;
    }
    cout << minDeletionSize(s);
    return 0;
}