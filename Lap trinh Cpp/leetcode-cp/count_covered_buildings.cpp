#include <bits/stdc++.h>
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>> &buildings)
{
    vector<pair<int, int>> row(n + 1, {INT_MIN, INT_MAX});
    vector<pair<int, int>> col(n + 1, {INT_MIN, INT_MAX});
    for (auto &b : buildings)
    {
        int x = b[0];
        int y = b[1];
        col[x].first = max(col[x].first, y);
        col[x].second = min(col[x].second, y);
        row[y].first = max(row[y].first, x);
        row[y].second = min(row[y].second, x);
    }
    int res = 0;
    for (auto b : buildings)
    {
        int x = b[0];
        int y = b[1];
        if (x > row[y].second && x < row[y].first && y > col[x].second && y < col[x].first)
            res++;
    }
    return res;
}

int main()
{
    // leetcode 3531
    int n;
    cin >> n;
    vector<vector<int>> buildings;
    int x, y;
    while (cin >> x >> y)
    {
        buildings.push_back({x, y});
    }
    int res = countCoveredBuildings(n, buildings);
    cout << res;
    return 0;
}