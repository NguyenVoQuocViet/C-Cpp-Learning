#include <bits\stdc++.h>
using namespace std;

vector<int> X;

void backtrack(vector<int> a, int i)
{
    if(i == a.size())
    {
        cout << "[";
        for(int j = 0; j < X.size(); j++)
        {
            cout << X[j];
            if(j != X.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        return;
    }
    backtrack(a, i + 1);
    X.push_back(a[i]);
    backtrack(a, i + 1);
    X.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    backtrack(a, 0);
}