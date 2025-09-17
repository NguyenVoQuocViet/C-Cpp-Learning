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

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int, int>> v;
    for(int x : a)
    {
        if(mp[x])
        {
            v.push_back({x, mp[x]});
            mp[x] = 0;
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(pair<int, int> x : v)
    {
        for(int i = 1; i <= x.second; i++)
        {
            cout << x.first << " ";
        }
    }
    return 0;
}