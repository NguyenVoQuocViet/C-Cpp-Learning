#include <iostream>
#include <cmath>
using namespace std;

//Dem so luong so nguyen to cung nhau voi n khong vuot qua n
// res = n*(1-1/p)(1-1/x)... , p, x la cac thua so nguyen to khac nhau
int main()
{
    int n;
    cin >> n;
    int res = n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            res = (res - res/i);
        }
    }
    if(n > 1)
        res = (res - res/n);
    cout << res << endl;
    return 0;
}