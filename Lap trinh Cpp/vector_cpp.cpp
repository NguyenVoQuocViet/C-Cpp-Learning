#include <iostream>
#include <vector>
using namespace std;

//push_back
//size
//clear : xoa toan bo
//empty : check rong (true, fasle)
//insert : chen
//iterator : ++ -- += -=
int main()
{
    int n;
    cin >> n;
    //vector<int> v; khai bao vecto chua cap phat o nho
    //vector<int> v(n); //khai bao vecto cap phat n o nho
    //vector<int> v(n, 100); //khai bao vecto cap phat n o nho, moi o nho co gia tri = 100
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it; //begin(), end(), rbegin(), rend()
    v.insert(v.begin() + 3, 10);
    for(it = v.begin(); it != v.end(); it++) //v.begin() + x : tro den vi tri x
        cout << *it << " ";    
    cout << endl;
    v.clear();
    cout << v.empty() << endl;
    return 0;
}