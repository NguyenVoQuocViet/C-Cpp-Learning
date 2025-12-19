#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    heights.push_back(0);
    int n = heights.size();
    stack<int> st;
    int i = 0, res = 0;
    while (i < n)
    {
        if (st.empty() || heights[i] >= heights[st.top()])
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int tmp = st.top();
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                int area = (i - left - 1) * heights[tmp];
                res = max(res, area);
            }
            st.push(i);
        }
        i++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int &x : heights)
        cin >> x;
    int res = largestRectangleArea(heights);
    cout << res;
    return 0;
}