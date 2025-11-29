#include <bits/stdc++.h>
using namespace std;

void generateTestFile(int indexFile, int n)
{
    string inputFileName = "input" + to_string(indexFile) + ".txt";
    string outputFileName = "output" + to_string(indexFile) + ".txt";
    ofstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "ERROR: NOT OPEN FILE" << indexFile << endl;
        return;
    }

    inputFile << n;
    int a2 = 1, a0 = 0, a1 = 0, a11 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 2 * (n - i); j++)
            outputFile << " ";
        for(int j = 1; j <= 2 * i - 1; j++)
        {
            if(a2)
            {
                outputFile << 2 << " ";
                a2 = 0; a0 = 1;
            }
            else if(a0)
            {
                outputFile << 0 << " ";
                a0 = 0; a1 = 1;
            }
            else if(a1)
            {
                outputFile << 1 << " ";
                a1 = 0; a11 = 1;
            }
            else
            {
                outputFile << 1 << " ";
                a11 = 0; a2 = 1;
            }
        }
        outputFile << endl;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 2 * i; j++)
            outputFile << " ";
        for(int j = 1; j <= 2 * (n - i) - 1; j++)
        {
            if(a2)
            {
                outputFile << 2 << " ";
                a2 = 0; a0 = 1;
            }
            else if(a0)
            {
                outputFile << 0 << " ";
                a0 = 0; a1 = 1;
            }
            else if(a1)
            {
                outputFile << 1 << " ";
                a1 = 0; a11 = 1;
            }
            else
            {
                outputFile << 1 << " ";
                a11 = 0; a2 = 1;
            }
        }
        if (i < n)
            outputFile << endl; 
    }
}

int main()
{
    set<int> num;
    srand(time(0));
    for (int i = 1; i <= 20; i++)
    {
        int n;
        do
        {
            n = 1 + (rand() % 20);
        } while (num.count(n));
        num.insert(n);
        generateTestFile(i, n);
    }
    return 0;
}