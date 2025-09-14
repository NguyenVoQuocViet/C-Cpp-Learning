#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if(a[m] == x)
            return true;
        else
        {
            if(a[m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return false;
}

int main()
{
    int n = 10;
    int a[] = {1, 2, 4, 4, 4, 5, 8, 10, 11, 14};
    vector<int> v = {1, 2, 4, 4, 4, 5, 8, 10, 11, 14};
    cout << boolalpha << binarySearch(a, n, 5) << endl;
    auto it = lower_bound(a, a + n, 4); //tim phan tu dau tien >= x, neu khong co tra ve a + n, a.end()
    cout << *it << endl;
    auto it2 = upper_bound(v.begin(), v.end(), 1); // tim phan tu dau tien > x, neu khong co tra ve a + n, a.end()
    cout << *it2 << endl;
    return 0;
}