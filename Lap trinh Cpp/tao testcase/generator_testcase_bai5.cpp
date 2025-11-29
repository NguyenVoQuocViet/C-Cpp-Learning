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

string lowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string generateRandomName() {
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Huynh", "Phan", "Vo"};
    vector<string> tenDem = {"Van", "Thi", "Minh", "Thu", "Hoang", "Duc"};
    vector<string> ten = {"Anh", "Binh", "Chien", "Dung", "Giang", "Hieu", "Khanh", "Lan"};

    string name = ho[rand() % ho.size()] + " ";
    int numTenDem = 1 + (rand() % 2); 
    for (int i = 0; i < numTenDem; ++i) {
        name += tenDem[rand() % tenDem.size()] + " ";
    }
    name += ten[rand() % ten.size()];
    return name;
}

string generateRandomDate() {
    int day = 1 + (rand() % 28);
    int month = 1 + (rand() % 12);
    int year = 1990 + (rand() % 30);

    stringstream ss;
    ss << (day < 10 ? "0" : "") << day << "/";
    ss << (month < 10 ? "0" : "") << month << "/";
    ss << year;
    return ss.str();
}

void generateTestFile(int fileIndex, int numRecords) {
    string inputFileName = "input" + to_string(fileIndex) + ".txt";
    string outputFileName = "output" + to_string(fileIndex) + ".txt";

    ofstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "ERROR: Khong mo duoc file " << fileIndex << endl;
        return;
    }

    inputFile << numRecords << endl;

    map<string, int> mp;
    
    for (int i = 0; i < numRecords; ++i) {
        string name = generateRandomName();
        string date = generateRandomDate();
        string s = name + " " + date;

        inputFile << s << endl;

        stringstream ss(s);
        vector<string> x;
        string tmp;
        while (ss >> tmp) {
            x.push_back(tmp);
        }

        string email = lowerCase(x[x.size() - 2]);
        for (int j = 0; j < x.size() - 2; j++) {
            email += tolower(x[j][0]);
        }
        
        mp[email]++;
        if (mp[email] > 1) {
            email += to_string(mp[email]);
        }
        email += "@ntu.edu.vn";

        string password = "";
        password += to_string(stoi(x[x.size() - 1].substr(0, 2)));
        password += to_string(stoi(x[x.size() - 1].substr(3, 2)));
        password += to_string(stoi(x[x.size() - 1].substr(6, 4)));

        outputFile << email << endl;
        outputFile << password << endl;
    }

    cout << "Da tao thanh cong: " << inputFileName << " va " << outputFileName 
         << " voi " << numRecords << " dong du lieu." << endl;
    
    inputFile.close();
    outputFile.close();
}

int main() {
    srand(time(0));

    for (int i = 1; i <= 17; ++i) {
        int numRecords = 1 + (rand() % 5000); 
        generateTestFile(i, numRecords);
    }
    
    return 0;
}