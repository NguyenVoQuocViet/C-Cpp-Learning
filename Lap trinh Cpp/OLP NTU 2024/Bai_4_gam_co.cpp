#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
    int n, m;
    cin >> n >> m;
    int a[31][31];
    int s1, s2, e1, e2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if(x == '*')
                a[i][j] = 0;
            else if(x == 'B')
            {
                a[i][j] = 1;
                s1 = i; s2 = j;
            }
            else if(x == 'C')
            {
                a[i][j] = 1;
                e1 = i; e2 = j;
            }
            else
                a[i][j] = 1;
        }
    }
    int d[100][100] = {0};
    d[s1][s2] = 1;
    queue<pair<int, int>> q;
    q.push({s1, s2});
    while(!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.first == e1 && tmp.second == e2)
        {
            cout << d[tmp.first][tmp.second] - 1;
            return 0;
        }
        for(int i = 0; i < 4; i++)
        {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] && d[x][y] == 0)
            {
                q.push({x, y});
                d[x][y] = d[tmp.first][tmp.second] + 1;
            }
        }
    }
}
