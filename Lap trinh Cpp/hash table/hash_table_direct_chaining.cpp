#include <bits/stdc++.h>
#define M 11
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void initHash(Node *heads[])
{
    for (int i = 0; i < M; i++)
        heads[i] = nullptr;
}

int hashFunc(int val)
{
    return val % M;
}

void insert(Node *heads[], int val)
{
    int h = hashFunc(val);
    Node *r = heads[h];
    Node *prev = nullptr;
    while (r != nullptr && r->data < val)
    {
        prev = r;
        r = r->next;
    }

    Node *node = new Node(val);
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

Node *search(Node *heads[], int val)
{
    int h = hashFunc(val);
    Node *r = heads[h];
    while (r != nullptr && r->data != val)
        r = r->next;
    return r;
}

void erase(Node *heads[], int val)
{
    int h = hashFunc(val);
    Node *r = heads[h];
    Node *prev = nullptr;

    while (r && r->data != val)
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
    cout << "DELETE: " << val << endl;
    
}

void display(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        if (heads[i] != nullptr)
        {
            cout << "====" << "BUCKET " << i << "====" << endl;
            Node *tmp = heads[i];
            while (tmp != nullptr)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
}

void clearHash(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        Node *curr = heads[i];
        while (curr != nullptr)
        {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        heads[i] = nullptr;
    }
}

int main()
{
    srand(time(nullptr));
    Node *heads[M];
    initHash(heads);
    int n = rand() % 10 + 3;
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 30;
        insert(heads, x);
    }
    display(heads);
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        int x = rand() % 30;
        if (search(heads, x) != nullptr)
            cout << x << " FOUND" << endl;
        else
            cout << x << " NOT FOUND" << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        int x = rand() % 30;
        erase(heads, x);
    }
    display(heads);
    clearHash(heads);
    return 0;
}