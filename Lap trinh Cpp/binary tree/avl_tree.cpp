#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    int h;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        h = 1;
        left = right = nullptr;
    }
};

int height(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    return root->h;
}

// xoay phai
TreeNode* rightRotate(TreeNode* root)
{
    TreeNode* rootLeft = root->left;
    TreeNode* T2 = rootLeft->right;
    // thuc hien xoay phai
    root->left = T2;
    rootLeft->right = root;
    // cap nhat chieu cao cay
    root->h = max(height(root->left), height(root->right)) + 1;
    rootLeft->h = max(height(rootLeft->left), height(rootLeft->right)) + 1;
    return rootLeft;
}

TreeNode* leftRotate(TreeNode* root)
{
    TreeNode* rootRight = root->right;
    TreeNode* T2 = rootRight->left;
    // thuc hien xoay trai
    root->right = T2;
    rootRight->left = root;
    // cap nhat chieu cao cay
    root->h = max(height(root->left), height(root->right)) + 1;
    rootRight->h = max(height(rootRight->left), height(rootRight->right)) + 1;
    return rootRight;
}
// tinh muc do can bang
int getBalance(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return height(root->left) - height(root->right);
}

TreeNode* insert(TreeNode* node, int key)
{
    if (node == nullptr)
        return new TreeNode(key);
    else if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    else
        return node;
    // cap nhat chieu cao cay
    node->h = max(height(node->left), height(node->right)) + 1;
    // tinh muc do can bang
    int balance = getBalance(node);
    // neu cay khong can bang
    // LL
    if (balance > 1 && key < node->left->val)
        return rightRotate(node);
    // LR
    if (balance > 1 && key > node->left->val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RR
    if (balance < -1 && key > node->right->val)
    {
        return leftRotate(node);
    }
    // RL
    if (balance < -1 && key < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    srand(time(NULL));
    TreeNode* root = nullptr;
    int n = rand() % 10;
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        root = insert(root, x);
    }
    preOrder(root);
    return 0;
}