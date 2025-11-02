#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1000][1000], m, n;
int d[1000][1000];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int bfs(pair<int, int> s, pair<int, int> e)
{
    queue<pair<int, int>> q;
    q.push(s);     
    d[s.first][s.second] = 0;
    while(!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp == e)
        {
            return d[tmp.first][tmp.second];
        }
        for(int i = 0; i < 4; i++)
        {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1 && d[x][y] == -1)
            {
                q.push({x, y});
                d[x][y] = d[tmp.first][tmp.second] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    pair<int, int> s, e;
    cin >> s.first >> s.second >> e.first >> e.second;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    cout << bfs(s, e);
}