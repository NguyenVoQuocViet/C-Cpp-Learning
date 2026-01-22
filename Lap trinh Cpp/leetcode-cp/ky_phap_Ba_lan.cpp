#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <cctype>

using namespace std;
using ll = long long;

bool optor(string c)
{
    return c == "+" || c == "-" || c == "*" || c == "/";
}

int main()
{
    int stk[100];
    int top = -1;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string tmp;
    while(ss >> tmp)
    {
        if(optor(tmp))
        {
            int tmp1 = stk[top--];
            int tmp2 = stk[top--];
            int kq;
            if(tmp == "+")
                kq = tmp1 + tmp2;
            else if(tmp == "-")
                kq = tmp2 - tmp1;
            else if(tmp == "*")
                kq = tmp2 * tmp1;
            else if(tmp == "/")
                kq = tmp2 / tmp1;
            stk[++top] = kq;
        }
        else
        {
            
            top++;
            stk[top] = stoi(tmp);
        }
    }    
    cout << stk[top];
    return 0;
}