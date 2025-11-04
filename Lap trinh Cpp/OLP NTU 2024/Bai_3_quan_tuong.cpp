#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int d1[1001] = {0};
    int d2[1001] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            {
                if (i == 1 || j == 1)
                {
                    d1[i - j + n] = a[i][j];
                }
                else
                {
                    d1[i - j + n] += a[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {

            {
                if (i == 1 || j == n)
                {
                    d2[i + j - 1] = a[i][j];
                }
                else
                {
                    d2[i + j - 1] += a[i][j];
                }
            }
        }
    }

    int x1, y1, sum1 = 0, x2, y2, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (sum1 < (d1[i - j + n] + d2[i + j - 1] - a[i][j]))
                {
                    sum1 = (d1[i - j + n] + d2[i + j - 1] - a[i][j]);
                    x1 = i;
                    y1 = j;
                }
            }
            else
            {
                if (sum2 < (d1[i - j + n] + d2[i + j - 1] - a[i][j]))
                {
                    sum2 = (d1[i - j + n] + d2[i + j - 1] - a[i][j]);
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << sum1 + sum2 << endl
         << x1 << " " << y1 << " " << x2 << " " << y2;
}
