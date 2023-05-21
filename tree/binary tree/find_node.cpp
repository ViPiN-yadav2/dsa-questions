#include <bits/stdc++.h>

using namespace std;

template <typename T>

class treenode
{
public:
    T data;

    treenode *left;
    treenode *right;

    treenode(T data)
    {
        this->data = data;

        left = NULL;
        right = NULL;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

treenode<int> *takelevelinput()
{
    int data;
    cout << "enter data for root" << endl;
    cin >> data;
    treenode<int> *root = new treenode<int>(data);
    queue<treenode<int> *> q;
    q.push(root);
    while (q.empty() == 0)
    {
        treenode<int> *node = q.front();
        q.pop();
        cout << "enter data for left of " << node->data << endl;
        cin >> data;
        if (data != -1)
        {
            node->left = new treenode<int>(data);
            q.push(node->left);
        }
        cout << "enter data for right of node" << endl;
        cin >> data;
        if (data != -1)
        {
            node->right = new treenode<int>(data);
            q.push(node->right);
        }
    }
    return root;
}

bool isNodePresent(treenode<int> *root, int num)
{

    if (root->data == num)
    {
        return true;
    }
    if (root->left != NULL)
    {
        if (isNodePresent(root->left, num))
            return true;
    }
    if (root->right != NULL)
    {
        if (isNodePresent(root->right, num))
            return true;
    }

    return false;
}

int main()
{
    treenode<int> *root = takelevelinput();
    cout << isNodePresent(root, 7);
    return 0;
}
