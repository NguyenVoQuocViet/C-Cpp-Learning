#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void makeRoot(TreeNode* root, int u, int v, char c)
{
    if (c == 'L')
        root->left = new TreeNode(v);
    else
        root->right = new TreeNode(v);
}

void insertNode(TreeNode* root, int u, int v, int c)
{
    if (root == nullptr)
        return;
    if (root->data == u)
        makeRoot(root, u, v, c);
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    TreeNode* root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == nullptr)
        {
            root = new TreeNode(u);
            makeRoot(root, u, v, c);
        }
        else
            insertNode(root, u, v, c);
    }
    inOrder(root);
}