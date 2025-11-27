#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_len(ll n)
{
    if (n <= 1)
        return 1;
    return 2 * get_len(n / 2) + 1;
}

ll count(ll n, ll l, ll r)
{
    if (n <= 1)
        return n == 1 ? 1 : 0;
    ll left_len = get_len(n / 2);
    ll mid_pos = left_len + 1;
    ll right_len = left_len + 2;
    ll cnt = 0;

    if (left_len >= l)
    {
        ll left_end = min(r, left_len);
        cnt += count(n / 2, l, left_end);
    }

    if (l <= mid_pos && mid_pos <= r)
    {
        cnt += n % 2;
    }

    if (r >= right_len)
    {
        ll right_start = max(1LL, l - right_len + 1);
        ll right_end = r - right_len + 1;
        cnt += count(n / 2, right_start, right_end);
    }
    return cnt;
}

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    cout << count(n, l, r);
    return 0;
}