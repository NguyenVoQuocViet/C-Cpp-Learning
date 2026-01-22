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

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());
    int cnt = 0, _max = 0;
    for(int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;
        _max = max(_max, cnt);
    }
    cout << _max << endl;
    return 0;
}