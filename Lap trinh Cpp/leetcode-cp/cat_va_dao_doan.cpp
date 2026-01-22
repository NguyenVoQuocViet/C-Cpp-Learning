#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    long long ans = 0;
    ans = max(pre[0], ans);
    long long min_gap = 1e18;
    long long max_prej = pre[0];
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, pre[i]);
        if (i >= 2)
        {
            min_gap = min(min_gap, pre[i - 1] - max_prej);
            ans = max(ans, pre[i] - min_gap);
            max_prej = max(max_prej, pre[i - 1]);
        }
    }
    cout << ans;
    return 0;
}