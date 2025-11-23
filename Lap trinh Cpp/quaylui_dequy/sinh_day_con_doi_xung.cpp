#include <bits/stdc++.h>
using namespace std;

bool palin(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}

vector<vector<string>> res;
vector<string> X;

void backtrack(string s, int start)
{
    if (start >= s.size())
        res.push_back(X);
    else
    {
        for (int end = start; end < s.size(); end++)
        {
            if (palin(s.substr(start, end - start + 1)))
            {
                X.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                X.pop_back();
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    backtrack(s, 0);
    for (auto it : res)
    {
        for (auto it1 : it)
            cout << it1 << ' ';
        cout << endl;
    }
    return 0;
}