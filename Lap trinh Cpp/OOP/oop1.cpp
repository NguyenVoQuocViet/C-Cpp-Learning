#include <bits/stdc++.h>
using namespace std;

// Ki thuat lap trinh huong doi tuong - Object Oriented Programing

// Class: Customer
// Object: Nguyen Van A, instance

// Data field: Truong du lieu, thuoc tinh
// Method: Phuong thuc, hanh dong

// Class Account
// --username, password, email
// --checkLogin
// --resetPassword

class SinhVien{
private:
    string name, date, grade;
    double gpa;
    static string schoolName; // chung nhau schoolName cho tat ca doi tuong

public:
    // Constructor
    // SinhVien()
    // {
    //     cout << "Khoi tao" << endl;
    // }

    // SinhVien(string name, string date, string grade, double gpa)
    // {
    //     cout << "Khoi tao co tham so" << endl;
    //     this->name = name;
    //     this->date = date;
    //     this->grade = grade;
    //     this->gpa = gpa;
    // }

    // void nhapThongTin();
    // void xuatThongTin();
    string getName();
    void setName(string newName);
    string getSchoolName();
    void setSchoolName(string newSchoolName);
    double getGpa();

    // Overloading
    friend istream& operator >> (istream& in, SinhVien& x)
    {
        getline(in, x.name);
        getline(in, x.date);
        getline(in, x.grade);
        in >> x.gpa;
        in.ignore();
        return in;
    }

    friend ostream& operator << (ostream& out, SinhVien x)
    {
        out << x.name << endl;
        out << x.date << endl;
        out << x.grade << endl;
        out << fixed << setprecision(2) << x.gpa;
        return out;
    }

    bool operator < (const SinhVien& tmp)
    {
        return this->gpa < tmp.gpa;
    }

    bool operator > (const SinhVien& tmp)
    {
        return this->gpa > tmp.gpa;
    }

    double operator + (const SinhVien& tmp)
    {
        return this->gpa + tmp.gpa;
    }

    friend double operator - (const SinhVien& a, const SinhVien& b)
    {
        return a.gpa - b.gpa;
    }

    // ~SinhVien()
    // {
    //     cout << "Huy doi tuong" << endl;
    // }
};

// Implementation

string SinhVien::schoolName = "DHNT";

// void SinhVien::nhapThongTin()
// {
//     cin >> this->name >> this->date >> this->grade >> this->gpa;
// }

// void SinhVien::xuatThongTin()
// {
//     cout << this->name << endl << this->date << endl << this->grade << endl << this->gpa << endl;
// }

// Getter, setter

string SinhVien::getName()
{
    return this->name;
}

void SinhVien::setName(string newName)
{
    this->name = newName;
}

string SinhVien::getSchoolName()
{
    return schoolName;
}

void SinhVien::setSchoolName(string newSchoolName)
{
    this->schoolName = newSchoolName;
}

double SinhVien::getGpa()
{
    return this->gpa;
}

// Comparator
bool cmp(SinhVien& a, SinhVien& b)
{
    return a.getGpa() < b.getGpa();
}

int main()
{
    SinhVien a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];

    // if (x < y)
    //     cout << "X nho hon Y" << endl;
    // else 
    //     cout << "X lon hon Y" << endl;

    // cout << fixed << setprecision(2) << x + y << endl;
    // cout << fixed << setprecision(2) << x - y << endl;

    sort(a, a + 3);
    for (int i = 0 ; i < 3; i++)
        cout << a[i] << endl;
}