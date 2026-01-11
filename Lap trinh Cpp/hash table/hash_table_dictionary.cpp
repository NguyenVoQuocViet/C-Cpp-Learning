#include <bits/stdc++.h>
#define M 26
using namespace std;

struct Dict
{
    string word;
    string mean;
};

struct Node
{
    Dict data;
    Node *next;
    Node(string x, string y)
    {
        data.word = x;
        data.mean = y;
        next = nullptr;
    }
};

void initHash(Node *heads[])
{
    for (int i = 0; i < M; i++)
        heads[i] = nullptr;
}

int hashFunc(char c)
{
    return c - 'a';
}

void insert(Node *heads[], string x, string y)
{
    int h = hashFunc(x[0]);
    Node *r = heads[h];
    Node *prev = nullptr;

    while (r != nullptr && r->data.word < x)
    {
        prev = r;
        r = r->next;
    }
    Node *node = new Node(x, y);
    if (prev == nullptr)
    {
        heads[h] = node;
        node->next = r;
    }
    else if (r == nullptr)
    {
        prev->next = node;
    }
    else
    {
        node->next = r;
        prev->next = node;
    }
}

void erase(Node *heads[], string x)
{
    int h = hashFunc(x[0]);
    Node *r = heads[h];
    Node *prev = nullptr;

    while (r != nullptr && r->data.word != x)
    {
        prev = r;
        r = r->next;
    }

    if (r == nullptr)
        return;
    if (prev == nullptr)
        heads[h] = r->next;
    else
        prev->next = r->next;
    delete r;
    cout << "Da xoa: " << x << endl;
}

void eraseAll(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        Node *cur = heads[i];
        while (cur != nullptr)
        {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        heads[i] = nullptr;
    }
}

Node *search(Node *heads[], string x)
{
    int h = hashFunc(x[0]);
    Node *head = heads[h];
    while (head != nullptr && head->data.word != x)
        head = head->next;
    return head;
}

void display(Node *heads[], char c)
{
    int h = hashFunc(c);
    Node *head = heads[h];
    cout << "==== " << c << " ====" << endl;
    if (head == nullptr)
    {
        cout << "Chua co tu trong tu dien!" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data.word << ": " << head->data.mean << endl;
        head = head->next;
    }
}

void displayAll(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        if (heads[i] != nullptr)
        {
            cout << "==== " << char(i + 'a') << " ====" << endl;
            Node *tmp = heads[i];
            while (tmp != nullptr)
            {
                cout << tmp->data.word << ": " << tmp->data.mean << endl;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    Node *heads[M];
    initHash(heads);
    while (true)
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << "1. Nhap vao mot tu" << endl;
        cout << "2. Xem tu dien theo ky tu dau" << endl;
        cout << "3. Xem toan bo tu dien" << endl;
        cout << "4. Tra tu dien" << endl;
        cout << "5. Xoa mot tu" << endl;
        cout << "6. Xoa toan bo tu dien" << endl;
        cout << "0. Thoat" << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "Nhap chuc nang: ";
        int tt;
        cin >> tt;
        cin.ignore();
        cout << endl;
        if (tt == 1)
        {
            cout << "Tu can nhap (tieng anh): ";
            string x;
            getline(cin, x);
            cout << "Nghia cua tu (tieng viet): ";
            string y;
            getline(cin, y);
            insert(heads, x, y);
        }
        else if (tt == 2)
        {
            cout << "Nhap ky tu can xem tu dien: ";
            char c;
            cin >> c;
            cout << endl;
            display(heads, c);
        }
        else if (tt == 3)
        {
            cout << endl;
            displayAll(heads);
        }
        else if (tt == 4)
        {
            cout << "Nhap tu can tra: ";
            string x;
            getline(cin, x);
            Node* find = search(heads, x);
            cout << endl;
            if (find == nullptr)
                cout << "Tu khong co trong tu dien!" << endl;
            else    
                cout << find->data.word << ": " << find->data.mean << endl;
        }
        else if (tt == 5)
        {
            cout << "Nhap tu can xoa: ";
            string x;
            getline(cin, x);
            erase(heads, x);
        }
        else if (tt == 6)
        {
            eraseAll(heads);
        }
        else
            break;
    }
    return 0;
}