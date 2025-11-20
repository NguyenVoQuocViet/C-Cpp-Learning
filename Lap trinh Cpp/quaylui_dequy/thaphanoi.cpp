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

void thapHaNoi(int n, char a, char b, char c)
{
    if(n == 1)
        cout << "Chuyen 1 dia tu " << a << " sang " << c << endl;
    else
    {
        thapHaNoi(n - 1, a, c, b);
        thapHaNoi(1, a, b, c);
        thapHaNoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    thapHaNoi(n, a, b, c);
    return 0;
}