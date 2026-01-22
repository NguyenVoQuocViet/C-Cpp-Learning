#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> a)
{
    int n = a.size();
    int ones = count(a.begin(), a.end(), 1);
    if (ones > 1)
        return n - ones;
    int g = 0;
    int min_len = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        g = 0;
        for (int j = i + 1; j < n; j++)
        {
            g = gcd(g, a[j]);
            if (g == 1)
            {
                min_len = min(j - i, min_len);
                break;
            }
        }
    }
    if (min_len == INT_MAX)
        return -1;
    return min_len + n - 2;
}

int main()
{
    // leetcode 2654
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << minOperations(a);
    return 0;
}