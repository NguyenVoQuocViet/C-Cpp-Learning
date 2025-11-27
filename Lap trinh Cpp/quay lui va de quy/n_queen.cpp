#include <bits/stdc++.h>
using namespace std;

int X[100], col[100], d1[100], d2[100], n;

void inkq()
{
    int res[100][100] = {0};
    for(int i = 0; i < n; i++)
    {
        res[i][X[i]] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void backtrack(int i)
{
    for(int j = 0; j < n; j++)
    {
        if(col[j] == 0 && d1[i - j + n - 1] == 0 && d2[i + j] == 0)
        {
            col[j] = d1[i - j + n - 1] = d2[i + j] = 1;
            X[i] = j;
            if(i == n - 1)
            {
                inkq();
            }
            else
                backtrack(i + 1);
            col[j] = d1[i - j + n - 1] = d2[i + j] = 0;
        }
    }
}

int main()
{
    cin >> n;
    backtrack(0);
}