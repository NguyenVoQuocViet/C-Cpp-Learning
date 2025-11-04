#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cost = 1e9, visited[100], X[100], min_cost = 1e9, curr_cost = 0, a[100][100];
void backtrack(int i, int n)
{
    for (int j = 1; j < n; j++)
    {
        if (!visited[j])
        {
            X[i] = j;
            curr_cost += a[X[i - 1]][X[i]];
            visited[j] = 1;
            if (i == n - 1)
            {
                int total = curr_cost + a[X[n - 1]][X[0]];
                cost = min(total, cost);
            }
            else if ((n - i) * min_cost + curr_cost < cost)
                backtrack(i + 1, n);

            visited[j] = 0;
            curr_cost -= a[X[i - 1]][X[i]];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
                min_cost = min(min_cost, a[i][j]);
        }
    }

    X[0] = 0;
    visited[0] = 1;
    backtrack(1, n);
    cout << cost;
}