#include <iostream>
#include <vector>
#include <cctype>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* makeTreeNode(int x)
{
    TreeNode* newTreeNode = new TreeNode;
    newTreeNode->data = x;
    newTreeNode->left = newTreeNode->right = nullptr;
    return newTreeNode;
}

void insert(TreeNode* &root, int x)
{
    if(root == nullptr)
    {
        TreeNode* p = makeTreeNode(x);
        root = p;
    }
    else
    {
        if(root->data > x)
            insert(root->left, x);
        else if(root->data < x)
            insert(root->right, x);
    }
}

void PreOrder(TreeNode* root)
{
    if(root != nullptr)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(TreeNode* root)
{
    if(root != nullptr)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(TreeNode* root)
{
    if(root != nullptr)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

void stackPreOrder(TreeNode* root)
{
    if(root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr != nullptr || !st.empty())
    {
        while(curr != nullptr)
        {
            cout << curr->data << " ";
            if(curr->right != nullptr)
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

int search(TreeNode* root, int x)
{
    if (root == nullptr)
        return 0;
    else
    {
        if (root->data == x)
            return 1;
        else if (root->data > x)
            return search(root->left, x);
        else
            return search(root->right, x);
    }
}

void twoNodeSearch(TreeNode* root)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->left != nullptr && root->right != nullptr)
            cout << root->data << ' ';
        twoNodeSearch(root->left);
        twoNodeSearch(root->right);
    }
}

void oneNodeSearch(TreeNode* root)
{
    if (root == nullptr)
        return;
    else
    {
        if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
            cout << root->data << ' ';
        oneNodeSearch(root->left);
        oneNodeSearch(root->right);
    }
}

void leafSearch(TreeNode* root)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->left == nullptr && root->right == nullptr)
            cout << root->data << ' ';
        leafSearch(root->left);
        leafSearch(root->right);
    }
}

TreeNode* minValueTreeNode(TreeNode* root)
{
    TreeNode* curr = root;
    while (curr->left != nullptr)
        curr = curr->left;
    return curr;
}

void erase(TreeNode* &root, int x)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->data < x)
            erase(root->right, x);
        else if(root->data > x)
            erase(root->left, x);
        else
        {
            if (root->left == nullptr)
            {
                TreeNode* victim = root;
                root = root->right;
                delete victim;
            }
            else if (root->right == nullptr)
            {
                TreeNode* victim = root;
                root = root->left;
                delete victim;
            }
            else
            {
                TreeNode* temp = minValueTreeNode(root->right);
                root->data = temp->data;
                erase(root->right, temp->data);
            }
        }
    }
}

void deleteTree(TreeNode* &root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

int main()
{
    TreeNode* root = nullptr;
    while (true)
    {
        cout << "==================================" << endl;
        cout << "1. Tao cay nhi phan tim kiem" << endl;
        cout << "2. Them node" << endl;
        cout << "3. PreOrder" << endl;
        cout << "4. InOrder" << endl;
        cout << "5. PostOrder" << endl;
        cout << "6. Tim kiem" << endl;
        cout << "7. Liet ke cac node co 1 cay con" << endl;
        cout << "8. Liet ke cac node co 2 cay con" << endl;
        cout << "9. Liet ke cac node la" << endl;
        cout << "10. Xoa node" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "==================================" << endl;
        int t;
        cin >> t;
        if (t == 1)
        {
            cout << "nhap so phan tu:" << endl;
            int n;
            cin >> n;
            cout << "nhap gia tri cac phan tu: " << endl;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                insert(root, x);
            }
        }
        else if (t == 2)
        {
            cout << "nhap gia tri can them:" << endl;
            int x;
            cin >> x;
            insert(root, x);
        }
        else if (t == 3)
            PreOrder(root);
        else if (t == 4)
            InOrder(root);
        else if (t == 5)
            PostOrder(root);
        else if (t == 6)
        {
            cout << "nhap gia tri can tim kiem: " << endl;
            int x;
            cin >> x;
            if (search(root, x))
                cout << ("FOUND");
            else
                cout << ("NOT FOUND");
        }
        else if (t == 7)
            oneNodeSearch(root);
        else if (t == 8)
            twoNodeSearch(root);
        else if (t == 9)
            leafSearch(root);
        else if (t == 10)
        {
            cout << "nhap gia tri can xoa: ";
            int x;
            cin >> x;
            erase(root, x);
        }
        else 
        {
            deleteTree(root);
            break;
        }
        cout << endl;
    }
    return 0;
}