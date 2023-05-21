#include <bits/stdc++.h>

using namespace std;

class binaryTreeNode
{
public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
    binaryTreeNode *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    binaryTreeNode *insert()
    {
        cout << "enter data for root" << endl;
        int data;
        cin >> data;
        if (data == -1)
        {
            return NULL;
        }
        root = new binaryTreeNode(data);
        cout << "enter data";
        cin >> data;

        if (data < root->data)
        {
            root->left = insert();
        }
        if (data >= root->data)
        {
            root->right = insert();
        }
        return root;
    }

    void print(binaryTreeNode *root)
    {
        if (root == NULL)
            return;
        print(root->left);
        cout << root->data << endl;
        print(root->right);
    }
};

int main()
{
    BST b;
    binaryTreeNode *root = b.insert();
    b.print(root);

    return 0;
}