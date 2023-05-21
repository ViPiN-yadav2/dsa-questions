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

treenode<int> *takeinput()
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    treenode<int> *node = new treenode<int>(data);
    node->left = takeinput();
    node->right = takeinput();
    return node;
}

void print(treenode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
        cout << "L" << root->left->data << endl;
    if (root->right != NULL)
        cout << "R" << root->right->data << endl;
    cout << root->data << " " << endl;
    print(root->left);
    print(root->right);
}

void printlevelwish(treenode<int> *root)
{
    if (root == NULL)
        return;
    queue<treenode<int> *> pending;
    pending.push(root);
    while (pending.size() != 0)
    {
        treenode<int> *temp = pending.front();
        pending.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            pending.push(temp->left);
        if (temp->right != NULL)
            pending.push(temp->right);
    }
}

int no_of_node(treenode<int> *root, int cnt = 1)
{
    if (root == NULL)
        return cnt;
    if (root->left != NULL)
    {
        cnt = no_of_node(root->left, cnt + 1);
    }

    if (root->right != NULL)
    {
        cnt = no_of_node(root->right, cnt + 1);
    }
    return cnt;
}

int main()
{
    // treenode<int> *root = new treenode<int>(5);
    // treenode<int> *node1 = new treenode<int>(6);
    // treenode<int> *node2 = new treenode<int>(7);
    // root->left = node1;
    // root->right = node2;
    treenode<int> *root = takelevelinput();
    printlevelwish(root);
    cout << no_of_node(root);
    return 0;
}