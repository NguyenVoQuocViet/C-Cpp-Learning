#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <set>
#include <map>

using namespace std;
using ll = long long;
//tim khoang cach xa nhat co hieu dung bang k
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x = a[i] + k;
        int y = a[i] - k;
        if(mp.find(x) != mp.end())
        {
            cnt = max(cnt, i - mp[x]);
        }
        if(mp.find(y) != mp.end())
        {
            cnt = max(cnt, i - mp[y]);
        }
        if(mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = i;
        }
    }
    cout << (cnt == 0 ? -1 : cnt) << endl;
    return 0;
}