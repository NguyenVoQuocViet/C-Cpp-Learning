#include <bits/stdc++.h>
using namespace std;

int merge_count(vector<int> &a, int left, int right)
{
    if (left >= right)  return 0;
    int cnt = 0;
    int mid = (left + right) / 2;
    cnt += merge_count(a, left, mid);
    cnt += merge_count(a, mid + 1, right);
    vector<int> l(a.begin() + left, a.begin() + mid + 1);
    vector<int> r(a.begin() + mid + 1, a.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while(i < l.size() && j < r.size())
    {
        if (l[i] <= r[j])
        {
            a[k++] = l[i++];
        }
        else
        {
            cnt += (l.size() - i);
            a[k++] = r[j++];
        }
    }
    while (i < l.size()) a[k++] = l[i++];
    while (j < r.size()) a[k++] = r[j++];
    return cnt;
}   

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << merge_count(a, 0, n - 1);
    return 0;
}