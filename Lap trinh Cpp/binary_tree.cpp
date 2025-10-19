#include <iostream>
#include <vector>
#include <cctype>
#include <stack>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* makeNode(int x)
{
    node* newNode = new node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void push(node* &root, int x)
{
    if(root == NULL)
    {
        node* p = makeNode(x);
        root = p;
    }
    else
    {
        if(root->data > x)
            push(root->left, x);
        else if(root->data < x)
            push(root->right, x);
    }
}

void PreOrder(node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(node* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(node* root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

void stackPreOrder(node* root)
{
    if(root == NULL)
        return;
    stack<node*> st;
    node* curr = root;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            cout << curr->data << " ";
            if(curr->right != NULL)
                st.push(curr->right);
            curr = curr->left;
        }
        if(!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

int main()
{
    node* root = NULL;
    push(root, 3);
    push(root, 2);
    push(root, 4);
    push(root, 1);
    push(root, 5);
    push(root, 6);
    PreOrder(root);
    cout << endl;
    stackPreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);

    return 0;
}