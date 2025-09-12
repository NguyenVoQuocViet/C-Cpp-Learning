#include <iostream>
#include <vector>
using namespace std;

/* VECTOR
push_back
pop_back
size
clear : xoa toan bo
empty : check rong (true, fasle)
insert : chen
iterator : ++ -- += -=
*/

/* PAIR
.first
.second
make_pair(x, y)
*/
int main()
{
    /*
    vector<int> v; khai bao vecto chua cap phat o nho
    vector<int> v(n); khai bao vecto cap phat n o nho
    vector<int> v(n, 100); khai bao vecto cap phat n o nho, moi o nho co gia tri = 100
    */
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it; // begin(), end(), rbegin(), rend()
    v.insert(v.begin() + 3, 10);
    for (it = v.begin(); it != v.end(); it++) // v.begin() + x : tro den vi tri x
        cout << *it << " ";

    cout << endl;

    int m;
    cin >> m;
    vector<pair<int, int>> p(m);
    for (auto &a : p)
    {
        cin >> a.first >> a.second;
    }
    for (int i = 0; i < m; i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }
    pair<char, pair<int, int>> pr;
    pr.first = '@';
    pr.second.first = 1;
    pr.second.second = 2;
    cout << pr.first << " " << pr.second.first << " " << pr.second.second << endl;
    return 0;
}