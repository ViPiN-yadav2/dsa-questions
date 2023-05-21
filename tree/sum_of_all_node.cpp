#include <bits/stdc++.h>
// #include<tree.cpp>

using namespace std;

template <typename t>

class treenode
{
public:
    t data;
    vector<treenode<t> *> children;
    treenode(t data)
    {
        this->data = data;
    }
};

treenode<int> *takeinputlevelwish()
{
    cout << "enter data for root" << endl;
    int rootdata;
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    queue<treenode<int> *> q;
    q.push(root);
    while (q.empty() == 0)
    {
        treenode<int> *front = q.front();
        q.pop();
        cout << "enter no. of children of" << front->data << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childdata;
            cout << "enter the " << i << " th child" << front->data << endl;
            cin >> childdata;
            treenode<int> *node = new treenode<int>(childdata);
            front->children.push_back(node);
            q.push(node);
        }
    }
    return root;
}

void levelwishprint(treenode<int> *root)
{
    queue<treenode<int> *> q;
    q.push(root);
    cout << root->data << endl;
    while (q.empty() == 0)
    {
        treenode<int> *front = q.front();
        // cout << front->data << endl;
        q.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << endl;
            q.push(front->children[i]);
        }
    }
}

int sum(treenode<int> *root)
{
    treenode<int> *temp = root;
    int data = temp->data;
    for (int i = 0; i < temp->children.size(); i++)
    {
        data = data + sum(temp->children[i]);
    }
    return data;
}

int main()
{
    treenode<int> *root = takeinputlevelwish();
    cout << sum(root);
}