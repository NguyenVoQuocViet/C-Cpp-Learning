#include <bits/stdc++.h>
using namespace std;
using ll = long long;  


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    bool dp[100][100] = {false};
    int max_len = 0, start = 0;
    for(int i = 0; i < s.size(); i++)
        dp[i][i] = true;
    for(int len = 2; len <= s.size(); len++)
    {
        for(int i = 0; i <= s.size() - len; i++)
        {
            int j = len + i - 1;
            if(len == 2 && s[i] == s[j])
            {
                dp[i][j] = true;
            }
            else if(s[i] == s[j] && dp[i + 1][j - 1])
                dp[i][j] = true;

            if(dp[i][j] && len > max_len)
            {
                max_len = len;
                start = i;
            }
        }
    }
    string res = s.substr(start, max_len);
    cout << res << endl;   
    cout << max_len;
}