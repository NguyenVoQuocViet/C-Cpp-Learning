#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &nums, int k)
{
    long long prefix = 0, ans = LLONG_MIN;
    vector<long long> best(k, 1e18);
    best[k - 1] = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefix += 1LL * nums[i];
        ans = max(ans, 1LL * prefix - best[i % k]);
        best[i % k] = min(best[i % k], prefix);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSubarraySum(a, k);
    return 0;
}