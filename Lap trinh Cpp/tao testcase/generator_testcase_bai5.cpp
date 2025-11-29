#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm chuyển chuỗi sang chữ thường
string lowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Hàm sinh tên ngẫu nhiên
string generateRandomName() {
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Huynh", "Phan", "Vo"};
    vector<string> tenDem = {"Van", "Thi", "Minh", "Thu", "Hoang", "Duc"};
    vector<string> ten = {"Anh", "Binh", "Chien", "Dung", "Giang", "Hieu", "Khanh", "Lan"};

    string name = ho[rand() % ho.size()] + " ";
    // Thêm ngẫu nhiên 1 hoặc 2 từ tên đệm
    int numTenDem = 1 + (rand() % 2); 
    for (int i = 0; i < numTenDem; ++i) {
        name += tenDem[rand() % tenDem.size()] + " ";
    }
    name += ten[rand() % ten.size()];
    return name;
}

// Hàm sinh ngày sinh ngẫu nhiên (dạng dd/mm/yyyy)
string generateRandomDate() {
    int day = 1 + (rand() % 28); // Giả sử max 28 ngày để đơn giản
    int month = 1 + (rand() % 12);
    int year = 1990 + (rand() % 30); // Từ 1990 đến 2019

    stringstream ss;
    ss << (day < 10 ? "0" : "") << day << "/";
    ss << (month < 10 ? "0" : "") << month << "/";
    ss << year;
    return ss.str();
}

// Hàm chính xử lý logic và ghi ra file
void generateTestFile(int fileIndex, int numRecords) {
    string inputFileName = "input" + to_string(fileIndex) + ".txt";
    string outputFileName = "output" + to_string(fileIndex) + ".txt";

    ofstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "ERROR: Khong mo duoc file " << fileIndex << endl;
        return;
    }

    // Ghi số lượng bản ghi N vào file input
    inputFile << numRecords << endl;

    map<string, int> mp;
    
    // Vòng lặp sinh N bản ghi
    for (int i = 0; i < numRecords; ++i) {
        // Sinh dữ liệu ngẫu nhiên
        string name = generateRandomName();
        string date = generateRandomDate();
        string s = name + " " + date;

        // Ghi dữ liệu vào file input
        inputFile << s << endl;

        // --- Xử lý logic như code gốc của bạn để tạo Output ---
        stringstream ss(s);
        vector<string> x;
        string tmp;
        while (ss >> tmp) {
            x.push_back(tmp);
        }

        string email = lowerCase(x[x.size() - 2]); // Tên
        for (int j = 0; j < x.size() - 2; j++) {
            email += tolower(x[j][0]); // Ký tự đầu
        }
        
        mp[email]++;
        if (mp[email] > 1) {
            email += to_string(mp[email]);
        }
        email += "@ntu.edu.vn";

        string password = "";
        // DD
        password += to_string(stoi(x[x.size() - 1].substr(0, 2)));
        // MM
        password += to_string(stoi(x[x.size() - 1].substr(3, 2)));
        // YYYY
        password += to_string(stoi(x[x.size() - 1].substr(6, 4)));

        // Ghi kết quả vào file output
        outputFile << email << endl;
        outputFile << password << endl;
    }

    cout << "Da tao thanh cong: " << inputFileName << " va " << outputFileName 
         << " voi " << numRecords << " dong du lieu." << endl;
    
    inputFile.close();
    outputFile.close();
}

int main() {
    srand(time(0)); // Khởi tạo seed cho hàm random

    // 17 file, số lượng dòng ngẫu nhiên từ 1 đến 5000
    for (int i = 1; i <= 17; ++i) {
        // Sinh ngẫu nhiên số lượng dòng từ 1 đến 5000
        int numRecords = 1 + (rand() % 5000); 
        generateTestFile(i, numRecords);
    }
    
    return 0;
}