#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    vector<int> res(prices.size());
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int check = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] <= prices[i])
            {
                res[i] = prices[i] - prices[j];
                check = 1;
                break;
            }
        }
        if (!check)
            res[i] = prices[i];
    }
    res[prices.size() - 1] = prices[prices.size() - 1];
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int &x : prices)
        cin >> x;
    vector<int> res = finalPrices(prices);
    for (int x : res)
        cout << x << " ";
    return 0;
}