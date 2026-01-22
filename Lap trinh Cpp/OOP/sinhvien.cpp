#include <bits/stdc++.h>
using namespace std;

class SinhVien{
private:
    string name, date;
    double s1, s2, s3, sumS;
public:
    SinhVien(string name, string date, double s1, double s2, double s3)
    {
        this->name = name;
        this->date = date;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->sumS = s1 + s2 + s3;
    }

    void xuatThongTin();
};

void SinhVien::xuatThongTin()
{
    cout << this->name << " " << this->date << " " << this->sumS << endl;
}

int main()
{
    string name, date;
    double s1, s2, s3, sumS;
    getline(cin, name);
    getline(cin, date);
    cin >> s1 >> s2 >> s3;
    SinhVien x(name, date, s1, s2, s3);
    x.xuatThongTin();
    return 0;
}