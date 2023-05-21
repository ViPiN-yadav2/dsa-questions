#include <bits/stdc++.h>

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
pair<int, int> node;
void solve(treenode<int> *root)
{
    if (root == NULL)
        return;
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + root->children[i]->data;
    }
    // cout << "this is sum " << sum;

    if (node.second < sum)
    {
        node.first = root->data;
        node.second = sum;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        solve(root->children[i]);
    }
}

int main()
{
    node.first = 0;
    node.second = 0;
    treenode<int> *root = takeinputlevelwish();
    solve(root);
    cout << node.first;
}