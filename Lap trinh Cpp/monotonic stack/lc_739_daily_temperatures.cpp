#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    stack<pair<int, int>> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push({temperatures[i], i});
            ans[i] = 0;
        }
        else
        {
            auto tmp = st.top();
            if (temperatures[i] < tmp.first)
            {
                ans[i] = tmp.second - i;
                st.push({temperatures[i], i});
            }
            else
            {
                st.pop();

                while (!st.empty())
                {
                    auto tmp1 = st.top();
                    if (temperatures[i] < tmp1.first)
                    {
                        ans[i] = tmp1.second - i;
                        st.push({temperatures[i], i});
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                if (st.empty())
                {
                    st.push({temperatures[i], i});
                    ans[i] = 0;
                    continue;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> temperatures;
    for (int &x : temperatures)
        cin >> x;
    vector<int> res = dailyTemperatures(temperatures);
    for (int x : res)
        cout << x << " ";
    return 0;
}